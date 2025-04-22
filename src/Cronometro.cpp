#include "Cronometro.h"

// Implementación de variables
uint8_t g_cronometro_minutos = 0;
uint8_t g_cronometro_segundos = 0;
uint8_t g_cronometro_minutos_anteriores = 0;
uint8_t g_cronometro_segundos_anteriores = 0;
bool g_cronometro_activo = false;
unsigned long g_cronometro_inicio = 0;
unsigned long g_cronometro_transcurrido = 0;

void iniciarCronometro()
{
    g_cronometro_activo = true;
    g_cronometro_inicio = millis();
}

void detenerCronometro()
{
    if (g_cronometro_activo)
    {
        g_cronometro_transcurrido = millis() - g_cronometro_inicio + g_cronometro_transcurrido;
        g_cronometro_activo = false;
    }
}

void reiniciarCronometro()
{
    g_cronometro_inicio = millis();
    g_cronometro_transcurrido = 0;
    g_cronometro_minutos = 0;
    g_cronometro_segundos = 0;
    g_cronometro_minutos_anteriores = 0;
    g_cronometro_segundos_anteriores = 0;
    mostrarTiempo(0, 0, cronometro_display);
    actualizarDisplay();
}

void actualizarCronometro()
{
    if (!g_cronometro_activo)
        return;

    static unsigned long ultimoTiempo = 0;
    unsigned long tiempoActual = millis();

    if (tiempoActual - ultimoTiempo >= 1000)
    {
        ultimoTiempo = tiempoActual;

        unsigned long tiempoTranscurridoMS = tiempoActual - g_cronometro_inicio + g_cronometro_transcurrido;
        unsigned long segundosTotales = (tiempoTranscurridoMS / 1000);
        unsigned long minutosTotales = segundosTotales / 60;

        g_cronometro_segundos = (uint8_t)(segundosTotales % 60);
        g_cronometro_minutos = (uint8_t)(minutosTotales % 60);

        if (g_cronometro_segundos != g_cronometro_segundos_anteriores ||
            g_cronometro_minutos != g_cronometro_minutos_anteriores)
        {
            mostrarTiempo(g_cronometro_minutos, g_cronometro_segundos, cronometro_display);
            actualizarDisplay();

            g_cronometro_segundos_anteriores = g_cronometro_segundos;
            g_cronometro_minutos_anteriores = g_cronometro_minutos;

            Serial.print(g_cronometro_minutos);
            Serial.print(":");
            Serial.println(g_cronometro_segundos);
        }
    }
}

uint8_t getCronometroMinutos()
{
    return g_cronometro_minutos;
}

uint8_t getCronometroSegundos()
{
    return g_cronometro_segundos;
}

bool estaCronometroActivo()
{
    return g_cronometro_activo;
}