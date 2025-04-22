#ifndef DISPLAY_H
#define DISPLAY_H

#include "Config.h"

static uint8_t minutos_anteriores = 0, segundos_anteriores = 0;

// Funciones para controlar displays
void mostrarNumero(uint8_t num, uint8_t digitPosition, CRGB* display);
void mostrarTiempo(uint8_t minutos, uint8_t segundos, CRGB* display);
void mostrarPuntaje(uint16_t puntaje, CRGB* display, uint16_t numLeds);
void mostrarContador(uint8_t valor, CRGB* display, uint16_t numLeds);
void actualizarDisplay();

#endif  // DISPLAY_H