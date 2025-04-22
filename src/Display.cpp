#include "Display.h"

void mostrarNumero(uint8_t num, uint8_t digitPosition, CRGB *display)
{
    byte segmentos = NUMEROS[num];
    for (uint8_t seg = 0; seg < 7; seg++)
    {
        bool encender = bitRead(segmentos, seg);
        for (uint8_t i = 0; i < 5; i++)
        {
            display[SEGMENTOS_LEDS[seg][i] + digitPosition] = encender ? COLOR_ACTIVO : COLOR_INACTIVO;
        }
    }
    FastLED.show();
}

void mostrarTiempo(uint8_t minutos, uint8_t segundos, CRGB *display)
{
    Serial.print(minutos, DEC);
    Serial.print(":");
    Serial.println(segundos, DEC);

    if (minutos != minutos_anteriores)
    {
        mostrarNumero(minutos / 10, 3 * LEDS_POR_DIGITO, display);
        mostrarNumero(minutos % 10, 2 * LEDS_POR_DIGITO, display);
        minutos_anteriores = minutos;
        // Serial.println(minutos);
    }
    if (segundos != segundos_anteriores)
    {
        mostrarNumero(segundos / 10, 1 * LEDS_POR_DIGITO, display);
        mostrarNumero(segundos % 10, 0 * LEDS_POR_DIGITO, display);
        segundos_anteriores = segundos;
        // Serial.println(segundos);
    }
}

void mostrarPuntaje(uint8_t puntaje, CRGB *display)
{
    if (puntaje < 10)
    {
        mostrarNumero(puntaje % 10, 0 * LEDS_POR_DIGITO, display);
    }
    else if (puntaje < 100)
    {
        mostrarNumero((puntaje / 10) % 10, 1 * LEDS_POR_DIGITO, display);
        mostrarNumero(puntaje % 10, 0 * LEDS_POR_DIGITO, display);
    }
    else
    {
        mostrarNumero((puntaje / 100) % 10, 2 * LEDS_POR_DIGITO, display);
        mostrarNumero((puntaje / 10) % 10, 1 * LEDS_POR_DIGITO, display);
        mostrarNumero(puntaje % 10, 0 * LEDS_POR_DIGITO, display);
    }
}

void mostrarContador(uint8_t valor, CRGB *display)
{
    mostrarNumero(valor, 0, display);
}

void actualizarDisplay()
{
    FastLED.show();
}