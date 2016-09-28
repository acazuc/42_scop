/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_read_mtllib_read_ks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:38:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 13:45:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	obj_read_mtllib_read_ks(t_obj *obj, char *line)
{
	char	**datas;

	if (!(datas = ft_strsplit(line, ' ')))
		ERROR("ft_strsplit failed");
	if (!datas[0] || !datas[1] || !datas[2] || !datas[3] || datas[4])
		ERROR("invalid mtllib ks line");
	if (!parse_valid_number(datas[1]) || !parse_valid_number(datas[2])
			|| !parse_valid_number(datas[3]))
		ERROR("invalid mtllib ks values");
	if (!obj->current_mtl)
		ERROR("no current mtl for Ks values");
	obj->current_mtl->mtl.ksr = ft_atod(datas[1]);
	obj->current_mtl->mtl.ksg = ft_atod(datas[2]);
	obj->current_mtl->mtl.ksb = ft_atod(datas[3]);
	if (obj->current_mtl->mtl.ksr < 0 || obj->current_mtl->mtl.ksr > 1)
		ERROR("mtl Ks values must be between 0 and 1");
	if (obj->current_mtl->mtl.ksg < 0 || obj->current_mtl->mtl.ksg > 1)
		ERROR("mtl Ks values must be between 0 and 1");
	if (obj->current_mtl->mtl.ksb < 0 || obj->current_mtl->mtl.ksb > 1)
		ERROR("mtl Ks values must be between 0 and 1");
	free_array(datas);
}
