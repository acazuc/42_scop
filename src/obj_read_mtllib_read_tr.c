/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_read_mtllib_read_tr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:56:25 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 13:59:59 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	obj_read_mtllib_read_tr(t_obj *obj, char *line)
{
	char	**datas;

	if (!(datas = ft_strsplit(line, ' ')))
		ERROR("ft_strsplit failed");
	if (!datas[0] || !datas[1] || datas[2])
		ERROR("invalid mtl tr line");
	if (!parse_valid_number(datas[1]))
		ERROR("invalid mtl tr value");
	if (!obj->current_mtl)
		ERROR("no current mtl for tr");
	obj->current_mtl->mtl.tr = 1 - ft_atod(datas[1]);
	free_array(datas);
}
