/*
 * -------------------------------------------------------------------------
 *                                 AlthenosOS
 *  (c) 2025-2026 littlefly365
 *  This project is under the GPL v3 license.
 *  You should receive the license with the source code. If not - check:
 *  https://github.com/littlefly365/AlthenosOS/blob/main/LICENSE.md
 * -------------------------------------------------------------------------
 */
#ifndef _RANDOM_H
#define _RANDOM_H 1
#include "math.h"
#include "time.h"
#include "stdint.h"

static uint32_t seed = 0;

#define RAND_MAX 4294967295 // 2^32 - 1
#define NORM 2.328306549295728e-10

double rand(void);
void srand(void);

#endif
