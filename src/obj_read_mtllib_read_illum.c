/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_read_mtllib_read_illum.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:17:59 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 14:22:05 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	obj_read_mtllib_read_illum(t_obj *obj, char *line)
{
	char	**datas;

	if (!(datas = ft_strsplit(line, ' ')))
		ERROR("ft_strsplit failed");
	if (!datas[0] || !datas[1] || datas[2])
		ERROR("invalid mtl illum line");
	if (!(ft_strisdigit(datas[1])))
		ERROR("invalid mtl illum value");
	if (!obj->current_mtl)
		ERROR("no current mtl for illum");
	obj->current_mtl->mtl.illum = ft_atoi(datas[1]);
	if (obj->current_mtl->mtl.illum < 0 || obj->current_mtl->mtl.illum > 10)
		ERROR("invalid mtl illum value");
	free_array(datas);
}
