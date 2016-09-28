/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:22:36 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 12:49:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	obj_read(t_obj *obj, int fd)
{
	ssize_t	readed;
	char	*line;

	while ((line = read_next_line(fd, &readed)) && readed > 0)
	{
		if (!(line = ft_strtrim(line)))
			ERROR("Failed to trim line");
		if (line[0] == 'v' && line[1] == ' ')
			obj_read_vertex(obj, line);
		else if (line[0] == 'f' && line[1] == ' ')
			obj_read_face(obj, line);
		else if (line[0] == 's' && line[1] == ' ')
			obj_read_smooth(obj, line);
		else if (ft_strlen(line) >= 7 && !ft_strncmp(line, "usemtl ", 7))
			obj_read_usemtl(obj, line);
		else if (ft_strlen(line) >= 7 && !ft_strncmp(line, "mtllib ", 7))
			obj_read_mtllib(obj, line);
		free(line);
	}
	if (readed == -1)
		ERROR("failed to read file");
}
