/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create_translation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:57:29 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 17:01:48 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_matrix	*matrix_create_translation(double x, double y, double z)
{
	t_matrix	*matrix;

	if (!(matrix = malloc(sizeof(*matrix))))
		return (NULL);
	ft_bzero(matrix, sizeof(*matrix));
	matrix->value[0][0] = 1;
	matrix->value[1][1] = 1;
	matrix->value[2][2] = 1;
	matrix->value[3][3] = 1;
	matrix->value[0][3] = x;
	matrix->value[1][3] = y;
	matrix->value[2][3] = z;
	return (matrix);
}
