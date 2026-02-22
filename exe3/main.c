#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_VERM = 4;
const int BOTAO_VERM = 28;
const int LED_VERDE = 6;
const int BOTAO_VERDE = 26;


int main() {
  stdio_init_all();
  int verde = 0;
  int vermelho = 0;

  // Configuracao dos pinos
  gpio_init(BOTAO_VERM);
  gpio_set_dir(BOTAO_VERM, GPIO_IN);
  gpio_pull_up(BOTAO_VERM);

  gpio_init(BOTAO_VERDE);
  gpio_set_dir(BOTAO_VERDE, GPIO_IN);
  gpio_pull_up(BOTAO_VERDE);
  
  gpio_init(LED_VERDE);
  gpio_set_dir(LED_VERDE, GPIO_OUT);

  gpio_init(LED_VERM);
  gpio_set_dir(LED_VERM, GPIO_OUT);

  while (true) {
    if (!gpio_get(BOTAO_VERDE)) {
      verde = !verde;
      while (!gpio_get(BOTAO_VERDE)) {};
      gpio_put(LED_VERDE, verde);
    }
    if (!gpio_get(BOTAO_VERM)) {
      vermelho = !vermelho;
      while (!gpio_get(BOTAO_VERM)) {};
      gpio_put(LED_VERM, vermelho);
    }

  }
}
