/*
 * -------------------------------------------------------------------------
 *                                 AlthenosOS
 *  (c) 2025-2026 littlefly365
 *  This project is under the GPL v3 license.
 *  You should receive the license with the source code. If not - check:
 *  https://github.com/littlefly365/AlthenosOS/blob/main/LICENSE.md
 * -------------------------------------------------------------------------
 */
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include <unix.h>
#include <tty.h>
#include <version.h>
#include <globals.h>

 void cowsay(char message[1024]) {
        int message_length = strlen(message);

        printk("\n", 0x07);
        printk("\n", 0x07);
        printk(" < ", 0x07);
        printk(message, 0x07);
        printk(" > \n", 0x07);
        printk("  ", 0x07);
        printk("", 0x07);

        printk("\\    ^__^\n", 0x07);
        printk("    \\  (oo)\\_______\n", 0x07);
        printk("       (__)\\       )\\/\n", 0x07);
        printk("           ||---w||\n", 0x07);
        printk("           ||    ||\n", 0x07);
    }
void kname(void){
char kernel_version[7];
sprintf(kernel_version, "%u.%u.%u", KV1, KV2, KV3);
printk("Nyra v%s",kernel_version);
}

void os_name(void){
char os_version[7];
sprintf(os_version, "%u.%u.%u", OV1, OV2, OV3);
printk("AlthenosOS v%s i386",os_version);
}

void cmd_echo(char *s) {
    printk("\n");
    printk(s);
}
void fluxv(void){
printk("Flux v0.1.0");
}

int flux(void){
return 0;
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

    while (ptr < end) {
        struct tar_header *hdr = (struct tar_header*) ptr;

        if (hdr->filename[0] == '\0')
            break;

        unsigned int size = oct2bin(hdr->size, 12);
        printk("%s ", hdr->filename);

        unsigned int blocks = (size + 511) / 512;
        ptr += 512 + blocks * 512;
    }
}
