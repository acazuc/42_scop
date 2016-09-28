/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_read_smooth.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 12:01:43 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 12:15:30 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	obj_read_smooth(t_obj *obj, char *line)
{
	char	**datas;

	if (!(datas = ft_strsplit(line, ' ')))
		ERROR("ft_strsplit failed");
	if (!datas[1] || datas[2])
		ERROR("invalid obj smooth line");
	if (!ft_strcmp(datas[1], "1") || !ft_strcmp(datas[1], "on"))
		obj->smooth = 1;
	else if (!ft_strcmp(datas[1], "on") || !ft_strcmp(datas[1], "off"))
		obj->smooth = 0;
	else
		ERROR("invalid obj smooth value");
}
