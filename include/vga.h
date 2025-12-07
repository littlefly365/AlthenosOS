#include <string.h>

#ifndef VGA_H
#define VGA_H

#define VIDEO_MEMORY 0xB8000
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

extern uint16_t *video_memory;
extern uint16_t cursor_pos;
void clearscreen(void);
void update_cursor(void);
#endif
