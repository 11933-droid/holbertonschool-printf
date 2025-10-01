#include "main.h"

/**
 * print_c - prints a char
 * @args: list of args
 * Return: 1
 */
int print_c(va_list args)
{
	char c = (char)va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_s - prints a string
 * @args: list of args
 * Return: length of string
 */
int print_s(va_list args)
{
	int i;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
		write(1, &str[i], 1);

	return (i);
}

/**
 * print_percent - prints %
 * Return: 1
 */
int print_percent(void)
{
	char c = '%';

	write(1, &c, 1);
	return (1);
}

/**
 * print_d - prints a signed integer %d and %i
 * @args: list of arguments
 * Return: number of char printed
 */

int print_d(va_list args)
{
	int n = va_arg(args, int);
	int len = 0;
	char buf[12];
	int i = 0;

	if (n < 0)
	{
		write(1, "-", 1);
		len++;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return (len + 1);
	}
	while (n != 0)
	{
		int digit = n % 10;

		if (digit < 0)
			digit = -digit;
		buf[i++] = (char)(digit + '0');
		n /= 10;
	}
	while (i > 0)
	{
		i--;
		write(1, &buf[i], 1);
		len++;
	}
	return (len);
}
