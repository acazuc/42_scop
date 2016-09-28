/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 17:38:29 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 19:16:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static double		matrix_mult_path(t_matrix *m1, t_matrix *m2, int x, int y)
{
	return (m1->value[y][0] * m2->value[0][x]
			+ m1->value[y][1] * m2->value[1][x]
			+ m1->value[y][2] * m2->value[2][x]
			+ m1->value[y][3] * m2->value[3][x]);
}

void				matrix_mult(t_matrix *m1, t_matrix *m2)
{
	float		new[4][4];
	int			x;
	int			y;

	ft_bzero(new, sizeof(new));
	y = -1;
	while (y < 4)
	{
		x = -1;
		while (++x < 4)
			new[y][x] = matrix_mult_path(m1, m2, x, y);
	}
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			m1->value[y][x] = new[y][x];
	}
}
