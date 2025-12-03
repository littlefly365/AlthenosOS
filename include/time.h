#ifndef _TIME_H
#define _TIME_H 1

#include "stdint.h"

uint8_t get_update_in_progress_flag(void);
uint32_t get_RTC_register(uint8_t reg);
void datetime(void);
void date(void);
void clock(void);
uint32_t current_seconds(void);
uint32_t current_minutes(void);
uint32_t current_hour(void);
uint32_t current_day(void);
uint32_t current_month(void);
uint32_t current_year(void);

#endif
