/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:36:38 by gkuraite          #+#    #+#             */
/*   Updated: 2018/01/02 18:29:57 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_min_square(int nb_tetriminos)
{
	int		size;

	size = 2;
	while ((nb_tetriminos * 4) > (size * size))
		size++;
	return (size);
}
