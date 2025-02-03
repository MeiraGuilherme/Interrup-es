# Projeto: Interrupções no Raspberry Pi Pico

# Descrição

Este projeto implementa um sistema utilizando o microcontrolador RP2040 na placa BitDogLab. Ele faz uso de interrupções, debouncing e controle de LEDs WS2812 e LED RGB. O código é escrito em C e desenvolvido no VSCode, com testes realizados no Wokwi.

# Funcionalidades

O LED vermelho (GPIO 11) pisca 5 vezes por segundo.

O botão A (GPIO 5) incrementa um número exibido na matriz de LEDs WS2812.

O botão B (GPIO 6) decrementa esse número.

Exibição dos números 0 a 9 na matriz 5x5 de LEDs (GPIO 7).

Uso de interrupções (IRQ) para capturar eventos dos botões.

Implementação de debouncing via software.

# Requisitos

Hardware:

Placa BitDogLab com RP2040

Matriz 5x5 WS2812 conectada à GPIO 7

LED RGB conectado às GPIOs 11, 12 e 13

Botões A e B conectados às GPIOs 5 e 6

# Software:

VSCode

SDK do RP2040

CMake e Make

Wokwi (para simulação)

# Autor:
Guilherme (2025)
