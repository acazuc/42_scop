/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   face_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:38:07 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/16 15:39:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACE_LIST_H
# define FACE_LIST_H

# include "face.h"

typedef struct s_face_list	t_face_list;

struct			s_face_list
{
	t_face		*face;
	t_face_list	*next;
};

#endif
