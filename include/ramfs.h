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
