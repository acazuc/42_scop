/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_read_mtllib_read_kd.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:38:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 13:43:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	obj_read_mtllib_read_kd(t_obj *obj, char *line)
{
	char	**datas;

	if (!(datas = ft_strsplit(line, ' ')))
		ERROR("ft_strsplit failed");
	if (!datas[0] || !datas[1] || !datas[2] || !datas[3] || datas[4])
		ERROR("invalid mtllib kd line");
	if (!parse_valid_number(datas[1]) || !parse_valid_number(datas[2])
			|| !parse_valid_number(datas[3]))
		ERROR("invalid mtllib kd values");
	if (!obj->current_mtl)
		ERROR("no current mtl for Kd values");
	obj->current_mtl->mtl.kdr = ft_atod(datas[1]);
	obj->current_mtl->mtl.kdg = ft_atod(datas[2]);
	obj->current_mtl->mtl.kdb = ft_atod(datas[3]);
	if (obj->current_mtl->mtl.kdr < 0 || obj->current_mtl->mtl.kdr > 1)
		ERROR("mtl Kd values must be between 0 and 1");
	if (obj->current_mtl->mtl.kdg < 0 || obj->current_mtl->mtl.kdg > 1)
		ERROR("mtl Kd values must be between 0 and 1");
	if (obj->current_mtl->mtl.kdb < 0 || obj->current_mtl->mtl.kdb > 1)
		ERROR("mtl Kd values must be between 0 and 1");
	free_array(datas);
}
