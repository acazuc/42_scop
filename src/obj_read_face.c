/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_read_face.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:05:49 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 12:25:27 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void		obj_push_face(t_obj *obj, t_obj_face face)
{
	t_obj_face_list	*new;
	t_obj_face_list	*lst;

	if (!(new = malloc(sizeof(*new))))
		ERROR("malloc failed");
	new->face = face;
	new->next = NULL;
	if (!(obj->faces))
	{
		obj->faces = new;
		return ;
	}
	lst = obj->faces;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
}

static void		push_face(t_obj *obj, char **datas)
{
	t_obj_face	face;

	face.mtl = obj->current_mtl;
	face.is_quad = datas[4] != NULL;
	face.v1 = ft_atoi(datas[1]);
	face.v2 = ft_atoi(datas[2]);
	face.v3 = ft_atoi(datas[3]);
	if (face.is_quad)
		face.v4 = ft_atoi(datas[4]);
	obj_push_face(obj, face);
}

void	obj_read_face(t_obj *obj, char *line)
{
	char	**datas;

	if (!(datas = ft_strsplit(line, ' ')))
		ERROR("ft_strsplit failed");
	if (!datas[0] || !datas[1] || !datas[2] || !datas[3] || (datas[4] && datas[5]))
		ERROR("invalid obj face line");
	if (!ft_strisdigit(datas[1]) || !ft_strisdigit(datas[2]) || !ft_strisdigit(datas[3])
			|| (datas[4] && !ft_strisdigit(datas[4])))
		ERROR("invalid obj face values");
	push_face(obj, datas);
	free_array(datas);
}
