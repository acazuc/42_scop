/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_read_usemtl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 12:20:34 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 12:40:42 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	obj_read_usemtl(t_obj *obj, char *line)
{
	char	**datas;

	if (!(datas = ft_strsplit(line, ' ')))
		ERROR("ft_strsplit failed");
	if (!datas[0] || !datas[1] || datas[2])
		ERROR("invalid usemtl line");
	if (!(obj->current_mtl = ft_strdup(datas[1])))
		ERROR("strdup failed");
	free_array(datas);
}
