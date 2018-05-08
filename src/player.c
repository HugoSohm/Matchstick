/*
** EPITECH PROJECT, 2017
** player.c
** File description:
** Made by Hugo SOHM
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "gnl.h"
#include "matchstick.h"

int	get_line(void)
{
	char *str_line;
	int line;

	my_putstr("Line: ");
	str_line = get_next_line(0);
	if (!str_line)
	        return (-2);
	line = my_getnbr(str_line);
	return (line);
}

int	get_matches(void)
{
	char	*str_matches;
	int	matches;

	my_putstr("Matches: ");
	str_matches = get_next_line(0);
	if (!str_matches)
		return (-2);
	matches = my_getnbr(str_matches);
	return (matches);
}

void	check_line(map_t *map, int line)
{
	if (line == 0 || line > map->row) {
		my_putstr("Error: this line is out of range\n");
		map->success = 0;
		return;
	} else if (line < 0) {
		my_putstr("Error: invalid input (positive number expected)\n");
		map->success = 0;
		return;
	}
}

void	check_match(map_t *map, int matches, int line)
{
	if (matches > map->max_matches) {
		my_printf("%s %d %s", "Error: you cannot remove more than", \
		map->max_matches, "matches per turn\n");
		map->success = 0;
		return;
	} else if (matches == 0) {
		my_putstr("Error: you have to remove at least one match\n");
		map->success = 0;
		return;
	}
	if (matches < 0){
		my_putstr("Error: invalid input (positive number expected)\n");
		map->success = 0;
		return;
	} else if (matches > map->match[line - 1]) {
		my_putstr("Error: not enough matches on this line\n");
		map->success = 0;
		return;
	}
}

int	player_turn(map_t *map)
{
	int line;
	int matches;

	if (map->success == 0)
		map->success = 1;
	line = get_line();
	if (line == -2)
		return (-2);
	check_line(map, line);
	if (map->success == 0)
		return (-1);
	matches = get_matches();
	if (matches == -2)
		return (-2);
	check_match(map, matches, line);
	if (map->success == 0)
		return (1);
	map->success = 1;
	map->turn = 2;
	matches_stick(map, line, matches);
	return (0);
}
