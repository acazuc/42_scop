/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 17:59:23 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 18:02:15 by acazuc           ###   ########.fr       */
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
			ft_putnbr((int)(matrix->value[y][x]) % 10);
			ft_putnbr((int)(matrix->value[y][x] * 100) % 1000);
			if (x != 3)
				ft_putchar(' ');
			++x;
		}
		ft_putchar('\n');
		++y;
	}
}
