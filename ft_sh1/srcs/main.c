/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 17:50:53 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/08 17:39:38 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <stdio.h>

int					main(int argc, char **argv, char **env)
{

	t_clist *param;
	char **tab;
	(void)argc;
	(void)argv;

	param = init_param();
	dup_env(env, param);
	while(1)
	{
		ft_putstr("$ > ");
		tab = read_standar(param);
		set_action(param, 0);
		exec_builtins(param);
		bin_bin(param);
	}
	return (0);
}
