/*
 * -------------------------------------------------------------------------
 *                                 AlthenosOS
 *  (c) 2025-2026 littlefly365
 *  This project is under the GPL v3 license.
 *  You should receive the license with the source code. If not - check:
 *  https://github.com/littlefly365/AlthenosOS/blob/main/LICENSE.md
 * -------------------------------------------------------------------------
 */
#include <string.h>
#include <ramfs.h>
#include <tty.h>
#include <memory.h>

static ramfs_file_t files[128];
static uint32_t file_count = 0;

typedef struct {
    char name[100];
    char mode[8];
    char uid[8];
    char gid[8];
    char size[12];
    char mtime[12];
    char checksum[8];
    char type;
    char linkname[100];
} tar_header_t;

static uint32_t oct2bin(const char *str) {
    uint32_t value = 0;
    while (*str >= '0' && *str <= '7') {
        value = (value << 3) + (*str - '0');
        str++;
    }
    return value;
}

void ramfs_init(uint8_t *addr, uint32_t size) {
    uint8_t *end = addr + size;

    printk("[RAMFS] Inicializando FS en RAM...\n");

    while (addr < end) {
        tar_header_t *h = (tar_header_t*) addr;

        if (h->name[0] == '\0')
            break;

        uint32_t fsize = oct2bin(h->size);
        uint8_t *data = addr + 512;

        // Guardamos archivo
        strcpy(files[file_count].name, h->name);
        files[file_count].data = data;
        files[file_count].size = fsize;
        file_count++;

        // Ir al siguiente header
        uint32_t blocks = (fsize + 511) / 512;
        addr += (blocks + 1) * 512;
    }

    printk("[RAMFS] Listo. Total archivos: %d\n", file_count);
}

ramfs_file_t *ramfs_get(const char *name) {
    for (uint32_t i = 0; i < file_count; i++) {
        if (!strcmp(files[i].name, name))
            return &files[i];
    }
    return 0;
}

int ramfs_read(const char *name, char *buffer, uint32_t bufsize) {
    ramfs_file_t *f = ramfs_get(name);
    if (!f)
        return -1;

    if (bufsize < f->size)
        return -2;

    memcpy(buffer, f->data, f->size);
    return f->size;
}

void ramfs_list(void) {
    for (uint32_t i = 0; i < file_count; i++)
        printk("  %s (%d bytes)\n", files[i].name, files[i].size);
}
