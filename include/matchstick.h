/*
** EPITECH PROJECT, 2017
** matchstick.h
** File description:
** Made by Hugo SOHM
*/

#ifndef MATCHSTICK_H
#define MATCHSTICK_H

typedef struct map {
	int row;
	int max_matches;
	int success;
	int turn;
	int *match;
} map_t;

int	get_line(void);
int	get_matches(void);
void	check_line(map_t *map, int line);
void	check_match(map_t *map, int matches, int line);
int	player_turn(map_t *map);
void	ai_turn(map_t *map);
void	print_stars(int stars);
void	print_map(map_t *map);
void	prepare_map(map_t *map, char **av);
void	matches_stick(map_t *map, int line, int matches);
int	won_mess(map_t *map);
int	is_won(map_t *map);
int	matchstick(map_t *map);

#endif
