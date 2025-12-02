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


void commands_reader(){


				if (strlen(buffer) > 0 && strcmp(buffer, "exit") == 0)
				{

				}
				else if (strlen(buffer) > 0 && strstr(buffer, "sha224(") != NULL)
				{
					char *parser;
					char string[64];
					parser = strstr(buffer, "sha224(");
					parser += strlen("sha224(");
					parse_string(string, parser, ')');
					sha224(string);
				}
				else if (math_func(buffer))
				{
					math_shell(buffer);
				}
   			    else if (strlen(buffer) > 0 && strcmp(buffer, "math") == 0)
				{
					printk("\n\n\tMathematical functions:\n");
					printk("\n\t rand()             - \tpseudo random number generator");
					printk("\n\t srand()            - \tpseudo random number generator seed");
					printk("\n\t fact(x)            - \treturns factorial of x");
					printk("\n\t abs(x)             - \treturns absolute value of x");
					printk("\n\t sqrt(x)            - \treturns square root of x");
					printk("\n\t pow(x,y)           - \treturns the y power of x");
					printk("\n\t exp(x)             - \treturns the natural exponential of x");
					printk("\n\t ln(x)              - \treturns the natural logarithm of x");
					printk("\n\t log10(x)           - \treturns the logarithm of x base 10");
					printk("\n\t log(x,y)           - \treturns the logarithm of x base y");
					printk("\n\t sin(x)             - \treturns sine of x");
					printk("\n\t cos(x)             - \treturns cosine of x");
					printk("\n\t tan(x)             - \treturns tangent of x");
					printk("\n\t asin(x)            - \treturns arcsine of x");
					printk("\n\t acos(x)            - \treturns arccosine of x");
					printk("\n\t atan(x)            - \treturns arctangent of x");
					printk("\n\t sinh(x)            - \treturns hyperbolic sine of x");
					printk("\n\t cosh(x)            - \treturns hyperbolic cosine of x");
					printk("\n\t tanh(x)            - \treturns hyperbolic tangent of x");
					printk("\n\t asinh(x)           - \treturns inverse hyperbolic sine of x");
					printk("\n\t acosh(x)           - \treturns inverse hyperbolic cosine of x");
					printk("\n\t atanh(x)           - \treturns inverse hyperbolic tangent of x");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "crypto") == 0)
				{
					printk("\n\nCryptography utilities:\n");
					printk("\n\t sha224(string)     - \tSHA-224 hashing");
					printk("\n\t sha256(string)     - \tSHA-256 hashing");
					printk("\n");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "help") == 0)
				{
					printk("\n\n\tBasic kernel commands:\n");
					printk("\n\t fastfetch          - \ta tool like neofetch");
					printk("\n\t about              - \tabout AlthenosOS");
					printk("\n\t math               - \tlists all mathematical functions");
					printk("\n\t crypto             - \tlists all cryptography utilities");
					printk("\n\t clear              - \tclears the screen");
					printk("\n\t fontcolor          - \tchange default font color");
					printk("\n\t datetime           - \tdisplays current date and time");
					printk("\n\t date               - \tdisplays current date");
					printk("\n\t clock              - \tdisplays clock");
					printk("\n\t history            - \tdisplays commands history");
					printk("\n\t reboot             - \treboots system");
					printk("\n\t shutdown           - \tsends shutdown signal");
					printk("\n");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "about") == 0)
				{
					about(current_version);
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "fastfetch") == 0)
				{
					print_logo();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "fontcolor") == 0)
				{
					default_font_color = change_font_color();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "clear") == 0)
				{
					terminal_initialize(default_font_color, COLOR_BLACK);
					strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "datetime") == 0)
				{
					printk("\nCurrent datetime: ");
					datetime();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "date") == 0)
				{
					printk("\nCurrent date: ");
					date();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "clock") == 0)
				{
					printk("\nCurrent clock: ");
					clock();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "reboot") == 0)
				{
					reboot();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "shutdown") == 0)
				{
					shutdown();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "history") == 0)
				{             
                print_history(head);
				}
				else if (strlen(buffer) > 0 && (strstr(buffer, "+") != NULL || strstr(buffer, "-") != NULL || strstr(buffer, "*") != NULL|| strstr(buffer, "/") != NULL ))
				{
					compute(buffer);
				}
				else
				{
					printk("\n'%s' is not a recognized command. ", buffer);
				}                 
            }


        