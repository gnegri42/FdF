/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:48:20 by gnegri            #+#    #+#             */
/*   Updated: 2017/12/06 14:48:22 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
int     ft_escape(int keycode, void *param)
{
    if (keycode == 53)
        exit(1);
    return (0);
}

int         **ft_new_tab(char *buff, int nb_line, int nb_char)
{
    int     i;
    int     j;
    int     k;
    int     **tab;

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




void	ft_init_struct(t_tools tools, t_mlx *mlx, t_point *point)
{
	ft_struct(tools.str, tools.nb_line, tools.nb_char, point);
}
*/