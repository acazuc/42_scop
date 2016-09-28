/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 18:53:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 19:17:27 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_matrix	*matrix_create()
{
	t_matrix	*matrix;
	float		*tmp;

	ft_putendl("a");
	if (!(matrix = malloc(sizeof(*matrix))))
		return (NULL);
	ft_memset(matrix, 0, sizeof(*matrix));
	if (!(matrix->value = malloc(sizeof(*matrix->value)* 4)))
	{
		free(matrix);
		return (NULL);
	}
	if (!(tmp = malloc(sizeof(*tmp) * 4 * 4)))
	{
		free(matrix->value);
		free(matrix);
		return (NULL);
	}
	matrix->value[0] = &tmp[0];
	matrix->value[1] = &tmp[4];
	matrix->value[2] = &tmp[8];
	matrix->value[3] = &tmp[12];
	ft_memset(tmp, 0, sizeof(*tmp) * 4 * 4);
	return (matrix);
}
