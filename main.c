/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:51:30 by gnegri            #+#    #+#             */
/*   Updated: 2017/12/06 15:51:31 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int         **ft_new_tab(char **content, char *str, int nb_line, int nb_char)
{
    int     i;
    int     j;
    int     k;
    int		c;
    int     **tab;

    j = 0;
    k = 0;
    if (!(tab = (int **)malloc(sizeof(int *) * nb_line)))
        return (NULL);
    while (content[j] != 0)
    {
        i = 0;
        if (!(tab[j] = (int *)malloc(sizeof(int) * (ft_strlen(content[1]) / 2 + 1))))
            return (NULL);
        while (content[j][i] != '\0')
        {
            //tab[j][k] = ft_atoi_fdf(str, &c);
            while (content[j][i] == ' ')
            {
                i++;
                c++;
            }
            i++;
            k++;
        }
        c++;
        j++;
    }
    return (tab);
}

t_point		ft_init(char **content, char *str, int nb_line, int nb_char)
{
    t_point point;
    
    point.z = 2.0;
    point.tab = ft_new_tab(content, str, nb_line, nb_char);
    if (nb_line >= nb_char)
        point.def_zoom = 400 / nb_line;
    else
        point.def_zoom = 400 / nb_char;
    return (point);
}

int     ft_escape(int keycode, void *param)
{
    if (keycode == 53)
        exit(1);
    return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;
	t_tools	tools;
	t_point	point;

	int i;
	int j;

	i = 0;
	j = 0;

	tools.nb_line = 0;
	ft_reader(argc, argv[1], &tools);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "win fdf");
	point = ft_init(tools.content, tools.str, tools.nb_line, tools.nb_char);
	/*while (tools.content[j] != 0)
	{
		i = 0;
		while (tools.content[j][i] != '\0')
		{
			printf("%d", point.tab[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}*/
	ft_draw(&point, tools, mlx);
	mlx_key_hook(mlx.win, ft_escape, 0);
	mlx_loop(mlx.mlx);
	return 0;
}
