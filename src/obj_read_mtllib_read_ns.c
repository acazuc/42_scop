/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_read_mtllib_read_ns.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:49:08 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 14:23:59 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	obj_read_mtllib_read_ns(t_obj *obj, char *line)
{
	char	**datas;

	if (!(datas = ft_strsplit(line, ' ')))
		ERROR("ft_strsplit failed");
	if (!datas[0] || !datas[1] || datas[2])
		ERROR("invalid mtl ns line");
	if (!parse_valid_number(datas[1]))
		ERROR("invalid mtl ns value");
	if (!obj->current_mtl)
		ERROR("no current mtl for ns value");
	obj->current_mtl->mtl.ns = ft_atod(datas[1]);
	free_array(datas);
}
