#include "main.h"
#include <stdarg.h>
/**
 * _switch - evaluates cases
 * @c: character to find
 * @arg: va_list type
 * Return: count of printed characters
 */
int _switch(char c, va_list arg)
{
	int cont = 0;

	switch (c)
	{
		case 'c':
			cont += print_unsign(arg, 2);
			break;
		case 'd':
		case 'i':
			cont += print_sign(arg, 10);
			break;
		case 's':
			cont += print_string(arg);
			break;
		default:
			cont = -1;
	}
	return (cont);
}

/**
 * function_manager - calls other functions
 * @c: character to find
 * @arg: va_list type
 * Return: count of printed characters
 */
int function_manager(char c, va_list arg)
{
	int cont = 0;

	cont = _switch(c, arg);
	if (c == 'p')
		cont = print_ptr(arg);
	return (cont);
}
