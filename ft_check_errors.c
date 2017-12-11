/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:26:41 by gnegri            #+#    #+#             */
/*   Updated: 2017/12/07 12:26:42 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_start_error(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != ' ')
		{
			ft_putstr("lines must start by a digit or space : ");
			return (-1);
		}
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		i++;
	}
	return (1);
}

static int	ft_invalid(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] == '-' && (str[i + 1] < '0' || str[i + 1] > '9'))
		{
			ft_putstr(
					"'-' must be followed only by a digit : ");
			return (-1);
		}
		if (str[i] != '-' && str[i] != ' ' && str[i] != '\n'
			&& !(str[i] >= '0' && str[i] <= '9'))
		{
			ft_putstr("bad character in file : ");
			return (-1);
		}
		i++;
	}
	return (1);
}

int			ft_check_errors(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '\0')
	{
		ft_putstr("file is empty : ");
		return (0);
	}
	while (str[i] != '\0')
		i++;
	if (ft_start_error(str) == -1 || ft_invalid(str, 0) == -1)
		return (0);
	return (1);
}
