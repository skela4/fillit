/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:46:07 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/02/02 14:47:03 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static	int		check(char **map, int *col, int *row)
{
	if ((*row < 0 || *row >= (int)ft_strlen(*map))
			|| (*col < 0 || *col >= (int)ft_strlen(*map))
			|| (map[*col][*row] != '.'))
		return (0);
	return (1);
}

static	int		is_place(char **tetri, char **map, int c, int r)
{
	int		i;
	int		j;
	int		tmp_x;
	int		tmp_y;
	int		place;

	i = -1;
	place = 0;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
		{
			(tetri[i][j] != '.' && i != tmp_y && place) ? c = c + i - tmp_y : 1;
			(tetri[i][j] != '.' && j != tmp_x && place) ? r = r + j - tmp_x : 1;
			(tetri[i][j] != '.') ? tmp_x = j : 1;
			(tetri[i][j] != '.') ? tmp_y = i : 1;
			(tetri[i][j] != '.') ? place = 1 : 1;
			if (tetri[i][j] != '.' && !check(map, &c, &r))
				return (0);
			if (tetri[i][j] != '.')
				map[c][r] = tetri[i][j];
		}
	}
	return (1);
}

int				solve_fillit(char ***tetri, char ***map, char lettre, int size)
{
	int		i;
	int		j;

	if (!*tetri)
		return (1);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			replace_map(tetri, lettre);
			if (is_place(*tetri, *map, i, j))
			{
				if (solve_fillit(tetri + 1, map, lettre + 1, size))
					return (1);
				remove_lettre(&*map, lettre, size);
			}
			remove_lettre(&*map, lettre, size);
			j++;
		}
		i++;
	}
	j++;
	return (0);
}
