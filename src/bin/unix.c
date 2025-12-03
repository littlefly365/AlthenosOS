#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "../include/unix.h"
#include "../include/tty.h"



void cmd_echo(char *s) {
    printk("\n");
    printk(s);
}

extern unsigned char _binary_build_initrd_tar_start;
extern unsigned char _binary_build_initrd_tar_end;

#define TAR_BLOCK 512

struct tar_header {
    char filename[100];
    char mode[8];
    char uid[8];
    char gid[8];
    char size[12];
    char mtime[12];
    char checksum[8];
    char type;
    char linkname[100];
};

static unsigned int oct2bin(const char *str, size_t size) {
    unsigned int n = 0;
    for (size_t i = 0; i < size; i++) {
        if (str[i] < '0' || str[i] > '7')
            break;
        n = (n << 3) + (str[i] - '0');
    }
    return n;
}

void cmd_ls(void) {
    unsigned char *ptr = &_binary_build_initrd_tar_start;
    unsigned char *end = &_binary_build_initrd_tar_end;

//    printk("Initrd listing:\n");

    while (ptr < end) {
        struct tar_header *hdr = (struct tar_header*) ptr;

        // Fin del tar: dos bloques de 512 vacíos
        if (hdr->filename[0] == '\0')
            break;

        unsigned int size = oct2bin(hdr->size, 12);

        printk(" %s ", hdr->filename);

        // avanzar header + contenido alineado a 512 bytes
        unsigned int blocks = (size + 511) / 512;
        ptr += 512 + blocks * 512;
    }
}
