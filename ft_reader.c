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

int			**ft_new_tab(char *buff, int nb_line, int nb_char)
{
	int		i;
	int		j;
	int		k;
	int		**tab;

	j = 0;
	k = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * nb_line)))
		return (NULL);
	while (buff[k] != '\0' && j < nb_line)
	{
		i = 0;
		if (!(tab[j] = (int *)malloc(sizeof(int) * nb_char)))
			return (NULL);
		while (buff[k] != '\n' && buff[k] != '\0' && j < nb_line)
		{
			tab[j][i++] = ft_atoi_fdf(buff, &k);
			while (buff[k] == ' ')
				k++;
		}
		k++;
		j++;
	}
	return (tab);
}

t_fdf		ft_struct(char *buff, int nb_line, int nb_char)
{
	t_fdf	mlx;

	mlx.z = 2.0;
	mlx.x_move = 0;
	mlx.y_move = 0;
	mlx.tab = ft_new_tab(buff, nb_line, nb_char);
	mlx.nb_line = nb_line;
	mlx.nb_char = nb_char;
	if (mlx.nb_line >= mlx.nb_char)
		mlx.def_zoom = 400 / mlx.nb_line;
	else
		mlx.def_zoom = 400 / mlx.nb_char;
	return (mlx);
}

int			ft_check_error(int argc, char *argv, int *fd)
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

int		ft_reader(int argc, char *argv, t_fdf *mlx)
{
	int		fd;
	int		nb_line;
	int		nb_char;
	char	*line;
	char	*buff;

	nb_line = 0;
	buff = ft_strnew(1);
	if (ft_check_error(argc, argv, &fd) == 0)
		return (0);
	while (get_next_line(fd, &line) > 0 && nb_line++)
		buff = ft_strjoin(ft_strjoin(buff, line), "\n");
	if (get_next_line(fd, &line) < 0)
	{
		ft_putstr("error : get_next_line\n");
		free(buff);
		return (0);
	}
	if (close(fd) == -1)
	{
		ft_putstr("error : file\n");
		return (0);
	}
	if ((nb_char = ft_strlen(buff)) != 0)
		*mlx = ft_struct(buff, nb_line, nb_char);
	return (0);
}
