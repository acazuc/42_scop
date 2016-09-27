/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:57:07 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/27 17:41:31 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	main(int ac, char **av)
{
	t_env	env;

	ft_bzero(&env, sizeof(env));
	if (ac != 2)
	{
		ft_putstr("Usage: ");
		ft_putstr(av[0]);
		ft_putstr(" <filename.obj>");
		return (EXIT_FAILURE);
	}
	obj_load(&env, av[1]);
	window_init(&env);
	return (EXIT_SUCCESS);
}
