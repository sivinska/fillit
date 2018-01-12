/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_empty_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:19:29 by gkuraite          #+#    #+#             */
/*   Updated: 2018/01/11 11:43:47 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	create_empty_table(char *table, int size)
{
	int		i;

	i = 0;
	while (i < (size * size) + size)
	{
		table[i] = '.';
		if (i > 0 && (i + 1) % (size + 1) == 0)
			table[i] = '\n';
		i++;
	}
}

char	*malloc_empty_table(char *table, int size)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = NULL;
	str = ft_strnew((size * size) + size);
	create_empty_table(str, size);
	while (table[i])
	{
		if (table[i] != '\n')
			str[j] = table[i];
		else if (table[i] == '\n')
		{
			str[j] = '.';
			j++;
			str[j] = table[i];
		}
		i++;
		j++;
	}
	free(table);
	return (str);
}
