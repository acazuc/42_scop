/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_read_face.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:05:49 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/27 18:03:34 by acazuc           ###   ########.fr       */
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

static void		push_face(t_obj *obj, char **datas, int v_nb)
{
	t_obj_face	face;
	int			i;

	face.n_vertexes = v_nb;
	if (!(face.vertexes = malloc(sizeof(*face.vertexes) * v_nb)))
		ERROR("malloc failed");
	i = 0;
	while (i < v_nb)
	{
		face.vertexes[i] = ft_atoi(datas[i + 1]);
		++i;
	}
	obj_push_face(obj, face);
}

void	obj_read_face(t_obj *obj, char *line)
{
	char	**datas;
	int		v_nb;

	if (!(datas = ft_strsplit(line, ' ')))
		ERROR("ft_strsplit failed");
	v_nb = 0;
	while (datas[v_nb])
	{
		if (v_nb != 0 && !ft_strisdigit(datas[v_nb]))
			ERROR("invalid obj face values");
		v_nb++;
	}
	if (v_nb < 4)
		ERROR("invalid obj face line");
	push_face(obj, datas, v_nb);
}
