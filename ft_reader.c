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

char		**ft_reader(char *av)
{
	char		**str;
	int			fd;
	int			len;
	char		buf[BUF_SIZE + 1];

	len = 0;
	fd = open(av, O_RDONLY);
	len = read(fd, buf, BUF_SIZE);
	buf[len] = '\0';
	str = ft_strsplit(buf, '\n');
	close(fd);
	return (str);
}
