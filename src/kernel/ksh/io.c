/*
 * -------------------------------------------------------------------------
 *                                 AlthenosOS
 *  (c) 2025-2026 littlefly365
 *  This project is under the GPL v3 license.
 *  You should receive the license with the source code. If not - check:
 *  https://github.com/littlefly365/AlthenosOS/blob/main/LICENSE.md
 * -------------------------------------------------------------------------
 */
#include <io.h>
#include <tty.h>

void shutdown(void)
{
    outw(0xB004, 0x2000);
    outw(0x604, 0x2000);
    outw(0x4004, 0x3400);
}

void reboot(void)
{
    uint8_t temp;

    __asm__ volatile("cli");

    do
    {
        temp = input_bytes(KBRD_INTRFC);
        if (check_flag(temp, KBRD_BIT_KDATA) != 0)
            input_bytes(KBRD_IO); 
    } while (check_flag(temp, KBRD_BIT_UDATA) != 0);

    output_bytes(KBRD_INTRFC, KBRD_RESET); 
loop:
    __asm__ volatile("hlt"); 
    goto loop;          
}

uint8_t input_bytes(uint16_t port)
{
    uint8_t ret;
    __asm__ __volatile__("inb %1, %0"
                         : "=a"(ret)
                         : "Nd"(port));
    return ret;
}

void output_bytes(uint16_t port, uint8_t val)
{
    __asm__ __volatile__("outb %0, %1"
                         :
                         : "a"(val), "Nd"(port));
}

uint8_t inw(uint16_t port)
{
    uint8_t ret;
    __asm__ __volatile__("in %1, %0"
                         : "=a"(ret)
                         : "d"(port));
    return ret;
}

void outw(uint16_t port, uint16_t data)
{
    __asm__ __volatile__("out %0, %1"
                         :
                         : "a"(data), "d"(port));
}

uint8_t scan(void)
{
    unsigned char brk;
    static uint8_t key = 0;
    uint8_t read_char = input_bytes(0x60);
    brk = read_char & 0x80;
    read_char = read_char & 0x7f;
    if (brk)
    {
        return key = 0;
    }
    else if (read_char != key)
    {
        return key = read_char;
    }
    else
    {
        return 0;
    }
}

void move_cursor(int row, int col)
{
    unsigned short pos = (row * VGA_WIDTH) + col;
    output_bytes(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    output_bytes(FB_DATA_PORT, (unsigned char)(pos & 0xFF));
    output_bytes(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    output_bytes(FB_DATA_PORT, (unsigned char)((pos >> 8) & 0xFF));
}

void print_prompt(void)
{
    printk("\n[root@althenos ~]$ ");
    move_cursor(get_terminal_row(), get_terminal_col());
}
void prompt(void)
{
    printk("[root@althenos ~]$ ");
    move_cursor(get_terminal_row(), get_terminal_col());
}
