#include "main.h"
#include <string.h>
#include <stdio.h>

/**
 * rev_string - reverses a string in place
 * @s: string to be reversed
 */
void rev_string(char *s)
{
	int len = strlen(s);
	int i, j, tmp;

	i = 0;
	j = len - 1;

	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}
