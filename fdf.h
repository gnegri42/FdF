/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:00:03 by gnegri            #+#    #+#             */
/*   Updated: 2017/12/11 16:00:13 by gnegri           ###   ########.fr       */
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

# define BLUE 0x1E90FF
# define WHITE 0xFFFFFF
# define GREEN 0x25FF50
# define ORANGE 0x00FFA500
# define YELLOW 0xFFFF66

typedef struct		s_point
{
	int				**tab;
	int				length;
	double			z;
	int				x;
	int				y;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				zoom;
	int				x_move;
	int				y_move;
}					t_point;

typedef struct		s_tools
{
	int				nb_line;
	int				nb_int;
	char			*str;
	char			**content;

}					t_tools;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_point			*point;
	t_tools			*tools;

}					t_mlx;

int					ft_reader(int argc, char *argv, t_tools *tools);
int					ft_atoi_fdf(const char *str, int *c);
void				ft_draw(t_point *point, t_tools tools, t_mlx mlx);
int					ft_check_errors(char *str);
int					ft_key_events(int keycode, t_mlx *mlx);
int					ft_expose_hook(t_mlx *mlx);

#endif
