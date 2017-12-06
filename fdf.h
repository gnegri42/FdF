/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:17:41 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/01 12:06:15 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include "libft/libft.h"
# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>

# define WIN_WIDTH	1200
# define WIN_HEIGHT	1200

# define BLUE 0x0041FF
# define WHITE 0xFFFFFF
# define GREEN 0x25FF50
# define ORANGE 0x00FFA500

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	int				**tab;
	int				nb_line;
	int				nb_char;
	int				length;
	double			x;
	double			y;
	double			z;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				def_zoom;
	int				x_move;
	int				y_move;
}					t_fdf;

int				ft_reader(int argc, char *argv, t_fdf *mlx);
int				ft_atoi_fdf(const char *str, int *i);

#endif
