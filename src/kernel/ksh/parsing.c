/*
 * -------------------------------------------------------------------------
 *                                 AlthenosOS
 *  (c) 2025-2026 littlefly365
 *  This project is under the GPL v3 license.
 *  You should receive the license with the source code. If not - check:
 *  https://github.com/littlefly365/AlthenosOS/blob/main/LICENSE.md
 * -------------------------------------------------------------------------
 */
#include <parsing.h>
#include <string.h>
#include <limits.h>

#include <stdint.h>

uint32_t parse_int(char *string, char c)
{
    uint32_t i = 0;
    char parser[1024] = "";

    while (string[i] != c)
    {
        parser[i] = string[i];
        i++;
        if (string[i] == '\0')
        {
            return (uint32_t)NULL;
        }
    }
    return atoi(parser);
}

double parse_float(char *string, char c)
{
    uint32_t i = 0;
    char parser[1024] = "";

    while (string[i] != c)
    {
        parser[i] = string[i];
        i++;
        if (string[i] == '\0')
        {
            return EPS;
        }
    }
    return atof(parser);
}

void parse_string(char *parser, char *string, char c)
{
    uint32_t i = 0;

    while (string[i] != c)
    {
        parser[i] = string[i];
        i++;
    }
    parser[i] = '\0';
}
