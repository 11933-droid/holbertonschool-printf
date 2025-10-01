#include "main.h"

/**
 * handle_format - handles format specifiers
 * @format: format string
 * @args: argument list
 * @i: pointer to index in format string
 *
 * Return: number of characters printed
 */
int handle_format(const char *format, va_list args, int *i)
{
	int count = 0;

	if (format[*i] == 'c')
		count += print_c(args);
	else if (format[*i] == 's')
		count += print_s(args);
	else if (format[*i] == '%')
		count += print_percent();
	else if (format[*i] == 'd' || format[*i] == 'i')
		count += print_d(args);/*for task 1*/
	else
	{
		write(1, "%", 1);
		write(1, &format[*i], 1);
		count += 2;
	}
	return (count);
}

/**
 * _printf - simple printf
 * @format: string with format
 *
 * Return: number of chars printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}
			count += handle_format(format, args, &i);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

