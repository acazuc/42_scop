/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create_identity.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:55:51 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 16:58:20 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_matrix	*matrix_create_identity()
{
	t_matrix	*matrix;

	if (!(matrix = malloc(sizeof(*matrix))))
		return (NULL);
	ft_bzero(matrix, sizeof(*matrix));
	matrix->value[0][0] = 1;
	matrix->value[1][1] = 1;
	matrix->value[2][2] = 1;
	matrix->value[3][3] = 1;
	return (matrix);
}
