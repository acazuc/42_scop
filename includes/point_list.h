/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:36:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/16 15:38:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_LIST_H
# define POINT_LIST_H

# include "point.h"

typedef struct s_point_list	t_point_list;

struct				s_point_list
{
	t_point			*point;
	t_point_list	*next;
};

#endif
