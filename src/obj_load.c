/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:50:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/27 17:15:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	obj_load(t_env *env, char *file)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		ERROR("Failed to open file");
	obj_read(&env->obj, fd);
	close(fd);
}
