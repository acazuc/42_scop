/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create_projection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 17:12:07 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 18:58:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_matrix	*matrix_create_projection(double fov_o, double ratio, double near, double far)
{
	t_matrix	*matrix;
	double		fov;

	if (!(matrix = matrix_create()))
		return (NULL);
	fov = 1 / tan(fov_o / 2);
	matrix->value[0][0] = fov / ratio;
	matrix->value[1][1] = fov;
	matrix->value[2][2] = -(far + near) / (far - near);
	matrix->value[3][2] = -1;
	matrix->value[2][3] = (2 * near * far) / (near - far);
	return (matrix);
}
