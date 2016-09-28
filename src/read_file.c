/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:08:29 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 16:13:27 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

char	*read_file(char *file)
{
	char	*tmp;
	char	*buf;
	ssize_t	rd;
	int		fd;

	if (!(tmp = ft_strnew(0)))
		ERROR("ft_strnew failed");
	if ((fd = open(file, O_RDONLY)) == -1)
		ERROR("failed to open file");
	if (!(buf = malloc(sizeof(*buf) * 1025)))
		ERROR("malloc failed");
	ft_memset(buf, 0, 1025);
	while ((rd = read(fd, buf, 1024)) > 0)
	{
		buf[rd] = '\0';
		if (!(tmp = ft_strjoin_free1(tmp, buf)))
			ERROR("ft_strjoin_free1 failed");
		ft_memset(buf, 0, 1025);
	}
	free(buf);
	if (rd == -1)
		ERROR("read failed");
	return (tmp);
}
