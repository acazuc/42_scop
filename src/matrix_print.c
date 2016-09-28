/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 17:59:23 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 18:10:55 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	matrix_print(t_matrix *matrix)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (matrix->value[y][x] < 0)
				ft_putchar('-');
			else
				ft_putchar(' ');
			ft_putnbr(abs((int)(matrix->value[y][x]) % 10));
			ft_putchar('.');
			ft_putnbr(abs((int)(matrix->value[y][x] * 100) % 100));
			if ((int)(matrix->value[y][x] * 100) % 100 < 10)
				ft_putchar(' ');
			if (x != 3)
				ft_putchar(' ');
			++x;
		}
		ft_putchar('\n');
		++y;
	}
}
