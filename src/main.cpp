#include "Config.h"
#include "Display.h"
#include "RemoteXY_Config.h"

CRGB puntaje_local_display[NUM_LEDS_PUNTAJE];
CRGB puntaje_visitante_display[NUM_LEDS_PUNTAJE];
CRGB cronometro_display[NUM_LEDS_CRONOMETRO];
CRGB faltas_local_display[NUM_LEDS_CONTADORES];
CRGB faltas_visitante_display[NUM_LEDS_CONTADORES];
CRGB periodo_display[NUM_LEDS_CONTADORES];

static uint8_t segundos = 0, minutos = 0;

static uint8_t puntaje_local = 0, puntaje_visitante = 0;
static uint8_t faltas_local = 0, faltas_visitante = 0, periodo = 1;





void procesarComando(String comando);
bool botonPuntajePlusEstadoAnterior = false;
bool botonPuntajeMinusEstadoAnterior = false;

void setup() {
  setupRemoteXY();
  Serial.begin(115200);
  setupLeds();


}


void loop() {
  loopRemoteXY();
  // if (RemoteXY.incre_falta_local && !botonPuntajePlusEstadoAnterior) {
  //   botonPuntajePlusEstadoAnterior = true;
  //   if (faltas_local < 9) {
  //     faltas_local++;
  //     mostrarNumero(faltas_local, 0, faltas_local_display);
  //     RemoteXY.f_Local = faltas_local;
  //   }
  // } else if (RemoteXY.incre_falta_local == 0) {
  //   botonPuntajePlusEstadoAnterior = false;
  // }
  
  // if (RemoteXY.decre_falta_local && !botonPuntajeMinusEstadoAnterior) {
  //   botonPuntajeMinusEstadoAnterior = true;
  //   if (faltas_local > 0) {
  //     faltas_local--;
  //     mostrarNumero(faltas_local, 0, faltas_local_display);
  //     RemoteXY.f_Local = faltas_local;
  //   }
  // } else if (RemoteXY.decre_falta_local == 0) {
  //   botonPuntajeMinusEstadoAnterior = false;
  // }


  
  // // if (cronometroActivo) {
  // //   cronometro(minutos, segundos, cronometro_display);
  // // }

  // mostrarPuntaje(puntaje_local, puntaje_local_display);
  // mostrarPuntaje(puntaje_visitante, puntaje_visitante_display);
  // // mostrarNumero(faltas_local, 0, faltas_local_display);
  // mostrarNumero(faltas_visitante, 0, faltas_visitante_display);
  // mostrarNumero(periodo, 0, periodo_display);
  // // RemoteXY_delay(1);  // Pequeña pausa para evitar watchdog reset

  // if (Serial.available()) {
  //   String comando = Serial.readStringUntil('\n');
  //   comando.trim();
  //   procesarComando(comando);
  // }
}






// void procesarComando(String comando) {
//   if (comando == "IC") {
//     cronometroActivo = true;
//     inicioCronometro = millis();
//   } else if (comando == "DC") {
//     transcurrido = millis() - inicioCronometro + transcurrido;
//     cronometroActivo = false;
//   } else if (comando == "APL") {
//     if (puntaje_local < 999) puntaje_local++;
//   } else if (comando == "DPL") {
//     if (puntaje_local > 0) puntaje_local--;
//   } else if (comando == "APV") {
//     if (puntaje_visitante < 999) puntaje_visitante++;
//   } else if (comando == "DPV") {
//     if (puntaje_visitante > 0) puntaje_visitante--;
//   } else if (comando == "AFL") {
//     if (faltas_local < 9) faltas_local++;
//   } else if (comando == "DFL") {
//     if (faltas_local > 0) faltas_local--;
//   } else if (comando == "AFV") {
//     if (faltas_visitante < 9) faltas_visitante++;
//   } else if (comando == "DFV") {
//     if (faltas_visitante > 0) faltas_visitante--;
//   } else if (comando == "PP") {
//     if (periodo < 9) periodo++;
//   } else if (comando == "RP") {
//     periodo = 1;
//   } else {
//     Serial.println("Comando no reconocido");
//   }
// }
