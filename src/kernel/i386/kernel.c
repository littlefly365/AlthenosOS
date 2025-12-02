#include "../include/version.h"
#include "../include/tty.h"
#include "../include/io.h"
#include "../include/kbd.h"
#include "../include/string.h"
#include "../include/time.h"
#include "../include/math_shell.h"
#include "../include/parsing.h"
#include "../include/bool.h"
#include "../include/sha224.h"
#include "../include/sha256.h"
#include "../include/utils.h"
#include "../include/easter.h"
#include "../include/sleep.h"
#include "../include/thread.h"
#include "../include/memory.h"
#include "../include/shell_history.h"
#include "../include/calculator.h"
#include "../include/reader.h"
#include "../include/globals.h"

#define DEBUG false

#define BUFFER_SIZE 1024

uint8_t numlock = true;
uint8_t capslock = false;
uint8_t scrolllock = false;
uint8_t shift = false;
char current_version[7];


char buffer[BUFFER_SIZE];
char *string;
char *buff;
uint8_t byte;
node_t *head = NULL;

int kmain(void)
{

	terminal_initialize(default_font_color, COLOR_BLACK);
	terminal_set_colors(COLOR_LIGHT_BLUE, COLOR_BLACK);
	sprintf(current_version, "%u.%u.%u", V1, V2, V3 + 1);
//	print_logo();
	about(current_version);
	printk("\n\tType \"help\" for a list of commands.\n\n");
	printk("\n\tWelcome!\n\n");

	terminal_set_colors(default_font_color, COLOR_BLACK);

	// initialize heap
	heap_init();

#if DEBUG
	// memory test
	int *a = (int *)kmalloc(sizeof(int));
	void *b = kmalloc(5000);
	void *c = kmalloc(50000);
	*a = 1;
	printf("\na: %d", *a);
	printf("\na: %p", (void *)a);
	printf("\nb: %p", (void *)b);
	printf("\nc: %p", (void *)c);
	// int *b = (int *)kmalloc(0x1000);
	// int *c = (int *)kmalloc(sizeof(int));
	// printf("\nb: %x", b);
	// printf("\nc: %x", c);
	// kfree(b);
	// int *d = (int *)kmalloc(0x1000); // here should be adress of B
	// printf("\nd: %x", d);
	// kfree(d);
	// kfree(c);
	kfree(a);
	kfree(b);
	kfree(c);
#endif

	strcpy(&buffer[strlen(buffer)], "");
	print_prompt();
	while (true)
	{
		while (byte = scan())
		{
			if (byte == ENTER)
			{	
				strcpy(buffer, tolower(buffer));
				insert_at_head(&head, create_new_node(buffer));

				commands_reader();
				print_prompt();
				memset(buffer, 0, BUFFER_SIZE);
				strcpy(&buffer[strlen(buffer)], "");
				break;
			}
			else if ((byte == BACKSPACE) && (strlen(buffer) == 0))
			{
				printk("\n");
			}
			else if (byte == BACKSPACE)
			{
				char c = normalmap[byte];
				char *s;
				s = ctos(s, c);
				printk("%s", s);
				buffer[strlen(buffer) - 1] = '\0';
			}
			else
			{
				char c1 = togglecode[byte];
				char c2 = shiftcode[byte];
				char c;
				if (c1 == CAPSLOCK)
				{
					if (!capslock)
					{
						capslock = true;
					}
					else
					{
						capslock = false;
					}
				}
				if (capslock)
				{
					c = capslockmap[byte];
				}
				else if (shift)
				{
					c = shiftmap[byte];
					shift = false;
				}
				else
				{
					c = normalmap[byte];
				}
				char *s;
				s = ctos(s, c);
				printk("%s", s);
				strcpy(&buffer[strlen(buffer)], s);
				if (byte == 0x2A || byte == 0x36)
				{
					shift = true;
				}
			}
			move_cursor(get_terminal_row(), get_terminal_col());
		}
	}
	return 0;
}
