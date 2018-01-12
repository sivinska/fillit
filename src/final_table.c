/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:33:53 by sivinska          #+#    #+#             */
/*   Updated: 2018/01/11 11:44:52 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		final_table(char **table, char **tetri, int i, int size)
{
	int		in[2];
	char	*table2;

	if (tetri[i] == NULL)
		return (1);
	table2 = ft_strdup(*table);
	in[0] = 0;
	in[1] = 0;
	while ((*table)[in[0]])
	{
		while (!ft_isalpha(tetri[i][in[1]]))
			in[1]++;
		if (place_tetri_correctly(*table, tetri[i], in[0], in[1]) != 4)
		{
			in[1] = 0;
			reset_table(*table, tetri[i], in[0]++, i);
			continue;
		}
		if (final_table(table, tetri, i + 1, size))
			return (1);
		free(*table);
		*table = ft_strdup(table2);
	}
	free(table2);
	return (0);
}
