#include <vga.h>
#include <string.h>
#include <io.h>

uint16_t *video_memory = (uint16_t *)VIDEO_MEMORY;
uint16_t cursor_pos = 0;

void update_cursor(void) {
    uint16_t pos = cursor_pos;
    outw(0x3D4, 0x0F);
    outw(0x3D5, (uint8_t)(pos & 0xFF));
    outw(0x3D4, 0x0E);
    outw(0x3D5, (uint8_t)((pos >> 8) & 0xFF));
}

void clearscreen(void) {
    for (uint16_t i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        video_memory[i] = ' ' | (0x07 << 8);
    }
    cursor_pos = 0;
    update_cursor();
}
