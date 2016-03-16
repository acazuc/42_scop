/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:50:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/16 16:23:30 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	obj_load(t_env *env, char *file)
{
	int		fd;

	if (!(env->obj = malloc(sizeof(*env->obj))))
		ERROR("Failed to malloc obj struct");
	env->obj->points = NULL;
	env->obj->faces = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		ERROR("Failed to open file");
	read_obj(en->obj, fd);
	close(fd);
}
