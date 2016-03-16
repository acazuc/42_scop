/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:35:53 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/16 16:21:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# include "point_list.h"
# include "face_list.h"

typedef struct		s_obj
{
	t_point_list	*points;
	t_face_list		*faces;
}					t_obj;

#endif
