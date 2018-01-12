/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_tetrimonos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:31:44 by sivinska          #+#    #+#             */
/*   Updated: 2018/01/08 10:28:23 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		correct_tetrimonos(char *tetri, char tetri_nb, int i)
{
	int		good;

	good = 0;
	if (tetri[i] == '#' && i >= 0 && i <= 20 && good <= 4)
	{
		good++;
		tetri[i] = tetri_nb + 'a';
		good += correct_tetrimonos(tetri, tetri_nb, i + 1);
		good += correct_tetrimonos(tetri, tetri_nb, i - 1);
		good += correct_tetrimonos(tetri, tetri_nb, i + 5);
		good += correct_tetrimonos(tetri, tetri_nb, i - 5);
	}
	return (good);
}
