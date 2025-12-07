/*
 * -------------------------------------------------------------------------
 *                                 AlthenosOS
 *  (c) 2025-2026 littlefly365
 *  This project is under the GPL v3 license.
 *  You should receive the license with the source code. If not - check:
 *  https://github.com/littlefly365/AlthenosOS/blob/main/LICENSE.md
 * -------------------------------------------------------------------------
 */

#include <tty.h>
#include <io.h>
#include <kbd.h>
#include <string.h>
#include <bool.h>
#include <memory.h>
#include <thread.h>
#include <shell_history.h>
#include <reader.h>
#include <globals.h>
#include <ramfs.h>
#include <version.h>

extern uint8_t initrd_start;
extern uint8_t initrd_end;

#define DEBUG false

uint8_t numlock = true;
uint8_t capslock = false;
uint8_t scrolllock = false;
uint8_t shift = false;

char buffer[BUFFER_SIZE];
char *string;
char *buff;
uint8_t byte;
node_t *head = NULL;
char os_version[7];


int kmain(void)
{
	terminal_initialize(default_font_color, COLOR_BLACK);
	terminal_set_colors(COLOR_LIGHT_BLUE, COLOR_BLACK);
	terminal_set_colors(default_font_color, COLOR_BLACK);
	heap_init();
	sprintf(os_version, "%u.%u.%u", OV1, OV2, OV3);



#if DEBUG
	int *a = (int *)kmalloc(sizeof(int));
	void *b = kmalloc(5000);
	void *c = kmalloc(50000);
	*a = 1;
	printf("\na: %d", *a);
	printf("\na: %p", (void *)a);
	printf("\nb: %p", (void *)b);
	printf("\nc: %p", (void *)c);
	kfree(a);
	kfree(b);
	kfree(c);
#endif

	strcpy(&buffer[strlen(buffer)], "");
    prompt();
	while (true)
	{
		while ((byte = scan()))
		{
			if (byte == ENTER)
			{	
				strcpy(buffer, tolower(buffer));
				insert_at_head(&head, create_new_node(buffer));

				commands_reader();
				prompt();
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
				char *s = NULL;
				s = ctos(s, c);
				printk("%s", s);
				buffer[strlen(buffer) - 1] = '\0';
			}
			else
			{
				char c1 = togglecode[byte];
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
				char *s = NULL;
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
