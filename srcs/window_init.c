/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:17:52 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/16 15:27:01 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	window_init(t_env *env)
{
	if (!(env->window = malloc(sizeof(*env->window))))
		ERROR("Failed to malloc new window struct");
	env->window->width = 1280;
	env->window->height = 720;
	env->window->name = "acazuc's scop";
	if (!(env->window->mlx = mlx_init()))
		ERROR("Failed to init mlx");
	if (!(env->window->mlx_window = mlx_new_opengl_window(env->window->mlx
					, env->window->width, env->window->height
					, env->window->name)))
		ERROR("Failed to init mlx window");
}
