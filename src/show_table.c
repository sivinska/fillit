/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:28:39 by gkuraite          #+#    #+#             */
/*   Updated: 2017/12/15 16:29:40 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	show_table(char *table)
{
	write(1, table, ft_strlen(table));
}
