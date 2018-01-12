/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:31:27 by gkuraite          #+#    #+#             */
/*   Updated: 2018/01/11 11:59:45 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 546

int		find_min_square(int nb_tetriminos);
char	*file_reading(char *file);
void	create_empty_table(char *table, int size);
char	*malloc_empty_table(char *table, int size);
void	show_table(char *table);
int		correct_tetrimonos(char *tetri, char tetri_nb, int i);
int		final_table(char **table, char **tetri, int i, int size);
void	main_table(char **tetri, int tetri_nb);
int		place_tetri_correctly(char *table, char *tetri, int j, int i);
void	reset_table(char *table, char *tetri, int i, int j);
int		verifify_table_characters(char *tetri, int tetri_nb);
char	*tetri_verif(char *tetri, int i);
void	ft_error(void);
void	fillit(char *file);
int		main(int argc, char **argv);
void	usage(void);

#endif
