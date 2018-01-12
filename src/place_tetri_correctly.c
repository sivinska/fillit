/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetri_correctly.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:36:50 by sivinska          #+#    #+#             */
/*   Updated: 2018/01/11 11:44:09 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		tall(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int				place_tetri_correctly(char *table, char *tetri, int j, int i)
{
	int		size;
	int		k;

	size = tall(table);
	k = 0;
	if (i >= 0 && i <= 20 && j >= 0 && j <= ((size * size) + size - 1) &&
		table[j] == '.' && tetri[i] >= 'a' && tetri != NULL)
	{
		tetri[i] -= 32;
		table[j] = tetri[i];
		k++;
		k += place_tetri_correctly(table, tetri, j + 1, i + 1);
		k += place_tetri_correctly(table, tetri, j + (size + 1), i + 5);
		k += place_tetri_correctly(table, tetri, j - 1, i - 1);
		k += place_tetri_correctly(table, tetri, j - (size + 1), i - 5);
	}
	return (k);
}
