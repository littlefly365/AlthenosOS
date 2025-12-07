/*
 * -------------------------------------------------------------------------
 *                                 AlthenosOS
 *  (c) 2025-2026 littlefly365
 *  This project is under the GPL v3 license.
 *  You should receive the license with the source code. If not - check:
 *  https://github.com/littlefly365/AlthenosOS/blob/main/LICENSE.md
 * -------------------------------------------------------------------------
 */
#ifndef UNIX_H
#define UNIX_H

void cowsay(char message[1024]);
void cmd_ls(void);
void cmd_echo(char *s);
int flux(void);
void fluxv(void);
void kname(void);
void os_name(void);
#endif
