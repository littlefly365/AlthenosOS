/*
 * -------------------------------------------------------------------------
 *                                 AlthenosOS
 *  (c) 2025-2026 littlefly365
 *  This project is under the GPL v3 license.
 *  You should receive the license with the source code. If not - check:
 *  https://github.com/littlefly365/AlthenosOS/blob/main/LICENSE.md
 * -------------------------------------------------------------------------
 */
#ifndef RAMFS_H
#define RAMFS_H

#include <stdint.h>

typedef struct {
    char name[128];
    uint8_t *data;
    uint32_t size;
} ramfs_file_t;

void ramfs_init(uint8_t *addr, uint32_t size);
ramfs_file_t *ramfs_get(const char *name);
void ramfs_list(void);
int ramfs_read(const char *name, char *buffer, uint32_t bufsize);

#endif
