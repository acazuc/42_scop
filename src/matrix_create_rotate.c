/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 17:02:41 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 17:17:00 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_matrix	*matrix_create_rotate_x(double angle)
{
	t_matrix	*matrix;

	if (!(matrix = malloc(sizeof(*matrix))))
		return (NULL);
	ft_bzero(matrix, sizeof(*matrix));
	matrix->value[0][0] = 1;
	matrix->value[1][1] = cos(angle);
	matrix->value[1][2] = -sin(angle);
	matrix->value[2][1] = sin(angle);
	matrix->value[2][2] = cos(angle);
	matrix->value[3][3] = 1;
	return (matrix);
}

t_matrix	*matrix_create_rotate_y(double angle)
{
	t_matrix	*matrix;

	if (!(matrix = malloc(sizeof(*matrix))))
		return (NULL);
	ft_bzero(matrix, sizeof(*matrix));
	matrix->value[0][0] = cos(angle);
	matrix->value[0][2] = -sin(angle);
	matrix->value[1][1] = 1;
	matrix->value[2][0] = -sin(angle);
	matrix->value[2][2] = cos(angle);
	matrix->value[3][3] = 1;
	return (matrix);
}

t_matrix	*matrix_create_rotate_z(double angle)
{
	t_matrix	*matrix;

	if (!(matrix = malloc(sizeof(*matrix))))
		return (NULL);
	ft_bzero(matrix, sizeof(*matrix));
	matrix->value[0][0] = cos(angle);
	matrix->value[0][1] = -sin(angle);
	matrix->value[1][0] = sin(angle);
	matrix->value[1][1] = cos(angle);
	matrix->value[2][2] = 1;
	matrix->value[3][3] = 1;
	return (matrix);
}
