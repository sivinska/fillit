/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_reset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:25:05 by sivinska          #+#    #+#             */
/*   Updated: 2018/01/11 11:45:04 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	reset_table(char *table, char *tetri, int i, int j)
{
	while (table[i])
	{
		if (table[i] == ('A' + j))
			table[i] = '.';
		i++;
	}
	i = 0;
	while (tetri[i])
	{
		if (tetri[i] == ('A' + j))
			tetri[i] += 32;
		i++;
	}
}
