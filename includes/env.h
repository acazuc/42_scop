/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:22:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/16 15:49:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "window.h"
# include "camera.h"
# include "obj.h"

typedef struct	s_env
{
	t_window	*window;
	t_camera	*camera;
	t_obj		*obj;
}				t_env;

#endif
