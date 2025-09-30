#include "main.h"

/**
 * _printf - simple printf
 * @format: string with format
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				count += print_c(args);
			else if (format[i] == 's')
				count += print_s(args);
			else if (format[i] == '%')
				count += print_percent();
			else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
			}
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

