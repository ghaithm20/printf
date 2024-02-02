#include "main.h"
#include <stdarg.h>
#include <stddef.h>  /* Include for NULL definition */
#include <unistd.h>

int _putchar(int c);
int print_str(char *str);
int print_number(int num);
int print_number_recursive(int num);

/**
 * _printf - Custom printf function
 * @format: Format string containing conversion specifiers
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%' && *(format + 1) != '\0')
        {
            format++; /* Move past '%' */
            switch (*format)
            {
                case 'c':
                    count += _putchar(va_arg(args, int));
                    break;

                case 's':
                    count += print_str(va_arg(args, char *));
                    break;

                case 'd':
                case 'i':
                    count += print_number(va_arg(args, int));
                    break;

                default:
                    count += _putchar('%');
                    count += _putchar(*format);
            }
        }
        else
        {
            count += _putchar(*format);
        }

        format++;
    }

    va_end(args);

    return count;
}

/**
 * _putchar - Write a character to standard output
 * @c: Character to be written
 * Return: Number of characters written
 */
int _putchar(int c)
{
    return write(1, &c, 1);
}

/**
 * print_str - Write a string to standard output
 * @str: String to be written
 * Return: Number of characters written
 */
int print_str(char *str)
{
    int count = 0;

    if (str == NULL)
        str = "(null)";

    while (*str != '\0')
    {
        count += _putchar(*str);
        str++;
    }

    return count;
}

/**
 * print_number - Write an integer to standard output
 * @num: Integer to be written
 * Return: Number of characters written
 */
int print_number(int num)
{
    int count = 0;

    /* Handle negative numbers */
    if (num < 0)
    {
        count += _putchar('-');
        num = -num;
    }

    /* Write each digit to standard output */
    if (num == 0)
    {
        count += _putchar('0');
    }
    else
    {
        count += print_number_recursive(num);
    }

    return count;
}

/**
 * print_number_recursive - Helper function to recursively print digits
 * @num: Integer to be written
 * Return: Number of characters written
 */
int print_number_recursive(int num)
{
    int count = 0;

    if (num != 0)
    {
        count += print_number_recursive(num / 10);
        count += _putchar('0' + (num % 10));
    }

    return count;
}

