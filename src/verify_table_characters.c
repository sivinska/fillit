/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_table_characters.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:23:57 by sivinska          #+#    #+#             */
/*   Updated: 2018/01/11 11:04:02 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		verify_table_characters(char *tetri, int tetri_nb)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (tetri[i] != '\0')
	{
		if (i % 5 == 4 && tetri[i] != '\n')
			ft_error();
		if (tetri[i] == '.')
			k++;
		if (tetri[i] == '#')
			j = correct_tetrimonos(tetri, tetri_nb, i);
		i++;
	}
	if (i != 19 || j != 4 || k != 12)
		ft_error();
	return (1);
}

char	*tetri_verif(char *tetri, int tetri_nb)
{
	if (verify_table_characters(tetri, tetri_nb) == 1)
		return (tetri);
	ft_error();
	return (NULL);
}
