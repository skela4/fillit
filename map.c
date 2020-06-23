/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 08:45:56 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/02/02 15:16:18 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include "libft/libft.h"

void	replace_map(char ***map, char lettre)
{
	int		i;
	int		j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if ((*map)[i][j] == '#')
				(*map)[i][j] = lettre;
			j++;
		}
		i++;
	}
}

char	**calcul_map(int map_size, int size, char **map)
{
	int		n_case;

	map_size = 2;
	n_case = size * SIZE;
	while (n_case > map_size * map_size)
		map_size++;
	map = create_map(map_size);
	return (map);
}

char	**create_map(int size)
{
	char	**map;
	int		i;
	int		j;

	if (!(map = (char **)malloc(sizeof(*map) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return (*(free_two_array(&map)));
		j = 0;
		while (j < size)
			map[i][j++] = '.';
		map[i][j] = '\0';
		i++;
	}
	map[i] = 0;
	return (map);
}

void	remove_lettre(char ***map, char lettre, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if ((*map)[i][j] == lettre)
				(*map)[i][j] = '.';
			j++;
		}
		i++;
	}
}
