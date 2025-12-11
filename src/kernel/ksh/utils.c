/*
 * -------------------------------------------------------------------------
 *                                 AlthenosOS
 *  (c) 2025-2026 littlefly365
 *  This project is under the GPL v3 license.
 *  You should receive the license with the source code. If not - check:
 *  https://github.com/littlefly365/AlthenosOS/blob/main/LICENSE.md
 * -------------------------------------------------------------------------
 */
#include <utils.h>
#include <tty.h>
#include <unix.h>
#include <version.h>
#include <globals.h>

void print_logo(void)
{
terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
printk("\n```                        `        ");
printk("root@althenos\n");
printk("  ` `.....---.......--.```   -/     ");
printk("--------------\n");
printk("  +o   .--`         /y:`      +.    OS: ");
terminal_set_colors(COLOR_LIGHT_GREY, COLOR_BLACK);
printk("Althenos OS i386\n");
terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
printk("   yo`:.            :o      `+-     Host: ");
terminal_set_colors(COLOR_LIGHT_GREY, COLOR_BLACK);
printk("althenos\n");
terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
printk("    y/               -/`   -o/      Kernel: ");
terminal_set_colors(COLOR_LIGHT_GREY, COLOR_BLACK);
printk("Nyra v0.1.0\n");
terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
printk("   .-                  ::/sy+:.     Uptime: ");
terminal_set_colors(COLOR_LIGHT_GREY, COLOR_BLACK);
printk("1 mins\n");
terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
printk("   /                     `--  /     Packages: ");
terminal_set_colors(COLOR_LIGHT_GREY, COLOR_BLACK);
printk("0 (Fyra)\n");
terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
printk("  `:                          :`    Shell: ");
terminal_set_colors(COLOR_LIGHT_GREY, COLOR_BLACK);
printk("Flux v0.1.0\n");
terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
printk("  `:                          :`    Display (BOE063B): ");
terminal_set_colors(COLOR_LIGHT_GREY, COLOR_BLACK);
printk("Display\n");
terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
printk("   /                          /     WM: ");
terminal_set_colors(COLOR_LIGHT_GREY, COLOR_BLACK);
printk("Terminal\n");
terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
printk("   .-                        -.     CPU: ");
terminal_set_colors(COLOR_LIGHT_GREY, COLOR_BLACK);
printk("Qemu Default\n");
terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
printk("    --                      -.      GPU: ");
terminal_set_colors(COLOR_LIGHT_GREY, COLOR_BLACK);
printk("Qemu Virtio\n");
terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
printk("     `:`                  `:`       User: ");
terminal_set_colors(COLOR_LIGHT_GREY, COLOR_BLACK);
printk("Root \n");
terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
printk("       .--             `--.         Bootloader: ");
terminal_set_colors(COLOR_LIGHT_GREY, COLOR_BLACK);
printk("Grub\n");
terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
printk("          .---.....----.            Boot mode: ");
terminal_set_colors(COLOR_LIGHT_GREY, COLOR_BLACK);
printk("Bios Legacy\n");
terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
printk("                                    Memory: ");
terminal_set_colors(COLOR_LIGHT_GREY, COLOR_BLACK);
printk("7.38 MiB / 3.71 GiB\n");
terminal_set_colors(COLOR_LIGHT_RED, COLOR_BLACK);
printk("                                    Terminal: ");
terminal_set_colors(COLOR_LIGHT_GREY, COLOR_BLACK);
printk("/dev/tty1\n");
terminal_set_colors(default_font_color, COLOR_BLACK);
}                                           

void about(char *version)
{
    printk("\n\tAlthenosOS - v%s - Is a 32-bit operating system", os_version);
    printk("\n\tProvided under the GNU General Public License v3.0");
    printk("\n\tThis project is a fork of another called primus-os");
    printk("\n\tGitHub repository: https://github.com/littlefly365/AlthenosOS\n");  
}
