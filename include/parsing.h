/*
 * -------------------------------------------------------------------------
 *                                 AlthenosOS
 *  (c) 2025-2026 littlefly365
 *  This project is under the GPL v3 license.
 *  You should receive the license with the source code. If not - check:
 *  https://github.com/littlefly365/AlthenosOS/blob/main/LICENSE.md
 * -------------------------------------------------------------------------
 */
#ifndef _PARSING_H
#define _PARSING_H 1

#include "stdint.h"

uint32_t parse_int(char *string, char c);
double parse_float(char *string, char c);
void parse_string(char *parser, char *string, char c);

#endif
