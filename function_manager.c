#include "main.h"
#include <stdarg.h>
/**
 *function_manager - calls other functions
 *@c: character to find
 *@arg: va_list type
 *
 *Return: count of printed characters
 */
int function_manager(char c, va_list arg)
{
	int cont = 0;

	cont = _switch(c, arg);
	if (c == 'p')
		cont = print_ptr(arg);
	return (cont);
}
/**
 *_switch - evaluates cases
 *@c: character to find
 *@arg: va_list type
 *
 *Return: count of printed characters
 */
int _switch(char c, va_list arg)
{
	int cont = 0;

	switch (c)
	{
		case 'b':
			cont += print_unsign(arg, 2);
			break;
		case 'c':
			cont += print_character(arg);
			break;
		case 'd':
		case 'i':
			cont += print_sign(arg, 10);
			break;
		case 'o':
			cont += print_unsign(arg, 8);
			break;
		case 'r':
			cont += print_rev(arg);
			break;
		case 'R':
			cont += print_rot13(arg);
			break;
		case 's':
			cont += print_string(arg);
			break;
		case 'u':
			cont += print_unsign(arg, 10);
			break;
		case 'x':
			cont += print_base16_upper_lower(arg, "0123456789abcdef");
			break;
		case 'X':
			cont += print_base16_upper_lower(arg, "0123456789ABCDEF");
			break;
		case 'S':
			cont += print_STR(arg);
		default:
			cont = -1;
	}
	return (cont);
}
