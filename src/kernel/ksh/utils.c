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
printk("\n```                        `        root@althenosOS\n");
printk("  ` `.....---.......--.```   -/     --------------\n");
printk("  +o   .--`         /y:`      +.    OS: Althenos OS i386\n");
printk("   yo`:.            :o      `+-     Host: Qemu\n");
printk("    y/               -/`   -o/      Kernel: Nyra v0.1.0\n");
printk("   .-                  ::/sy+:.     Uptime: 1 mins\n");
printk("   /                     `--  /     Packages: 0 (Fyra)\n");
printk("  `:                          :`    Shell: Flux v0.1.0\n");
printk("  `:                          :`    Display (BOE063B): 0:\n");
printk("   /                          /     WM: Terminal\n");
printk("   .-                        -.     CPU: Qemu Default\n");
printk("    --                      -.      GPU: Qemu Virtio\n");
printk("     `:`                  `:`       User: Root \n");
printk("       .--             `--.         Bootloader: Grub\n");
printk("          .---.....----.            Boot mode: Bios Legacy\n");
printk("                                    Memory: 7.38 MiB / 3.71 GiB\n");
printk("                                    Terminal: /dev/tty1\n");

terminal_set_colors(default_font_color, COLOR_BLACK);
}                                           

void about(char *version)
{
    printk("\n\tAlthenosOS - v%s - Is a 32-bit operating system", os_version);
    printk("\n\tProvided under the GNU General Public License v3.0");
    printk("\n\tThis project is a fork of another called primus-os");
    printk("\n\tGitHub repository: https://github.com/littlefly365/AlthenosOS\n");  
}
