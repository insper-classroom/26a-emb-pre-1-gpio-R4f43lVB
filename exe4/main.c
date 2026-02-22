#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_VERM = 5;
const int LED_ROXO = 8;
const int LED_AZUL = 11;
const int LED_AMAR = 15;
const int BOTAO = 28;

int main() {
  stdio_init_all();
  
  gpio_init(BOTAO);
  gpio_set_dir(BOTAO, GPIO_IN);
  gpio_pull_up(BOTAO);

  gpio_init(LED_AMAR);
  gpio_set_dir(LED_AMAR, GPIO_OUT);

  gpio_init(LED_AZUL);
  gpio_set_dir(LED_AZUL, GPIO_OUT);

  gpio_init(LED_ROXO);
  gpio_set_dir(LED_ROXO, GPIO_OUT);

  gpio_init(LED_VERM);
  gpio_set_dir(LED_VERM, GPIO_OUT);

  int leds[4] = {LED_VERM, LED_ROXO, LED_AZUL, LED_AMAR};

  while (true) {
    if (!gpio_get(BOTAO)) {
      for (int i=0;i<4;i++) {
        gpio_put(leds[i], 1);
        sleep_ms(300);
        gpio_put(leds[i], 0);
        sleep_ms(300);
      }
      while (!gpio_get(BOTAO)) {};
    }
  }
}
