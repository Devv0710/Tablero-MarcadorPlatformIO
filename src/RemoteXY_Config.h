/*
   -- Prueba --

   This source code of graphical user interface
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.13 or later version
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/
     - for ANDROID 4.15.01 or later version;
     - for iOS 1.12.1 or later version;

   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// you can enable debug logging to Serial at 115200
// #define REMOTEXY__DEBUGLOG

// RemoteXY select connection mode and include library
#define REMOTEXY_MODE__ESP32CORE_BLE

#include <BLEDevice.h>

// RemoteXY connection settings
#define REMOTEXY_BLUETOOTH_NAME "RemoteXY"

#include <RemoteXY.h>

// RemoteXY GUI configuration
#pragma pack(push, 1)

uint8_t RemoteXY_CONF[] =   // 326 bytes
  { 255,13,0,9,0,63,1,19,0,0,0,0,173,1,106,200,1,1,24,0,
  67,28,14,43,15,78,134,26,2,67,5,48,40,15,93,2,186,2,78,17,
  27,11,0,1,26,31,31,79,78,0,79,70,70,0,129,41,2,21,8,64,
  16,84,105,109,101,114,0,129,15,37,20,8,64,16,76,111,99,97,108,0,
  129,39,89,28,8,64,16,80,101,114,105,111,100,111,0,1,4,67,19,15,
  1,135,16,43,0,1,82,92,19,15,1,135,16,43,0,1,5,154,20,11,
  1,135,16,43,0,1,26,67,19,15,1,36,16,45,0,1,63,67,19,15,
  1,135,16,43,0,1,85,67,19,15,1,36,16,45,0,129,69,37,32,8,
  64,16,86,105,115,105,116,97,110,116,101,0,129,42,122,22,8,64,16,70,
  97,108,116,97,115,0,67,63,48,40,15,93,2,186,67,25,100,54,15,93,
  177,186,67,6,135,40,15,93,2,186,67,62,135,40,15,93,2,186,12,4,
  171,97,10,194,30,186,83,101,108,101,99,99,105,111,110,101,0,70,195,186,
  116,115,97,108,0,86,111,108,108,101,121,0,66,97,115,107,101,116,98,97,
  108,108,0,1,4,185,98,13,1,27,16,82,101,105,110,105,99,105,97,114,
  32,116,111,100,111,0,1,82,109,19,15,1,36,16,45,0,1,27,154,20,
  11,1,36,16,45,0,1,61,154,20,11,1,135,16,43,0,1,83,154,20,
  11,1,36,16,45,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t on_off; // =1 if switch ON and =0 if OFF
  uint8_t incre_punto_local; // =1 if button pressed, else =0
  uint8_t incre_periodo; // =1 if button pressed, else =0
  uint8_t incre_falta_local; // =1 if button pressed, else =0
  uint8_t decre_punto_local; // =1 if button pressed, else =0
  uint8_t incre_punto_visitante; // =1 if button pressed, else =0
  uint8_t decre_punto_visitante; // =1 if button pressed, else =0
  uint8_t selector; // from 0 to 4
  uint8_t reiniciar; // =1 if button pressed, else =0
  uint8_t decre_periodo; // =1 if button pressed, else =0
  uint8_t decre_falta_local; // =1 if button pressed, else =0
  uint8_t incre_falta_visitante; // =1 if button pressed, else =0
  uint8_t decre_falta_visitante; // =1 if button pressed, else =0

    // output variables
  float cronometro;
  int8_t p_Local; // -128 .. 127
  int8_t p_Visitante; // -128 .. 127
  int8_t periodo; // -128 .. 127
  int8_t f_Local; // -128 .. 127
  int8_t f_Visitante; // -128 .. 127

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   

#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

void setupRemoteXY()
{
    // RemoteXY begin
    RemoteXY_Init();
    // RemoteXY end

    // TODO you setup code
}
void loopRemoteXY()
{
    // RemoteXY handler
    RemoteXY_Handler();

    // TODO you loop code
    // use the RemoteXY structure for data transfer
    // do not call delay(), use instead RemoteXY_delay()
}
