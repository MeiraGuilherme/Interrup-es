#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

// Definição dos pinos
#define BUTTON_A 5
#define BUTTON_B 6
#define LED_RED 11
#define LED_GREEN 12
#define LED_BLUE 13
#define LED_MATRIX 7

// Variáveis globais
volatile int number_displayed = 0;

// Função para piscar o LED vermelho 5x por segundo
bool blink_red_led(struct repeating_timer *t) {
    static bool state = false;
    gpio_put(LED_RED, state);
    state = !state;
    return true;
}

// Função de interrupção para o botão A (incrementar número)
void button_a_irq_handler(uint gpio, uint32_t events) {
    number_displayed = (number_displayed + 1) % 10;
    printf("Número: %d\n", number_displayed);
}

// Função de interrupção para o botão B (decrementar número)
void button_b_irq_handler(uint gpio, uint32_t events) {
    number_displayed = (number_displayed - 1 + 10) % 10;
    printf("Número: %d\n", number_displayed);
}

int main() {
    stdio_init_all();
    
    // Configuração dos LEDs
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    
    // Configuração dos botões
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);
    
    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B);

    // Configuração das interrupções
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_FALLING, true, &button_a_irq_handler);
    gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_FALLING, true, &button_b_irq_handler);
    
    // Timer para piscar o LED vermelho
    struct repeating_timer timer;
    add_repeating_timer_ms(100, blink_red_led, NULL, &timer);

    while (1) {
        tight_loop_contents();
    }

    return 0;
}
