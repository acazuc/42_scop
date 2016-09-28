/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_read_mtllib_read.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:20:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 13:27:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	obj_read_mtlllib_read(t_obj *obj, int fd)
{
	ssize_t		readed;
	char		*line;

	while ((line = read_next_line(fd, &readed)) && readed > 0)
	{
		if (!(line = ft_strtrim(line)))
			ERROR("ft_strtrim failed");
		if (line[0] == 'K' && line[1] == 'a' && line[2] == ' ')
			obj_read_mtllib_read_ka(obj, line);
		else if (line[0] == 'K' && line[1] == 'd' && line[2] == ' ')
			obj_read_mtllib_read_kd(obj, line);
		else if (line[0] == 'K' && line[1] == 's' && line[2] == ' ')
			obj_read_mtllib_read_ks(obj, line);
		else if (line[0] == 'N' && line[1] == 'i' && line[2] == ' ')
			obj_read_mtllib_read_ni(obj, line);
		else if (line[0] == 'T' && line[1] == 'r' && line[2] == ' ')
			obj_read_mtllib_read_tr(obj, line);
		else if (line[0] == 'd' && line[1] == ' ')
			obj_read_mtllib_read_d(obj, line);
	}
	if (readed == -1)
		ERROR("failed to read mtllib file");
}
