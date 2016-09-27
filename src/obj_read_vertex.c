/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_read_vertex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:16:24 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/27 17:24:01 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	obj_push_vertex(t_obj *obj, t_obj_vertex vertex)
{
	t_obj_vertex_list	*new;
	t_obj_vertex_list	*lst;

	if (!(new = malloc(sizeof(*new))))
		ERROR("malloc failed");
	new->vertex = vertex;
	new->next = NULL;
	if (!obj->vertexes)
	{
		obj->vertexes = new;
		return ;
	}
	lst = obj->vertexes;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
}

static void	push_vertex(t_obj *obj, char **datas)
{
	t_obj_vertex	vertex;

	vertex.x = ft_atod(datas[1]);
	vertex.y = ft_atod(datas[2]);
	vertex.z = ft_atod(datas[3]);
	obj_push_vertex(obj, vertex);
}

void		obj_read_vertex(t_obj *obj, char *line)
{
	char	**datas;

	if (!(datas = ft_strsplit(line, ' ')))
		ERROR("ft_strsplit failed");
	if (!datas[0] || !datas[1] || !datas[2] || !datas[3] || datas[4])
		ERROR("invalid obj vertex line");
	if (!parse_valid_number(datas[1]) || !parse_valid_number(datas[2])
			|| !parse_valid_number(datas[3]))
		ERROR("invalid obj vertex value");
	push_vertex(obj, datas);
}
