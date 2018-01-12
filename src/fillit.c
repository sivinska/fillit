/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 10:11:13 by sivinska          #+#    #+#             */
/*   Updated: 2018/01/11 12:17:17 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_freetab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	free_everything(char **tetris, char *in_file, int j)
{
	tetris[j + 1] = NULL;
	free(in_file);
	main_table(tetris, j);
	ft_freetab(tetris);
}

static void	*malloc_all(char **tetris, char *in_file, int j, int i)
{
	if (in_file[i] == '\0')
	{
		if (ft_strlen(in_file) == 20)
			tetris[j] =
				ft_strdup(tetri_verif(ft_strsub(in_file, i - 21, 19), j));
		else
			tetris[j] =
				ft_strdup(tetri_verif(ft_strsub(in_file, i - 20, 19), j));
	}
	return (tetris[j]);
}

void		fillit(char *file)
{
	char	*in_file;
	char	**tetris;
	int		i;
	int		j;

	i = 20;
	j = 0;
	in_file = file_reading(file);
	tetris = (char**)malloc(sizeof(char*) * 26);
	if (tetris == NULL)
		ft_error();
	while (in_file[++i] != '\0')
	{
		if (i % 21 == 0)
		{
			tetris[j] =
				ft_strdup(tetri_verif(ft_strsub(in_file, i - 21, 19), j));
			j++;
		}
	}
	tetris[j] = malloc_all(tetris, in_file, j, i);
	free_everything(tetris, in_file, j);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
		fillit(argv[1]);
	else
		usage();
	return (0);
}
