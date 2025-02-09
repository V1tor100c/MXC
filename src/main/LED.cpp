#include "LED.h"

#define RED    pixels.Color(Led._brilhoMax, 0, 0)     // vermelho
#define GREEN  pixels.Color(0, Led._brilhoMax, 0)     // verde
#define BLUE   pixels.Color(0, 0, Led._brilhoMax)     // azul
#define WHITE  pixels.Color(Led._brilhoMax, Led._brilhoMax, Led._brilhoMax) // branco
#define BLACK  pixels.Color(0, 0, 0)       // preto

Led::Led(int pin, int numled, int numcores, int time) 
  : _pin(pin), _numled(numled), _numcores(numcores), _tempo(time), pixels(numled, pin, NEO_GRB + NEO_KHZ800) {
  // Inicialização da array cores
  cores[0] = pixels.Color(_brilhoMax, 0, 0);     // RED
  cores[1] = pixels.Color(0, _brilhoMax, 0);     // GREEN
  cores[2] = pixels.Color(0, 0, _brilhoMax);     // BLUE
  cores[3] = pixels.Color(_brilhoMax, _brilhoMax, _brilhoMax); // WHITE
  cores[4] = pixels.Color(0, 0, 0);       // BLACK
}

int Led::pin() { 
  return _pin;
}

void Led::init() {
  pixels.begin();
}

void Led::red() {
  for (int i = 0; i < _numled; i++) {
    pixels.setPixelColor(i, cores[0]);
  }
  pixels.show();
}

void Led::green() {
  for (int i = 0; i < _numled; i++) {
    pixels.setPixelColor(i, cores[1]);
  }
  pixels.show();
}

void Led::blue() {
  for (int i = 0; i < _numled; i++) {
    pixels.setPixelColor(i, cores[2]);
  }
  pixels.show();
}

void Led::white() {
  for (int i = 0; i < _numled; i++) {
    pixels.setPixelColor(i, cores[3]);
  }
  pixels.show();
}

void Led::black() {
  for (int i = 0; i < _numled; i++) {
    pixels.setPixelColor(i, cores[4]);
  }
  pixels.show();
}

void Led::blinks(int _tempo) {
  unsigned long tempoatual = millis();

  if (parametro_pisca == -1){
      ledstat = 0;
      for (int i = 0; i < _numled; i++) {
        pixels.setPixelColor(i, cores[4]);
      } 
      pixels.show(); // Esta linha é essencial para atualizar os LEDs com as novas cores

  }
  if (parametro_pisca == 1){
    if (tempoatual - tempoantigo >= _tempo){
      tempoantigo = tempoatual;
      if (ledstat == 0){
        ledstat = 1;
        for (int i = 0; i < _numled; i++) {
          pixels.setPixelColor(i, cores[2]);
        } 
        pixels.show(); // Esta linha é essencial para atualizar os LEDs com as novas cores
      }
    }
    else {
      parametro_pisca = 1;
      ledstat = 0;
      for (int i = 0; i < _numled; i++) {
        pixels.setPixelColor(i, cores[4]);
      } 
      pixels.show(); // Esta linha é essencial para atualizar os LEDs com as novas cores
    }
  }
}
