#include <Adafruit_NeoPixel.h> // Biblioteca dos LEDs

#pragma once

class Led {
  private:
    int _pin;
    int _numled;
    int _numcores;
    int _tempo;
    int _brilhoMax = 50;
    Adafruit_NeoPixel pixels;
    uint32_t cores[5];
    int tempoantigo = 0;
    bool ledstat = 0;
    int parametro_pisca = 1;

  public:
    Led(int pin, int numled, int numcores, int time);
    int pin();
    void init();
    void red();
    void green();
    void blue();
    void white();
    void black();
    void blinks(int time);

};