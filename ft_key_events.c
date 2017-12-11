/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 10:26:36 by gnegri            #+#    #+#             */
/*   Updated: 2017/12/08 10:26:38 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int				ft_expose_hook(t_mlx *mlx)
{
	int			x;
	int			y;

	x = 30;
	y = 40;
	while (x <= 180)
		mlx_pixel_put(mlx->mlx, mlx->win, x++, y, WHITE);
	while (y <= 120)
		mlx_pixel_put(mlx->mlx, mlx->win, x, y++, WHITE);
	while (x >= 30)
		mlx_pixel_put(mlx->mlx, mlx->win, x--, y, WHITE);
	while (y >= 40)
		mlx_pixel_put(mlx->mlx, mlx->win, x, y--, WHITE);
	mlx_string_put(mlx->mlx, mlx->win, 38, 38, WHITE, "Quit = ESC");
	mlx_string_put(mlx->mlx, mlx->win, 38, 58, WHITE, "Move = ^ v < >");
	mlx_string_put(mlx->mlx, mlx->win, 38, 78, WHITE, "Zoom = w s");
	mlx_string_put(mlx->mlx, mlx->win, 38, 98, WHITE, "Up Down = e d");
	ft_draw(mlx->point, *mlx->tools, *mlx);
	return (0);
}

static int		ft_zoom_in_out(int keycode, t_mlx *mlx)
{
	if (keycode == 13 && ((mlx->point->zoom) * 2 < 1000))
	{
		mlx->point->zoom = mlx->point->zoom * 2;
		mlx_clear_window(mlx->mlx, mlx->win);
		ft_expose_hook(mlx);
	}
	else if (keycode == 1 && ((mlx->point->zoom) / 2 > 1))
	{
		mlx->point->zoom = mlx->point->zoom / 2;
		mlx_clear_window(mlx->mlx, mlx->win);
		ft_expose_hook(mlx);
	}
	return (0);
}

static int		ft_move(int keycode, t_mlx *mlx)
{
	if (keycode == 123)
	{
		mlx->point->x_move = mlx->point->x_move * 1.2;
		mlx_clear_window(mlx->mlx, mlx->win);
		ft_expose_hook(mlx);
	}
	else if (keycode == 124)
	{
		mlx->point->x_move = mlx->point->x_move / 1.2;
		mlx_clear_window(mlx->mlx, mlx->win);
		ft_expose_hook(mlx);
	}
	else if (keycode == 125)
	{
		mlx->point->y_move = mlx->point->y_move / 1.2;
		mlx_clear_window(mlx->mlx, mlx->win);
		ft_expose_hook(mlx);
	}
	else if (keycode == 126)
	{
		mlx->point->y_move = mlx->point->y_move * 1.2;
		mlx_clear_window(mlx->mlx, mlx->win);
		ft_expose_hook(mlx);
	}
	return (0);
}

static int		ft_zoom_up_down(int keycode, t_mlx *mlx)
{
	if (keycode == 2)
	{
		mlx->point->z = mlx->point->z + 1;
		mlx_clear_window(mlx->mlx, mlx->win);
		ft_expose_hook(mlx);
	}
	else if (keycode == 14 && (mlx->point->z - 1) > 0)
	{
		mlx->point->z = mlx->point->z - 1;
		mlx_clear_window(mlx->mlx, mlx->win);
		ft_expose_hook(mlx);
	}
	return (0);
}

int				ft_key_events(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 13 || keycode == 1)
		ft_zoom_in_out(keycode, mlx);
	if (keycode == 2 || keycode == 14)
		ft_zoom_up_down(keycode, mlx);
	if (keycode == 123 || keycode == 124 || keycode == 125
	|| keycode == 126)
		ft_move(keycode, mlx);
	return (0);
}
