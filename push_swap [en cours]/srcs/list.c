/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 12:49:11 by mdambrev          #+#    #+#             */
/*   Updated: 2015/05/28 17:20:56 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int				cmp(int a, int b)
{
	return(a > b);
}

t_content		*create_list(char **argv)
{
	t_content *axx;
	int x;
	t_int *tmp;

	x = 0;
	axx = init_list();
	while(argv[x])
	{
		tmp = (t_int*)malloc(sizeof(tmp));
		tmp->t_x = ft_atoi(argv[x]);
		add_l(&LIST_A(0), tmp, -1);
		tmp = (t_int*)malloc(sizeof(tmp));
		tmp->t_x = ft_atoi(argv[x]);
		add_l(&LIST_A(2), tmp, -1);
		x++;
	}
	sort_list_bul(axx, 2, cmp);
	add_l(&LIST_A(1), NULL, 0);
	return(axx);
}
