#include "main.h"
#include <stdarg.h>

/**
 * print_ptr - print_base16_upper_lower
 * @arg: va_list parameter
 *
 * Description: This function print address pointer
 * in representation parameter for print hexadecimal format
 * Return: address pointer
 */

int print_ptr(va_list arg)
{
	unsigned long int dec, buffr;
	char c[100];
	int count, n, i;

	dec = (unsigned long int)va_arg(arg, void*);
	buffr = dec;
	count = 1;
	i = 0;

	if (!dec)
	{
		_puts("(nil)");
		return (5);
	}
	while (buffr)
	{
		buffr /= 16;
		count++;
	}
	c[count + 1] = '\0';
	while (dec > 0)
	{
		n = (dec % 16);
		if (n >= 0 && n <= 9)
			c[count] = ((char)(n + '0'));
		else
			c[count] = ((char)(n + 'W'));
		count--;
		dec /= 16;
	}
	c[0] = '0';
	c[1] = 'x';

	while (c[i] != '\0')
	{
		_putchar(c[i]);
		i++;
	}
	return (i);
}

/**
 * print_rot13 - prints a string using rot13
 * @arg: list of arguments from _printf
 *
 * Return: length of the printed string
 */
int print_rot13(va_list arg)
{
	register short i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(arg, char *);

	if (!s)
	{
		return (-1);
	}

	for (j = 0; s[j]; j++)
	{
		if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
			_putchar(s[j]);
		else
		{
			for (i = 0; i <= 52; i++)
				if (s[j] == rot13[i])
					_putchar(ROT13[i]);
		}
	}
	return (j);
}

/**
 * print_rev - prints a string in reverse
 * @arg: argument from _printf
 * if a flag is passed to _printf
 *
 * Return: length of the printed string
 */
int print_rev(va_list arg)
{
	int i = 0;
	int j;
	char *s = va_arg(arg, char *);

	if (!s)
	{
		return (-1);
	}

	while (s[i])
	{
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		_putchar(s[j]);
	}

	return (i);
}

/**
 * print_unsignedIntToHex - prints unsigned int to hexadecimal.
 * @num: number to print
 * @_case: letter `a` on the case to print it (upper or lower)
 * Return: number or char printed
 */
int print_unsignedIntToHex(unsigned int num, char _case)
{
	unsigned int num2;
	int i, j, remainder, nbrCharacters = 0;
	char *numhex;

	for (num2 = num; num2 != 0; nbrCharacters++, num2 /= 16)
	;

	numhex = malloc(nbrCharacters);
	for (i = 0; num != 0; i++)
	{
		remainder = num % 16;
		if (remainder < 10)
			numhex[i] = remainder + '0';
		else
			numhex[i] = remainder - 10 + _case;
		num = num / 16;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(numhex[j]);
	free(numhex);
	return (nbrCharacters);
}


/**
 * print_STR - prints a string with a `S` (upper case) specificer
 * @arg: argument
 * Return: number of character printed
 */

int print_STR(va_list arg)
{
iint i;
char *str = va_arg(arg, char*);

if (str == NULL)
	str = "(null)";
else if (*str == '\0')
	return (-1);

for (i = 0; str[i]; i++)
{
	if ((str[i] < 32 && str[i] > 0) || str[i] >= 127)
	{
		_putchar('\\');
		_putchar('x');
		if (i < 16)
			_putchar('0');

		print_unsignedIntToHex(str[i], 'A');
	}
	else
		_putchar(str[i]);
}

return (i);
}
