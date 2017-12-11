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

static int			ft_strlen_fdf(char *str)
{
	int		i;
	int		nb_int;

	i = 0;
	nb_int = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '-')
			i++;
		if (ft_isdigit(str[i]) == 1)
		{
			nb_int++;
			i++;
			while (ft_isdigit(str[i]) == 1)
				i++;
		}
	}
	return (nb_int);
}

static int			ft_verif_int_nb(t_tools *tools)
{
	char	*str;
	int		l;
	int		c;

	l = 0;
	while (l < tools->nb_line - 1)
	{
		c = ft_strlen_fdf(tools->content[l]);
		if (ft_strlen_fdf(tools->content[l + 1]) != c)
			return (0);
		l++;
	}
	return (1);
}

static int			ft_verifs(int fd, t_tools *tools, char *line)
{
	if (get_next_line(fd, &line) < 0)
	{
		ft_putstr("get_next_line : error\n");
		free(tools->content);
		free(tools->str);
		return (0);
	}
	if (close(fd) == -1 || ft_check_errors(tools->str) != 1 ||
		ft_verif_int_nb(tools) != 1)
	{
		ft_putstr("error\n");
		free(tools->content);
		free(tools->str);
		return (0);
	}
	return (1);
}

static int			ft_check_read(int argc, char *argv, int *fd)
{
	if (argc < 2)
	{
		ft_putstr("usage: ./fdf input_file\n");
		return (0);
	}
	if ((*fd = open(argv, O_RDONLY)) < 0)
	{
		ft_putstr("bad_file : error\n");
		return (0);
	}
	if (BUFF_SIZE <= 0)
	{
		ft_putstr("BUFF_SIZE : error\n");
		return (0);
	}
	return (1);
}

int					ft_reader(int argc, char *argv, t_tools *tools)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*tmp2;

	tools->str = ft_strnew(1);
	if (ft_check_read(argc, argv, &fd) == 0)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = tools->str;
		tmp2 = ft_strjoin(tmp, line);
		tools->str = ft_strjoin(tmp2, "\n");
		free(tmp);
		free(tmp2);
		tools->nb_line++;
		free(line);
	}
	tools->content = ft_strsplit(tools->str, '\n');
	if (ft_verifs(fd, tools, line) == 0)
		return (0);
	tools->nb_int = ft_strlen_fdf(tools->content[0]);
	return (1);
}
