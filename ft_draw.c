/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:41:29 by gnegri            #+#    #+#             */
/*   Updated: 2017/12/06 11:41:34 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
/*
static void	ft_draw_line(t_mlx mlx, t_point *point)
{
	double	tx;
	float	dx;
	float	dy;

	tx = 0.0;
	dx = point->x2 - point->x1;
	dy = point->y2 - point->y1;
	while (tx <= 1)
	{
	point->x = point->x1 + (dx * tx);
	point->y = point->y1 + (dy * tx);
	mlx_pixel_put(mlx.mlx, mlx.win, point->x + point->x_move,\
	point->y + point->y_move, ORANGE);
	tx += 1. / sqrt((dx * dx) + (dy * dy));
	}
}

void	ft_horiz(t_mlx mlx, t_point *point, int x, int y)
{
	point->x1 = 50 + (x * point->def_zoom) + (y * point->def_zoom);
	point->x2 = 50 + ((x + 1) * point->def_zoom) + (y * point->def_zoom);
	point->y1 = ((700 + (y * point->def_zoom)) * 1. / 2.) - (((x * point->def_zoom)
				+ (point->z * point->tab[y][x])) * 1. / 2.);
	point->y2 = ((700 + (y * point->def_zoom)) * 1. / 2.) - ((((x + 1) * point->def_zoom)
				+ (point->z * point->tab[y][x + 1])) * 1. / 2.);
	ft_draw_line(mlx, point);
}

void	ft_vert(t_mlx mlx, t_point *point, int x, int y)
{
	point->x1 = 50 + (x * point->def_zoom) + (y * point->def_zoom);
	point->x2 = 50 + (x * point->def_zoom) + ((y + 1) * point->def_zoom);
	point->y1 = ((700 + (y * point->def_zoom)) * 1. / 2.) - (((x * point->def_zoom)
				+ (point->z * point->tab[y][x])) * 1. / 2.);
	point->y2 = ((700 + ((y + 1) * point->def_zoom)) * 1. / 2.) - (((x * point->def_zoom)
				+ (point->z * point->tab[y + 1][x])) * 1. / 2.);
	ft_draw_line(mlx, point);
}
*/

void ft_draw_line(t_mlx mlx, int x1, int y1, int x2,int y2, int ymin, int ymax)
{

	double	tx;
	float	dx;
	float	dy;
	double	x;
	double	y;

	tx = 0.0;
	dx = (float) x2 - x1;
	dy = (float) y2 - y1;
	while (tx <= 1)
	{
		x = x1 + (dx * tx);
		y = y1 + (dy * tx);
		mlx_pixel_put(mlx.mlx, mlx.win, x, y, ORANGE);
		tx += 1. / sqrt((dx * dx) + (dy * dy));
	}
}

void ft_pos(int i, int j, int z, int* outx, int* outy)
{
	int startx;
	int	starty;
	int pas = WIN_WIDTH / 35;
	startx = WIN_WIDTH / 3;
	starty = WIN_HEIGHT / 2;
	*outx = startx + (i * pas) - (j * pas);
	*outy = starty + (i * pas / 4) + (j * pas / 4) - (z * 20);
}

void	ft_segment(t_mlx mlx, int xmin,int ymin,int xmax,int ymax, int z1, int z2)
{
	int imin;
	int jmin;
	int imax;
	int jmax;

	ft_pos(xmin, ymin, z1, &imin, &jmin);
	ft_pos(xmax, ymax, z2, &imax, &jmax);
	ft_draw_line(mlx, imin, jmin, imax, jmax, ymin, ymax);
}

void	ft_draw(t_point *point, t_tools tools, t_mlx mlx)
{
	int i;
	int y;
	int x;
	int	z1;
	int z2;
	int z3;

	y = 0;
	while (tools.content[y] != 0)
	{
		i = 0;
		while (tools.content[y][i] != '\0')
		{
			if (tools.content[y][i] != ' ')
			{
				while (ft_isdigit(tools.content[y][i + 1]) == 1)
					i++;
				if (tools.content[y][i + 1] != '\0')
				{
					z1 = ft_atoi(&tools.content[y][i]);
					z2 = ft_atoi(&tools.content[y][i + 2]);
					ft_segment(mlx, x, y, x+1, y, z1, z2);
					//printf("%d\n", point->tab[y][i]);
				}
				//	ft_horiz(mlx, point, x, y);
				if (tools.content[y + 1] != 0)
				//	ft_vert(mlx, point, x, y);
					z3 = ft_atoi(&tools.content[y + 1][i]);
					ft_segment(mlx, x, y, x, y+1, z1, z3);
			}
			i++;
		}
		y++;
	}

}
