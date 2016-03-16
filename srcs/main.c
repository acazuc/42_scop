/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:57:07 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/16 15:35:39 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
	{
		ft_putstr("Usage: ");
		ft_putstr(av[0]);
		ft_putstr(" <filename.obj>");
	}
	obj_load(&env, av[1]);
	window_init(&env);
	camera_init(&env);
	return (0);
}
