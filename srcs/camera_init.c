/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:29:43 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/16 15:32:06 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	camera_init(t_env *env)
{
	if (!(env->camera = malloc(sizeof(*env->camera))))
		ERROR("Failed to malloc camera struct");
	if (!(env->camera->position = malloc(sizeof(*env->camera->position))))
		ERROR("Failed to malloc camera position struct");
	if (!(env->camera->rotation = malloc(sizeof(*env->camera->rotation))))
		ERROR("Failed to malloc camera rotation struct");
	env->camera->position->x = 0;
	env->camera->position->y = 0;
	env->camera->position->z = 0;
	env->camera->rotation->x = 0;
	env->camera->rotation->y = 0;
	env->camera->rotation->z = 0;
}
