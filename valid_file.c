/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 12:42:13 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/02/02 15:54:06 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void		cpy_tmp(void *tmp, char **line)
{
	ft_bzero((char *)tmp, SIZE);
	ft_strcpy((char *)tmp, *line);
	free(*line);
}

static	void	read_line(int fd, char **line)
{
	free(*line);
	get_next_line(fd, &*line);
}

static	char	***put_to_tab(char ***tab, int fd, int size, char *line)
{
	int		i;
	int		j;

	if (!(tab = (char ***)malloc(sizeof(char **) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(tab[i] = (char **)malloc(sizeof(line) * (SIZE + 1))))
			return (free_three_array(tab));
		j = 0;
		while (j < SIZE)
		{
			if (get_next_line(fd, &line) && !*line)
				read_line(fd, &line);
			if (!(tab[i][j] = ft_strnew(SIZE)))
				return (free_three_array(tab));
			cpy_tmp(tab[i][j++], &line);
		}
		tab[i++][j] = 0;
	}
	tab[i] = 0;
	return (tab);
}

static	int		check_line(int fd, int size, char **line)
{
	char			*tmp;
	int				nb_line;
	int				nb_map;

	tmp = ft_strnew(BUFF_SIZE);
	nb_line = 0;
	nb_map = 0;
	while ((size = get_next_line(fd, &*line)))
	{
		if (size < 0 || (*tmp == '\0' && *(*line) == '\0')
				|| (*(*line) == '\0' && nb_line != 4))
			return (free_one_array(&tmp, 0));
		if (*(*line) == '\0' && nb_line == 4)
			nb_line = -1;
		if (nb_line >= 0 && ft_strlen(*line) != 4)
			return (free_one_array(&tmp, 0));
		nb_line++;
		cpy_tmp(tmp, &*line);
		(!ft_strlen(tmp)) ? nb_map++ : 1;
	}
	if ((size == 0 && *tmp == '\0') || (size == 0 && nb_line != 4))
		return (free_one_array(&tmp, -1));
	free(tmp);
	return (nb_map + 1);
}

int				main(int ac, char **argv)
{
	int			fd;
	int			size;
	char		*line;
	int			ret;
	char		***tab;

	fd = 0;
	size = 0;
	tab = NULL;
	if (ac != 2)
		return (display_error("usage : ./fillit target_file"));
	fd = open(argv[ac - 1], O_RDONLY);
	if (fd < 0)
		return (display_error("error"));
	if (!(ret = (check_line(fd, size, &line))))
		free(line);
	close(fd);
	fd = open(argv[ac - 1], O_RDONLY);
	if (fd < 0 || ret <= 0)
		return (0);
	if (!(test_tetri_valid(put_to_tab(tab, fd, ret, line), ret)))
		return (display_error("error"));
	close(fd);
	return (0);
}
