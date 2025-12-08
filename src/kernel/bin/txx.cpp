extern "C" {
#include <tty.h>
#include <txx.h>
#include <globals.h>
#include <string.h>
#include <vga.h>
#include <gui.h>
}
void server(void){
terminal_initialize(COLOR_WHITE, COLOR_BLACK);
clearscreen();
printk("hello from txx\n");
while(1){
gui_loop();
}

}


