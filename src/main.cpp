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
static bool cronometroActivo = false;
long inicioCronometro = 0;
long transcurrido = 0;



void mostrarNumero(uint8_t num, uint8_t digitPosition, CRGB* display);
void mostrarTiempo(uint8_t minutos, uint8_t segundos, CRGB* display);
void cronometro(uint8_t& minutos, uint8_t& segundos, CRGB* display);
void mostrarPuntaje(uint8_t puntaje, CRGB* display);
void procesarComando(String comando);
bool botonPuntajePlusEstadoAnterior = false;
bool botonPuntajeMinusEstadoAnterior = false;

void setup() {
  setupRemoteXY();

  Serial.begin(115200);

  FastLED.addLeds<WS2813, PIN_CRONOMETRO, GRB>(cronometro_display, NUM_LEDS_CRONOMETRO);
  FastLED.addLeds<WS2813, PIN_PUNTAJE_LOCAL, GRB>(puntaje_local_display, NUM_LEDS_PUNTAJE);
  FastLED.addLeds<WS2813, PIN_PUNTAJE_VISITANTE, GRB>(puntaje_visitante_display, NUM_LEDS_PUNTAJE);
  FastLED.addLeds<WS2813, PIN_FALTAS_LOCAL, GRB>(faltas_local_display, NUM_LEDS_CONTADORES);
  FastLED.addLeds<WS2813, PIN_FALTAS_VISITANTE, GRB>(faltas_visitante_display, NUM_LEDS_CONTADORES);
  FastLED.addLeds<WS2813, PIN_PERIODO, GRB>(periodo_display, NUM_LEDS_CONTADORES);
  FastLED.setBrightness(50);

  FastLED.clear();
  FastLED.show();

//  Activar cronómetro automáticamente
  cronometroActivo = true;
  inicioCronometro = millis();
}


void loop() {
  loopRemoteXY();
  if (RemoteXY.incre_falta_local && !botonPuntajePlusEstadoAnterior) {
    botonPuntajePlusEstadoAnterior = true;
    if (faltas_local < 9) {
      faltas_local++;
      mostrarNumero(faltas_local, 0, faltas_local_display);
      RemoteXY.f_Local = faltas_local;
    }
  } else if (RemoteXY.incre_falta_local == 0) {
    botonPuntajePlusEstadoAnterior = false;
  }
  if (RemoteXY.decre_falta_local && !botonPuntajeMinusEstadoAnterior) {
    botonPuntajeMinusEstadoAnterior = true;
    if (faltas_local > 0) {
      faltas_local--;
      mostrarNumero(faltas_local, 0, faltas_local_display);
      RemoteXY.f_Local = faltas_local;
    }
  } else if (RemoteXY.decre_falta_local == 0) {
    botonPuntajeMinusEstadoAnterior = false;
  }


  
  if (cronometroActivo) {
    cronometro(minutos, segundos, cronometro_display);
  }
  mostrarPuntaje(puntaje_local, puntaje_local_display);
  mostrarPuntaje(puntaje_visitante, puntaje_visitante_display);
  // mostrarNumero(faltas_local, 0, faltas_local_display);
  mostrarNumero(faltas_visitante, 0, faltas_visitante_display);
  mostrarNumero(periodo, 0, periodo_display);
  // RemoteXY_delay(1);  // Pequeña pausa para evitar watchdog reset

  if (Serial.available()) {
    String comando = Serial.readStringUntil('\n');
    comando.trim();
    procesarComando(comando);
  }
}

void cronometro(uint8_t& minutos, uint8_t& segundos, CRGB* display) {
  static unsigned long ultimoTiempo = 0;
  unsigned long tiempoActual = millis();

  if (tiempoActual - ultimoTiempo >= 1000) {
    ultimoTiempo = tiempoActual;

    long tiempoTranscurridoMS = tiempoActual - inicioCronometro + transcurrido;
    long segundosTotales = (tiempoTranscurridoMS / 1000);
    long minutosTotales = segundosTotales / 60;

    segundos = (uint8_t)(segundosTotales % 60);
    minutos = (uint8_t)(minutosTotales % 60);
    /*
    if (++segundos >= 60) {
      segundos = 0;
      if (++minutos >= 100) minutos = 0;
    }
    */
    mostrarTiempo(minutos, segundos, display);
  }
}





void procesarComando(String comando) {
  if (comando == "IC") {
    cronometroActivo = true;
    inicioCronometro = millis();
  } else if (comando == "DC") {
    transcurrido = millis() - inicioCronometro + transcurrido;
    cronometroActivo = false;
  } else if (comando == "APL") {
    if (puntaje_local < 999) puntaje_local++;
  } else if (comando == "DPL") {
    if (puntaje_local > 0) puntaje_local--;
  } else if (comando == "APV") {
    if (puntaje_visitante < 999) puntaje_visitante++;
  } else if (comando == "DPV") {
    if (puntaje_visitante > 0) puntaje_visitante--;
  } else if (comando == "AFL") {
    if (faltas_local < 9) faltas_local++;
  } else if (comando == "DFL") {
    if (faltas_local > 0) faltas_local--;
  } else if (comando == "AFV") {
    if (faltas_visitante < 9) faltas_visitante++;
  } else if (comando == "DFV") {
    if (faltas_visitante > 0) faltas_visitante--;
  } else if (comando == "PP") {
    if (periodo < 9) periodo++;
  } else if (comando == "RP") {
    periodo = 1;
  } else {
    Serial.println("Comando no reconocido");
  }
}
