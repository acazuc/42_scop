/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_read_mtllib.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 12:50:21 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 13:35:21 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static char	*get_obj_path(char *file)
{
	char	*result;
	char	*last_slash;

	last_slash = ft_strrchr(file, '/');
	if (!last_slash)
	{
		if (!(result = ft_strdup(file)))
			ERROR("ft_strdup failed");
		return (result);
	}
	if (!(result = ft_strnew(last_slash - file)))
		ERROR("ft_strnew failed");
	ft_strncat(result, file, last_slash - file);
	return (result);
}

static void	mtllib_load(t_obj *obj, char *file)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		ERROR("failed to open mtllib file");
	obj_read_mtllib_read(obj, fd);
	close(fd);
}

void		obj_read_mtllib(t_obj *obj, char *line)
{
	char	**datas;
	char	*obj_path;
	char	*mtlfile;

	if (!(datas = ft_strsplit(line, ' ')))
		ERROR("ft_strsplit failed");
	if (!datas[0] || !datas[1] || datas[2])
		ERROR("invalid obj mtllib line");
	obj_path = get_obj_path(obj->file);
	if (!(mtlfile = ft_strjoin_free1(obj_path, "/")))
		ERROR("ft_strjoin_free1 failed");
	if (!(mtlfile = ft_strjoin_free1(mtlfile, datas[1])))
		ERROR("ft_strjoin_free1 failed");
	free_array(datas);
	mtllib_load(obj, mtlfile);
	free(mtlfile);
}
