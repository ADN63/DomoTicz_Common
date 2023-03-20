#pragma once
#ifndef _Domoticz_Common_H_
#define _Domoticz_Common_H_
#ifndef Arduino_h
#include <Arduino.h>
#endif

#include "avr/wdt.h"
#include "printf.h"

#define sizeT(x) (sizeof(x) / sizeof(x[0]))
#define FPSTR(pstr_pointer) (reinterpret_cast<const __FlashStringHelper *>(pstr_pointer))
#define Fstring(x) (String(FPSTR(x)).c_str())
#define string(x) (String(x).c_str())

#ifdef __AVR__
#define P(name) static const unsigned char name[] __attribute__((section(".progmem." #name)))
#else
#define P(name) static const unsigned char name[] PROGMEM
#endif //__AVR__

#define TRACE_F(...) printf(__VA_ARGS__)
#define MAX_LENGTH_EEPROM 15

static FILE uartout = {0};

static int uart_putchar(char c, FILE *stream)
{
    Serial.write(c);
    return 0;
}
struct eeprom_data_t
{
    char nodeName[MAX_LENGTH_EEPROM];
    char nodeId[MAX_LENGTH_EEPROM];
};

eeprom_data_t _Saved_Ref = eeprom_data_t();

#endif