/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 22:42:12 by ebellon           #+#    #+#             */
/*   Updated: 2021/07/03 03:07:50 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		dead_or_alive(int **map, int res_x, int res_y, int x, int y)
{
	int	nb_near_cels_alive;

	nb_near_cels_alive = 0;
	if (x - 1 >= 0 && y - 1 >= 0 && map[y - 1][x - 1] == 1)
		nb_near_cels_alive++;
	if (y - 1 >= 0 && map[y - 1][x] == 1)
		nb_near_cels_alive++;
	if (x + 1 < res_x && y - 1 >= 0 && map[y - 1][x + 1] == 1)
		nb_near_cels_alive++;
	if (x - 1 >= 0 && map[y][x - 1] == 1)
		nb_near_cels_alive++;
	if (x + 1 < res_x && map[y][x + 1] == 1)
		nb_near_cels_alive++;
	if (x - 1 >= 0 && y + 1 < res_y && map[y + 1][x - 1] == 1)
		nb_near_cels_alive++;
	if (y + 1 < res_y && map[y + 1][x] == 1)
		nb_near_cels_alive++;
	if (x + 1 < res_x && y + 1 < res_y && map[y + 1][x + 1] == 1)
		nb_near_cels_alive++;
	if (map[y][x] == 1)
	{
		if (nb_near_cels_alive > 3)
			return (0);
		if (nb_near_cels_alive == 3 || nb_near_cels_alive == 2)
			return (1);
	}
	else if (map[y][x] == 0 && nb_near_cels_alive == 3)
		return (1);
	return (0);
}

void	game(int **map, int res_x, int res_y)
{
	int		x;
	int		y;
	int		new_map[res_y][res_x];
	char	*s;
	int		i;
	int		gen;

	s = malloc(sizeof(char) * y * ((x * 2) + 2) + 1 );
	gen = 0;
    while (1)
	{
		y = 0;
		usleep(100000);
		printf("\033[H\033[2J");
		i = 0;
		while (y < res_y)
		{
			x = 0;
			s[i++] = '|';
			while (x < res_x)
			{
				if (map[y][x] == 1)
					s[i++] = '*';
				else
					s[i++] = ' ';
				s[i++] = '|';
				x++;
			}
			s[i++] = '\n';
			y++;
		}
		s[i] = 0;
		printf("gen : %d\n", gen++);
		printf("%s", s);
		y = 0;
		while (y < res_y)
		{
			x = 0;
			while (x < res_x)
			{
				new_map[y][x] = dead_or_alive(map, res_x, res_y, x, y);
				x++;
			}
			y++;
		}
		y = 0;
		while (y < res_y)
		{
			x = 0;
			while (x < res_x)
			{
				map[y][x] = new_map[y][x];
				x++;
			}
			y++;
		}
		// exit(0);
	}
}

int	main(int ac, char **av)
{
	int		**map;
	int		res_x;
	int		res_y;
	int		i;
	int		x;
	int		y;

	res_x = atoi(av[1]);
	res_y = atoi(av[2]);
	map = malloc(sizeof(int *) * res_y);
	i = 0;
	while (i < res_y)
		map[i++] = malloc(sizeof(int) * res_x);
	
	y = 0;
	while (y < res_y)
	{
		x = 0;
		while (x < res_x)
		{
			map[y][x] = 0;

			/* gliders canon */
			if (y == 40 + 7 && x == 30 - 13)
				map[y][x] = 1;
			if (y == 40 + 7 && x == 31 - 13)
				map[y][x] = 1;
			if (y == 41 + 7 && x == 29 - 13)
				map[y][x] = 1;
			if (y == 41 + 7 && x == 33 - 13)
				map[y][x] = 1;
			if (y == 42 + 7 && x == 28 - 13)
				map[y][x] = 1;
			if (y == 42 + 7 && x == 34 - 13)
				map[y][x] = 1;
			if (y == 42 + 7 && x == 42 - 13)
				map[y][x] = 1;
			if (y == 43 + 7 && x == 18 - 13)
				map[y][x] = 1;
			if (y == 43 + 7 && x == 19 - 13)
				map[y][x] = 1;
			if (y == 43 + 7 && x == 28 - 13)
				map[y][x] = 1;
			if (y == 43 + 7 && x == 32 - 13)
				map[y][x] = 1;
			if (y == 43 + 7 && x == 34 - 13)
				map[y][x] = 1;
			if (y == 43 + 7 && x == 35 - 13)
				map[y][x] = 1;
			if (y == 43 + 7 && x == 40 - 13)
				map[y][x] = 1;
			if (y == 43 + 7 && x == 42 - 13)
				map[y][x] = 1;
			if (y == 44 + 7 && x == 18 - 13)
				map[y][x] = 1;
			if (y == 44 + 7 && x == 19 - 13)
				map[y][x] = 1;
			if (y == 44 + 7 && x == 28 - 13)
				map[y][x] = 1;
			if (y == 44 + 7 && x == 34 - 13)
				map[y][x] = 1;
			if (y == 44 + 7 && x == 38 - 13)
				map[y][x] = 1;
			if (y == 44 + 7 && x == 39 - 13)
				map[y][x] = 1;
			if (y == 45 + 7 && x == 29 - 13)
				map[y][x] = 1;
			if (y == 45 + 7 && x == 33 - 13)
				map[y][x] = 1;
			if (y == 45 + 7 && x == 38 - 13)
				map[y][x] = 1;
			if (y == 45 + 7 && x == 39 - 13)
				map[y][x] = 1;
			if (y == 45 + 7 && x == 52 - 13)
				map[y][x] = 1;
			if (y == 45 + 7 && x == 53 - 13)
				map[y][x] = 1;
			if (y == 46 + 7 && x == 30 - 13)
				map[y][x] = 1;
			if (y == 46 + 7 && x == 31 - 13)
				map[y][x] = 1;
			if (y == 46 + 7 && x == 38 - 13)
				map[y][x] = 1;
			if (y == 46 + 7 && x == 39 - 13)
				map[y][x] = 1;
			if (y == 46 + 7 && x == 52 - 13)
				map[y][x] = 1;
			if (y == 46 + 7 && x == 53 - 13)
				map[y][x] = 1;
			if (y == 47 + 7 && x == 40 - 13)
				map[y][x] = 1;
			if (y == 47 + 7 && x == 42 - 13)
				map[y][x] = 1;
			if (y == 48 + 7 && x == 42 - 13)
				map[y][x] = 1;
			x++;
		}
		y++;
	}

	game(map, res_x, res_y);
	
	return (0);
}