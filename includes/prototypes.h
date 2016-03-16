/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:02:16 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/16 16:22:31 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "env.h"

void	error_quit(char *error, char *file, int line);
void	window_init(t_env *env);
void	camera_init(t_env *env);
void	obj_load(t_env *env, char *file);
void	read_obj(t_obj *obj, int fd);

#endif
