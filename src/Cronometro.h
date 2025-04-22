#ifndef CRONOMETRO_H
#define CRONOMETRO_H

#include "Display.h"

// Variables del cronómetro
extern uint8_t g_cronometro_minutos;
extern uint8_t g_cronometro_segundos;
extern uint8_t g_cronometro_minutos_anteriores;
extern uint8_t g_cronometro_segundos_anteriores;
extern bool g_cronometro_activo;

extern unsigned long g_cronometro_inicio;
extern unsigned long g_cronometro_transcurrido;

// Funciones para el cronómetro
void iniciarCronometro();
void detenerCronometro();
void reiniciarCronometro();
void actualizarCronometro();
uint8_t getCronometroMinutos();
uint8_t getCronometroSegundos();

bool estaCronometroActivo();

#endif  // CRONOMETRO_H