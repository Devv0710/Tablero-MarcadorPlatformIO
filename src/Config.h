#ifndef CONFIG_H
#define CONFIG_H

#include <FastLED.h>

// Configuración de pines
#define PIN_CRONOMETRO 5
#define PIN_PUNTAJE_LOCAL 13
#define PIN_PUNTAJE_VISITANTE 14
#define PIN_FALTAS_LOCAL 18
#define PIN_FALTAS_VISITANTE 19
#define PIN_PERIODO 21

// Configuración de LEDs
#define NUM_DIGITOS_CRONOMETRO 4  // 2 dígitos para minutos y 2 para segundos
#define NUM_DIGITOS_PUNTAJE 3 // 3 dígitos para puntaje
#define NUM_DIGITOS_CONTADORES 1  // 1 dígito para faltas y periodo

#define LEDS_POR_DIGITO 35  // LEDs por cada dígito
#define NUM_LEDS_CRONOMETRO (NUM_DIGITOS_CRONOMETRO * LEDS_POR_DIGITO)
#define NUM_LEDS_PUNTAJE (NUM_DIGITOS_PUNTAJE * LEDS_POR_DIGITO)
#define NUM_LEDS_CONTADORES (NUM_DIGITOS_CONTADORES * LEDS_POR_DIGITO)


// Límites y configuraciones
#define MAX_PUNTAJE 999
#define MAX_FALTAS 9
#define MAX_PERIODO 9
#define BRIGHTNESS 50

void setupLeds();

// Mapeo de segmentos para display de 7 segmentos
const uint8_t SEGMENTOS_LEDS[7][5] = {
  { 5, 6, 7, 8, 9 },       // A
  { 0, 1, 2, 3, 4 },       // B
  { 20, 21, 22, 23, 24 },  // C
  { 25, 26, 27, 28, 29 },  // D
  { 30, 31, 32, 33, 34 },  // E
  { 10, 11, 12, 13, 14 },  // F
  { 15, 16, 17, 18, 19 }   // G
};

// Definición de números de 7 segmentos
const byte NUMEROS[10] = {
  B00111111,  // 0
  B00000110,  // 1
  B01011011,  // 2
  B01001111,  // 3
  B01100110,  // 4
  B01101101,  // 5
  B01111101,  // 6
  B00000111,  // 7
  B01111111,  // 8
  B01101111   // 9
};

// Códigos de comandos
#define CMD_INICIAR_CRONO "IC"
#define CMD_DETENER_CRONO "DC"
#define CMD_AUMENTAR_PUNTAJE_LOCAL "APL"
#define CMD_DISMINUIR_PUNTAJE_LOCAL "DPL"
#define CMD_AUMENTAR_PUNTAJE_VISITANTE "APV"
#define CMD_DISMINUIR_PUNTAJE_VISITANTE "DPV"
#define CMD_AUMENTAR_FALTAS_LOCAL "AFL"
#define CMD_DISMINUIR_FALTAS_LOCAL "DFL"
#define CMD_AUMENTAR_FALTAS_VISITANTE "AFV"
#define CMD_DISMINUIR_FALTAS_VISITANTE "DFV"
#define CMD_AUMENTAR_PERIODO "PP"
#define CMD_REINICIAR_PERIODO "RP"

// Colores
#define COLOR_ACTIVO CRGB(255, 0, 0)  // Rojo
#define COLOR_INACTIVO CRGB::Black

// Declaración de variables globales externas
extern CRGB puntaje_local_display[];
extern CRGB puntaje_visitante_display[];
extern CRGB cronometro_display[];
extern CRGB faltas_local_display[];
extern CRGB faltas_visitante_display[];
extern CRGB periodo_display[];

#endif  // CONFIG_H