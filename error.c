/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:56:19 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/02/02 15:34:33 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdlib.h>

int		display_error(char *s)
{
	ft_putendl(s);
	return (0);
}

int		free_one_array(char **tmp, int error_level)
{
	if (error_level == 0 || error_level == -1)
	{
		ft_putendl("error");
		if (*tmp)
			free(*tmp);
	}
	return (error_level);
}

char	***free_two_array(char ***tab)
{
	int		i;
	char	**object;

	i = 0;
	object = *tab;
	while (object[i])
	{
		free(object[i]);
		i++;
	}
	free(object);
	object = NULL;
	return (NULL);
}

char	***free_three_array(char ***tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			free(tab[i][j]);
			j++;
		}
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}
