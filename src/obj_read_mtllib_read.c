/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_read_mtllib_read.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:20:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 13:22:48 by acazuc           ###   ########.fr       */
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

	}
	if (readed == -1)
		ERROR("failed to read mtllib file");
}
