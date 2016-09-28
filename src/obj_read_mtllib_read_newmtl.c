/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_read_mtllib_read_newmtl.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:01:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 14:07:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	push_mtl_init(t_obj_mtl *mtl)
{
	ft_memset(mtl + sizeof(char*), 1, sizeof(*mtl) * sizeof(char*));
}

static void	push_mtl(t_obj *obj, char *name)
{
	t_obj_mtl_list	*new;

	if (!(new = malloc(sizeof(*new))))
		ERROR("malloc failed");
	if (!(new->mtl.name = ft_strdup(name)))
		ERROR("ft_strdup failed");
	new->next = obj->mtls;
	obj->mtls = new;
	obj->current_mtl = new;
	push_mtl_init(&new->mtl);
}

void		obj_read_mtllib_read_newmtl(t_obj *obj, char *line)
{
	char	**datas;

	if (!(datas = ft_strsplit(line, ' ')))
		ERROR("ft_strsplit failed");
	if (!datas[0] || !datas[1] || datas[2])
		ERROR("invalid mtl newmtll line");
	push_mtl(obj, datas[1]);
	free_array(datas);
}
