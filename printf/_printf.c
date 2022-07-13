#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * 
 * _putchar - print
 * _printf - 
 * main - 
*/ 

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);

	int i;
	int count = 0;

	for (i = 0; format[i] != '\0'; i++)
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			char var;

			var = va_arg(ap, int);
			_putchar(var);
			count++;
			i++;
		}
		else
		{
			char *ptr;

			ptr = va_arg(ap, char*);
			while (*(ptr) != '\0')
				_putchar(*ptr);
				ptr++;
				count++;
				i++;
		}

	va_end(ap);
	return (count);
}

int main(void)
{
	int wordcount = 0;
	wordcount = _printf("Hello %s", "Mallam");
	printf("The string has %d characters\n", wordcount);
	return (0);
}

