/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create_scale.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 17:00:32 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 17:02:28 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_matrix	*matrix_create_scale(double scale)
{
	t_matrix	*matrix;

	if (!(matrix = malloc(sizeof(*matrix))))
		return (NULL);
	ft_bzero(matrix, sizeof(*matrix));
	matrix->value[0][0] = scale;
	matrix->value[1][1] = scale;
	matrix->value[2][2] = scale;
	matrix->value[3][3] = 1;
	return (matrix);
}
