/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 08:06:32 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/02/02 12:48:49 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define SIZE 4

int						display_error(char *s);
int						test_tetri_valid(char ***tetri, int size);
char					**create_map(int size);
int						solve_fillit(char ***tetri, char ***map, char lettre,
		int size);
int						free_one_array(char **tmp, int error_level);
char					***free_two_array(char ***tab);
char					***free_three_array(char ***tab);
void					remove_lettre(char ***map, char lettre, int size);
void					replace_map(char ***map, char lettre);
char					**create_map(int size);
char					**calcul_map(int map_size, int size, char **map);

#endif
