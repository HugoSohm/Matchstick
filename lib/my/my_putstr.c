/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** Made by Hugo SOHM
*/

void my_putchar(char);

int my_putstr(char const *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		my_putchar(str[i]);
	return (0);
}
