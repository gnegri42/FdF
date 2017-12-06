/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:55:11 by gnegri            #+#    #+#             */
/*   Updated: 2017/12/06 11:55:13 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_atoi_fdf(const char *str, int *i)
{
	int v;
	int posneg;

	v = 0;
	posneg = 1;
	while (str[*i] == '\n' || str[*i] == '\t' || str[*i] == '\v' ||
			str[*i] == '\r' || str[*i] == '\f' || str[*i] == ' ')
		(*i)++;
	if (str[*i] == '-')
		posneg = -1;
	if (str[*i] == '+' || str[*i] == '-')
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		v = v * 10 + str[*i] - 48;
		(*i)++;
	}
	return (posneg * v);
}
