/* DateStrings.cpp
 * Definitions for date strings for use with the Time library
 *
 * Updated for Arduino 1.5.7 18 July 2014
 *
 * No memory is consumed in the sketch if your code does not call any of the string methods
 * You can change the text of the strings, make sure the short strings are each exactly 3 characters 
 * the long strings can be any length up to the constant dt_MAX_STRING_LEN defined in Time.h
 * 
 */

/*
  Apr 10 2015 - append support Cyrillic UTF-8 by Dmitry Anokhin
*/

#if defined(__AVR__)
#include <avr/pgmspace.h>
#else
// for compatiblity with Arduino Due and Teensy 3.0 and maybe others?
#define PROGMEM
#define PGM_P  const char *
#define pgm_read_byte(addr) (*(const unsigned char *)(addr))
#define pgm_read_word(addr) (*(const unsigned char **)(addr))
#define strcpy_P(dest, src) strcpy((dest), (src))
#endif
#include <string.h> // for strcpy_P or strcpy
#include "Time.h"
 
// the short strings for each day or month must be exactly dt_SHORT_STR_LEN
#if defined(LANGUAGE_CYRILLIC_UTF8) // Russian language
//#define dt_SHORT_STR_LEN  4 // not needed

static char buffer[dt_MAX_STRING_LEN+1];  // must be big enough for longest string and the terminating null

const char monthStr0[] PROGMEM = "";
const char monthStr1[] PROGMEM = "Январь";
const char monthStr2[] PROGMEM = "Февраль";
const char monthStr3[] PROGMEM = "Март";
const char monthStr4[] PROGMEM = "Апрель";
const char monthStr5[] PROGMEM = "Май";
const char monthStr6[] PROGMEM = "Июнь";
const char monthStr7[] PROGMEM = "Июль";
const char monthStr8[] PROGMEM = "Август";
const char monthStr9[] PROGMEM = "Сентябрь";
const char monthStr10[] PROGMEM = "Октябрь";
const char monthStr11[] PROGMEM = "Ноябрь";
const char monthStr12[] PROGMEM = "Декабрь";

const PROGMEM char * const PROGMEM monthNames_P[] =
{
    monthStr0,monthStr1,monthStr2,monthStr3,monthStr4,monthStr5,monthStr6,
    monthStr7,monthStr8,monthStr9,monthStr10,monthStr11,monthStr12
};

const char monthShortStr0[] PROGMEM = "---";
const char monthShortStr1[] PROGMEM = "Янв";
const char monthShortStr2[] PROGMEM = "Фев";
const char monthShortStr3[] PROGMEM = "Март";
const char monthShortStr4[] PROGMEM = "Апр";
const char monthShortStr5[] PROGMEM = "Май";
const char monthShortStr6[] PROGMEM = "Июнь";
const char monthShortStr7[] PROGMEM = "Июль";
const char monthShortStr8[] PROGMEM = "Авг";
const char monthShortStr9[] PROGMEM = "Сент";
const char monthShortStr10[] PROGMEM = "Окт";
const char monthShortStr11[] PROGMEM = "Ноя";
const char monthShortStr12[] PROGMEM = "Дек";

const PROGMEM char * const PROGMEM monthShortNames_P[] =
{
    monthShortStr0,monthShortStr1,monthShortStr2,monthShortStr3,monthShortStr4,monthShortStr5,monthShortStr6,
    monthShortStr7,monthShortStr8,monthShortStr9,monthShortStr10,monthShortStr11,monthShortStr12
};

const char dayStr0[] PROGMEM = "Ошибка";
const char dayStr1[] PROGMEM = "Воскресенье";
const char dayStr2[] PROGMEM = "Понедельник";
const char dayStr3[] PROGMEM = "Вторник";
const char dayStr4[] PROGMEM = "Среда";
const char dayStr5[] PROGMEM = "Четверг";
const char dayStr6[] PROGMEM = "Пятница";
const char dayStr7[] PROGMEM = "Суббота";

const PROGMEM char * const PROGMEM dayNames_P[] =
{
   dayStr0,dayStr1,dayStr2,dayStr3,dayStr4,dayStr5,dayStr6,dayStr7
};

const char dayShortStr0[] PROGMEM = "--";
const char dayShortStr1[] PROGMEM = "ВС";
const char dayShortStr2[] PROGMEM = "ПН";
const char dayShortStr3[] PROGMEM = "ВТ";
const char dayShortStr4[] PROGMEM = "СР";
const char dayShortStr5[] PROGMEM = "ЧТ";
const char dayShortStr6[] PROGMEM = "ПТ";
const char dayShortStr7[] PROGMEM = "СБ";

const PROGMEM char * const PROGMEM dayShortNames_P[] =
{
   dayShortStr0,dayShortStr1,dayShortStr2,dayShortStr3,dayShortStr4,dayShortStr5,dayShortStr6,dayShortStr7
};

/* functions to return date strings */

char* monthShortStr(uint8_t month)
{
    strcpy_P(buffer, (PGM_P)pgm_read_word(&(monthShortNames_P[month])));
    return buffer;
}

char* dayShortStr(uint8_t day) // short day of the week on Russian
{
   strcpy_P(buffer, (PGM_P)pgm_read_word(&(dayShortNames_P[day])));
   return buffer;
}

#else

// Original English
#define dt_SHORT_STR_LEN  3 // the length of short strings

static char buffer[dt_MAX_STRING_LEN+1];  // must be big enough for longest string and the terminating null

const char monthStr0[] PROGMEM = "";
const char monthStr1[] PROGMEM = "January";
const char monthStr2[] PROGMEM = "February";
const char monthStr3[] PROGMEM = "March";
const char monthStr4[] PROGMEM = "April";
const char monthStr5[] PROGMEM = "May";
const char monthStr6[] PROGMEM = "June";
const char monthStr7[] PROGMEM = "July";
const char monthStr8[] PROGMEM = "August";
const char monthStr9[] PROGMEM = "September";
const char monthStr10[] PROGMEM = "October";
const char monthStr11[] PROGMEM = "November";
const char monthStr12[] PROGMEM = "December";

const PROGMEM char * const PROGMEM monthNames_P[] =
{
    monthStr0,monthStr1,monthStr2,monthStr3,monthStr4,monthStr5,monthStr6,
    monthStr7,monthStr8,monthStr9,monthStr10,monthStr11,monthStr12
};

const char monthShortNames_P[] PROGMEM = "ErrJanFebMarAprMayJunJulAugSepOctNovDec";

const char dayStr0[] PROGMEM = "Err";
const char dayStr1[] PROGMEM = "Sunday";
const char dayStr2[] PROGMEM = "Monday";
const char dayStr3[] PROGMEM = "Tuesday";
const char dayStr4[] PROGMEM = "Wednesday";
const char dayStr5[] PROGMEM = "Thursday";
const char dayStr6[] PROGMEM = "Friday";
const char dayStr7[] PROGMEM = "Saturday";

const PROGMEM char * const PROGMEM dayNames_P[] =
{
   dayStr0,dayStr1,dayStr2,dayStr3,dayStr4,dayStr5,dayStr6,dayStr7
};

const char dayShortNames_P[] PROGMEM = "ErrSunMonTueWedThrFriSat";

/* functions to return date strings */

char* monthShortStr(uint8_t month)
{
   for (int i=0; i < dt_SHORT_STR_LEN; i++)      
      buffer[i] = pgm_read_byte(&(monthShortNames_P[i+ (month*dt_SHORT_STR_LEN)]));  
   buffer[dt_SHORT_STR_LEN] = 0;
   return buffer;
}

char* dayShortStr(uint8_t day) 
{
   uint8_t index = day*dt_SHORT_STR_LEN;
   for (int i=0; i < dt_SHORT_STR_LEN; i++)      
      buffer[i] = pgm_read_byte(&(dayShortNames_P[index + i]));  
   buffer[dt_SHORT_STR_LEN] = 0; 
   return buffer;
}

#endif //LANGUAGE_CYRILLIC_UTF8

char* monthStr(uint8_t month)
{
    strcpy_P(buffer, (PGM_P)pgm_read_word(&(monthNames_P[month])));
    return buffer;
}

char* dayStr(uint8_t day) 
{
   strcpy_P(buffer, (PGM_P)pgm_read_word(&(dayNames_P[day])));
   return buffer;
}
