/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:29:36 by gnegri            #+#    #+#             */
/*   Updated: 2017/12/04 14:29:53 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int			ft_check_read(int argc, char *argv, int *fd)
{
	if (argc < 1)
	{
		ft_putstr("usage: ./FdF input_file\n");
		return (0);
	}
	if ((*fd = open(argv, O_RDONLY)) < 0)
	{
		ft_putstr("error : bad_file\n");
		return (0);
	}
	if (BUFF_SIZE <= 0)
	{
		ft_putstr("error : BUFF_SIZE\n");
		return (0);
	}
	return (1);
}

int		ft_reader(int argc, char *argv, t_tools *tools)
{
	int		fd;
	char	*line;

	tools->str = ft_strnew(1);
	if (ft_check_read(argc, argv, &fd) == 0)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		tools->str = ft_strjoin(ft_strjoin(tools->str, line), "\n");
		tools->nb_line++;
	}
	tools->content = ft_strsplit(tools->str, '\n');
	if (get_next_line(fd, &line) < 0)
	{
		ft_putstr("error : get_next_line\n");
		free(tools->str);
		return (0);
	}
	tools->nb_char = ft_strlen(tools->str);
	if (close(fd) == -1)
	{
		ft_putstr("error : file\n");
		return (0);
	}
	return (1);
}
