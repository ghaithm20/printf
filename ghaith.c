#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string containing conversion specifiers
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char *str;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%' && *(format + 1) != '\0')
        {
            format++; // Move past '%'
            switch (*format)
            {
                case 'c':
                    count += write(1, &va_arg(args, int), 1);
                    break;

                case 's':
                    str = va_arg(args, char *);
                    if (str == NULL)
                        str = "(null)";
                    count += write(1, str, 1);
                    break;

                case '%':
                    count += write(1, "%", 1);
                    break;

                default:
                    count += write(1, "%", 1);
                    count += write(1, format, 1);
            }
        }
        else
        {
            count += write(1, format, 1);
        }

        format++;
    }

    va_end(args);

    return count;
}

