#include <stdio.h>
#include "main.h"

/**
 * print_number - prints out input
 * @n: input
 * Return: integer
 */
int print_number(int n)
{
	k = 0, l = 0
	if (n < 0)
	{
		_putchar('-');
		n = -n;
		l = 1;
	}
	if (n / 10)
	{
		print_number( n / 10);
		k++;
	}else
	{
		_putchar(n % 10 + '0');
	}
	return (k + l);
}

/**
 * uprint_number - prints out unsigned input
 * @n: unsigned int to be printed
 *
 * Return: integer
 */
int uprint_number(unsigned int n)
{
	unsigned int a, b;
	int k = 0;

	if (n != 0)
	{
		a = n / 10;
		b = n % 10;
		if (a != 0)
		{
			k = uprint_number(a);
			_putchar(b + '0');
			k++;
		}
		else
		{
			_putchar(b + '0');
			k = 1;
		}
	}
	else
		_putchar('0');
	return (k);
}
