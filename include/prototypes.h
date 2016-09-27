/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:02:16 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/27 16:26:44 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "env.h"

void	error_quit(char *error, char *file, int line);
void	window_init(t_env *env);
void	camera_init(t_env *env);
void	obj_load(t_env *env, char *file);
void	obj_read(t_obj *obj, int fd);
void	obj_read_face(t_obj *obj, char *line);
void	obj_read_vertex(t_obj *obj, char *line);
char	*read_next_line(int fd);

#endif
