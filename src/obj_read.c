/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:22:36 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/27 17:40:51 by acazuc           ###   ########.fr       */
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
		if (line[0] == 'f' && line[1] == ' ')
			obj_read_face(obj, line);
		free(line);
	}
	if (readed == -1)
		ERROR("failed to read file");
}
