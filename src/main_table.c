/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:49:41 by sivinska          #+#    #+#             */
/*   Updated: 2018/01/11 11:43:31 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	main_table(char **tetri, int tetri_nb)
{
	char	*table;
	int		size;

	size = find_min_square(tetri_nb + 1);
	table = ft_strnew((size * size) + size);
	create_empty_table(table, size);
	while (!final_table(&table, tetri, 0, size))
	{
		table = malloc_empty_table(table, ++size);
	}
	show_table(table);
	free(table);
}
