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
#include <utils.h>
#include <reader.h>
#include <globals.h>
#include <unix.h>
#include <string.h>	
#include <shell_history.h>
#include <txx.h>
#include <vga.h>
#include <gui.h>

void for_use(const char *cmd)
{
(void)cmd;   
}
		
void commands_reader(void){
				    char *cmd = NULL;
        			char *arg = NULL;

        			cmd = strtok(buffer, " ");
       	 			arg = strtok(NULL, "");   


				if (strlen(buffer) > 0 && strcmp(buffer, "exit") == 0)
				{
					printk("goodbye");
					shutdown();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "help") == 0)
				{
					printk("\n\tBasic kernel commands:");
					printk("\n\t fastfetch          - \ta tool like neofetch");
					printk("\n\t about              - \tabout AlthenosOS");
					printk("\n\t clear              - \tclears the screen");
					printk("\n\t color              - \tchange default font color");
					printk("\n\t reboot             - \treboots system");
					printk("\n\t shutdown           - \tsends shutdown signal");
					printk("\n\t ls                 - \tlist files and directories in current directory");
					printk("\n\t echo               - \tshow text in the screen");
					printk("\n");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "about") == 0)
				{
					about(os_version);
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "fastfetch") == 0)
				{
					print_logo();
					printk("\n");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "color") == 0)
				{
					default_font_color = change_font_color();	
					printk("\n");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "clear") == 0)
				{
					terminal_initialize(default_font_color, COLOR_BLACK);
					strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "reboot") == 0)
				{
										reboot();
										printk("\n");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "shutdown") == 0)
				{
										shutdown();
										printk("\n");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "ls") == 0)
                                {
										printk("\n");
          			 					cmd_ls();
										printk("\n");
                                }
				else if (strlen(buffer) > 0 && strcmp(buffer, "echo") == 0)
                                {
                                        cmd_echo(arg);
										printk("\n");
                                }
				else if (strlen(buffer) > 0 && strcmp(buffer, "fluxv") == 0)
                                {
										printk("\n");
										fluxv();
										printk("\n");
                                }	
				else if (strlen(buffer) > 0 && strcmp(buffer, "flux") == 0)
                                {
                                        flux();
										printk("\n");
                                }
				else if (strlen(buffer) > 0 && strcmp(buffer, "kname") == 0)
                                {
                                        printk("\n");
										kname();
										printk("\n");
                                }
				else if (strlen(buffer) > 0 && strcmp(buffer, "os_name") == 0)
                                {
                                        printk("\n");
										os_name();
										printk("\n");
								 }
				else if (strlen(buffer) > 0 && strcmp(buffer, "txx") == 0)
                                {
										server();
                                }
				else if (strlen(buffer) > 0 && strcmp(buffer, "cowsay") == 0)
                                {
										cowsay(arg);
										printk("\n");
                                }
				else
								{
										printk("\nflux: '%s': command not found ", buffer);
										printk("\n");
								}  
				
               for_use(cmd);
            }


        
