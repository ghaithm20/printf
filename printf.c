#include "main.h"
#include <stdarg.h>

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
    int num;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%' && *(format + 1) != '\0')
        {
            format++; /* Move past '%' */
            switch (*format)
            {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;

                case 's':
                    str = va_arg(args, char *);
                    if (str == NULL)
                        str = "(null)";
                    while (*str != '\0')
                    {
                        count += putchar(*str);
                        str++;
                    }
                    break;

                case 'd':
                case 'i':
                    num = va_arg(args, int);
                    count += write_number(num);
                    break;

                case '%':
                    count += putchar('%');
                    break;

                default:
                    count += putchar('%');
                    count += putchar(*format);
            }
        }
        else
        {
            count += putchar(*format);
        }

        format++;
    }

    va_end(args);

    return count;
}

/**
 * write_number - Write an integer to standard output
 * @num: Integer to be written
 * Return: Number of characters written
 */
int write_number(int num)
{
    int count = 0;
    char digit;

    // Handle negative numbers
    if (num < 0)
    {
        count += putchar('-');
        num = -num;
    }

    // Write each digit to standard output
    if (num == 0)
    {
        count += putchar('0');
    }
    else
    {
        while (num > 0)
        {
            digit = '0' + (num % 10);
            count += putchar(digit);
            num /= 10;
        }
    }

    return count;
}

/**
 * putchar - Write a character to standard output
 * @c: Character to be written
 * Return: 1 (success), EOF (failure)
 */
int putchar(int c)
{
    return write(1, &c, 1);
}

