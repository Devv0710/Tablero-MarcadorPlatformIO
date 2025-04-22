#include "Config.h"

void setupLeds()
{
    // Initialize the LED strips
    FastLED.addLeds<WS2813, PIN_CRONOMETRO, GRB>(cronometro_display, NUM_LEDS_CRONOMETRO);
    FastLED.addLeds<WS2813, PIN_PUNTAJE_LOCAL, GRB>(puntaje_local_display, NUM_LEDS_PUNTAJE);
    FastLED.addLeds<WS2813, PIN_PUNTAJE_VISITANTE, GRB>(puntaje_visitante_display, NUM_LEDS_PUNTAJE);
    FastLED.addLeds<WS2813, PIN_FALTAS_LOCAL, GRB>(faltas_local_display, NUM_LEDS_CONTADORES);
    FastLED.addLeds<WS2813, PIN_FALTAS_VISITANTE, GRB>(faltas_visitante_display, NUM_LEDS_CONTADORES);
    FastLED.addLeds<WS2813, PIN_PERIODO, GRB>(periodo_display, NUM_LEDS_CONTADORES);
    
    FastLED.setBrightness(BRIGHTNESS);
    FastLED.clear();
    FastLED.show();
}