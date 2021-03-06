/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_read_mtllib_read_ka.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:27:53 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 13:44:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	obj_read_mtllib_read_ka(t_obj *obj, char *line)
{
	char	**datas;
	
	if (!(datas = ft_strsplit(line, ' ')))
		ERROR("ft_strsplit failed");
	if (!datas[0] || !datas[1] || !datas[2] || !datas[3] || datas[4])
		ERROR("invalid mtl ka line");
	if (!parse_valid_number(datas[1]) || !parse_valid_number(datas[2])
			|| !parse_valid_number(datas[3]))
		ERROR("invalid mtl ka values");
	if (!obj->current_mtl)
		ERROR("no current mtl for Ka value");
	obj->current_mtl->mtl.kar = ft_atod(datas[1]);
	obj->current_mtl->mtl.kag = ft_atod(datas[2]);
	obj->current_mtl->mtl.kab = ft_atod(datas[3]);
	if (obj->current_mtl->mtl.kar < 0 || obj->current_mtl->mtl.kar > 1)
		ERROR("mtl Kd values must be between 0 and 1");
	if (obj->current_mtl->mtl.kag < 0 || obj->current_mtl->mtl.kag > 1)
		ERROR("mtl Kd values must be between 0 and 1");
	if (obj->current_mtl->mtl.kab < 0 || obj->current_mtl->mtl.kab > 1)
		ERROR("mtl Kd values must be between 0 and 1");
	free_array(datas);
}
