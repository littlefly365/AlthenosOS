#include <stdint.h>
#include <stddef.h>
#include <gui.h>

volatile uint32_t *fb = (volatile uint32_t*)0xE0000000;

void put_pixel(int x,int y, uint32_t color) {
if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return;
//		fs[y * SCREEN_WIDTH + x] = color;
} 

void draw_rect(int x,int y, int w, int h, uint32_t color){
for(int j = 0; j < h; j++)
	for(int i = 0; i < w; i++)
		put_pixel(x + i, y + j, color);
}

typedef struct{
int x, y, w, h;
uint32_t color;
} Window;

typedef struct{
int x, y;
int left_button;
} Mouse;

Window win = {100, 100, 200, 150,0xFF00FF00};
Mouse mouse = {320, 240, 0};

void gui_loop(void){
int dragging = 0;
int drag_offset_x = 0, drag_offset_y = 0;
draw_rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0X11100000);
draw_rect(win.x, win.y, win.w, win.h, win.color);
}
