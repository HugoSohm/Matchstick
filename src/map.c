/*
** EPITECH PROJECT, 2017
** map.c
** File description:
** Made by Hugo SOHM
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "matchstick.h"

void	print_stars(int stars)
{
	for (int i = 0; i < stars; i++)
		my_putchar('*');
	my_putchar('\n');
}

void	print_map(map_t *map)
{
	int space;
	int width = (2 * map->row) - 1;

	print_stars(width + 2);
	for (int i = 0; i < map->row; i++) {
		space = (width - ((2 * i) + 1)) / 2;
		my_putchar('*');
		for (int j = 0; j < space; j++)
			my_putchar(' ');
		for (int j = 0; j < map->match[i]; j++)
			my_putchar('|');
		space = width - space - map->match[i];
		for (int j = 0; j < space; j++)
			my_putchar(' ');
		my_putstr("*\n");
	}
	print_stars(width + 2);
}

int	my_getnbr_2(char *str)
{
	int nbr = 0;
	int is_neg = 1;

	while (*str) {
		if (*str == '-') {
			is_neg = -1;
			str++;
		} else if (*str == ' ') {
			str++;
		} else {
			nbr = ((*str - '0') + nbr);
			nbr = nbr * 10;
			str++;
		}
	}
	return ((nbr * is_neg) / 10);
}

void	prepare_map(map_t *map, char **av)
{
	map->row = my_getnbr_2(av[1]);
	map->max_matches = my_getnbr_2(av[2]);
	map->success = 1;
	map->turn = 1;
	map->match = malloc (sizeof(int) * map->row);
	if (!map->match) {
		map->success = 0;
		return;
	}
	for (int i = 0; i < map->row; i++)
		map->match[i] = (2 * i) + 1;
}
