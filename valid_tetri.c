/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:07:19 by clboutry          #+#    #+#             */
/*   Updated: 2019/02/02 14:53:32 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static	int		check_adja(char **tete, int *p_x, int *p_y, int *ptr_adja)
{
	if (tete[*p_x][*p_y] == '#' && *p_x != 3 && tete[(*p_x) + 1][*p_y] == '#')
		(*ptr_adja)++;
	if (tete[*p_x][*p_y] == '#' && *p_y != 3 && tete[*p_x][(*p_y) + 1] == '#')
		(*ptr_adja)++;
	if (*p_x != 0 && tete[(*p_x) - 1][*p_y] == '#' && tete[*p_x][*p_y] == '#')
		(*ptr_adja)++;
	if (*p_y != 0 && tete[*p_x][(*p_y) - 1] == '#' && tete[*p_x][*p_y] == '#')
		(*ptr_adja)++;
	if (*ptr_adja != 0 && tete[*p_x][*p_y] == '#')
		return (1);
	return (0);
}

static	int		is_it_valid(char **tete, int ct_case, int ct_adj, int ct_adj_p)
{
	int		x;
	int		y;

	x = -1;
	while (tete[++x])
	{
		y = -1;
		while (tete[x][++y])
		{
			if (tete[x][y] != '.' && tete[x][y] != '#')
				return (0);
			if (check_adja(tete, &x, &y, &ct_adj))
			{
				ct_case++;
				ct_adj_p += ct_adj;
				ct_adj = 0;
			}
		}
	}
	if (ct_case != 4 || (ct_adj_p != 8 && ct_adj_p != 6))
		return (0);
	return (1);
}

static	void	display_map(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

static	int		fillit(char ***tetri, int size)
{
	char	**map;
	int		map_size;

	map_size = 2;
	if (!(map = calcul_map(2, size, NULL)))
	{
		free_two_array(&map);
		return (0);
	}
	while (!(solve_fillit(tetri, &map, 'A', map_size)))
	{
		free_two_array(&map);
		if (!(map = create_map(++map_size)))
		{
			free_two_array(&map);
			return (0);
		}
	}
	display_map(map);
	free_two_array(&map);
	free_three_array(tetri);
	return (1);
}

int				test_tetri_valid(char ***tetri, int size)
{
	int		i;

	if (!tetri)
		return (0);
	i = -1;
	while (++i < size)
	{
		if (!(is_it_valid(tetri[i], 0, 0, 0)))
		{
			free_three_array(tetri);
			return (0);
		}
	}
	if (!fillit(tetri, size))
		return (0);
	return (1);
}
