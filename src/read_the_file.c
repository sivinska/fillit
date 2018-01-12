/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_the_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:11:21 by sivinska          #+#    #+#             */
/*   Updated: 2018/01/11 11:04:31 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	file_verification(char *file)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (file[i] != '\0')
	{
		if (file[i] != '.' && file[i] != '\n' && file[i] != '#')
			ft_error();
		if (file[i] == '\n' && file[i + 1] == '\n' && file[i + 2] == '\n')
			ft_error();
		i++;
	}
	while (file[++j] != '\0')
	{
		if (j % 21 == 0)
		{
			if (file[j - 1] != '\n')
				ft_error();
		}
	}
}

char			*file_reading(char *file)
{
	int		fd;
	char	*buff;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error();
	buff = ft_strnew(BUFF_SIZE);
	if (read(fd, buff, BUFF_SIZE) < 0)
		ft_error();
	file_verification(buff);
	close(fd);
	return (buff);
}
