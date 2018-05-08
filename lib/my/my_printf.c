/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** Made by Hugo SOHM
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

int	switch_case(va_list arg, char const *str, int i)
{
	switch (str[i + 1]) {
	case 'd':
		my_put_nbr(va_arg(arg, int));
		break;
	case 'i':
		my_put_nbr(va_arg(arg, int));
		break;
	case 'c':
		my_putchar(va_arg(arg, int));
		break;
	case 's':
		my_putstr(va_arg(arg, char *));
		break;
	case 'x':
		my_putnbr_base(va_arg(arg, unsigned int),
		"0123456789abcdef");
		break;
	case 'X':
		my_putnbr_base(va_arg(arg, unsigned int),
		"0123456789ABCDEF");
		break;
	case 'b':
		my_putnbr_base(va_arg(arg, unsigned int),
		"01");
		break;
	case 'o':
		my_putnbr_base(va_arg(arg, unsigned int),
		"01234567");
		break;
	}
}

int	my_printf(char const *str, ...)
{
	va_list arg;
	int i = 0;

	va_start(arg, str);
	while (str[i] != '\0') {
		if (str[i] == '%') {
			switch_case(arg, str, i);
			i++;
		} else {
			my_putchar(str[i]);
		}
		i++;
	}
	va_end(arg);
	return (0);
}
