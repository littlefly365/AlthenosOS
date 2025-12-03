#include "../include/utils.h"
#include "../include/tty.h"

void print_logo(void)
{
printk("\n                   `-/oshdmNMNdhyo+:-`       root@althenosOS\n");
printk(" /s+:-``    `.-:+oydNMMMMNhs/-``             --------------\n");
printk(" m+NMMMMMMMMMMMMMMMMMMMNdhmNMMMmdhs+/-`      OS: Althenos OS i386\n");
printk("  -m+NMMMMMMMMMMMMMMMMMMMMmy+:`              Kernel: Nyx 0.1.3-PreAlpha\n");
printk("   -N/dMMMMMMMMMMMMMMMds:`                   Packages: 1 (Fyra)\n");
printk("   -N/hMMMMMMMMMmho:`                        Shell: Flux 0.0.1\n");
printk("     -N/-:/++/:.`                            Display: 1366x768\n");
printk("      :M+                                    DE: Nethos (TXX)\n");
printk("       :Mo                                   WM: Vex\n");
printk("        :Ms                                  Theme: Default\n");
printk("         :Ms                                 Icons: Disabled\n");
printk("          :Ms                                CPU: Qemu32\n");
printk("           :Ms                               GPU: Qemu-Virtio\n");
printk("            :Ms                              Memory: none\n");
printk("             :Ms                             Font: Stantard-sys\n");
printk("              :Ms                            Cursor: default (24px)\n");
printk("               :Ms                           Terminal: Nytr\n");
printk("                                             Terminal Font: Generic (12pt)\n");
printk("                                             Locale: C.UTF-8\n");
}                                           

void about(char *version)
{
    printk("\n\tAlthenosOS - v%s - Is a 32-bit operating system", version);
    printk("\n\tProvided under the GNU General Public License v3.0");
    printk("\n\tThis project is a fork of another called primus-os");
    printk("\n\tGitHub repository: https://github.com/littlefly365/AlthenosOS\n");  
}
