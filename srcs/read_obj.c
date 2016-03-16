/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:22:36 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/16 16:44:05 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	read_obj(t_obj *obj, int fd)
{
	char	*line;
	while ((rd = get_next_line(fd, &line)) > 0)
	{
		if (!(line = ft_str
	}
	if (rd == -1)
		ERROR("Failed to read obj file");
}
