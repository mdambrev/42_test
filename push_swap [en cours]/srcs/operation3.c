/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 20:14:51 by mdambrev          #+#    #+#             */
/*   Updated: 2015/06/01 08:21:53 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
// atention a lincrementation parfois inutile si par ex pa ne fait rien

size_t op(t_content *axx, int x)
{
	static size_t  out = 0;

	if(x > 0)
		out++;
	if(x == 0)
		s_a(axx);
	else if(x == 1)
		s_b(axx);
	else if(x == 2)
		ss(axx);
	else if(x == 3)
		p_a(axx);
	else if(x == 4)
		p_b(axx);
	else if(x == 5)
		r_a(axx);
	else if(x == 6)
		r_b(axx);
	else if(x == 7)
		rr(axx);
	else if(x == 8)
		rra(axx);
	else if(x == 9)
		rrb(axx);
	else if(x == 10)
		rrr(axx);
	return(out);
}

void push_b(t_content *axx, int  pos_x)
{
	int x;

	TMP_A(0) = LIST_A(0);
	LIST_R(NB_LIST);
	x = TMP_I(0, 0) / 2;
	if(x == 0)
		return;
	if(pos_x <= 0)
	{
		ft_putendl("\nERROR: R_Value < push_b >\n");
		exit(-1);
	}
	if(pos_x < x)
	{
		while(pos_x--)
			op(axx, 8);
		op(axx, 4);
	}
	else if(pos_x >= x)
	{
		pos_x++;
		x = TMP_I(0, 0);
		while(pos_x++ < x)
			op(axx, 5);
		op(axx, 4);
	}
	TMP_A(0) = LIST_A(0);
	LIST_R(NB_LIST);
	TMP_I(0, 0)--;
	TMP_A(0) = LIST_A(1);
	LIST_R(NB_LIST);
	TMP_I(0, 0)++;
}

void push_a(t_content *axx, int  pos_x)
{
	int x;

	TMP_A(0) = LIST_A(1);
	LIST_R(NB_LIST);
	x = TMP_I(0, 0) / 2;
	if(x == 0)
		return;
	if(pos_x <= 0)
	{
		ft_putendl("\nERROR: R_Value < push_a >\n");
		exit(-1);
	}
	if(pos_x < x)
	{
		while(pos_x--)
			op(axx, 9);
		op(axx, 3);
	}
	else if(pos_x >= x)
	{
		pos_x++;
		x = TMP_I(0, 0);
		while(pos_x++ < x)
			op(axx, 6);
		op(axx, 3);
	}
	TMP_A(0) = LIST_A(1);
	LIST_R(NB_LIST);
	TMP_I(0, 0)--;
	TMP_A(0) = LIST_A(0);
	LIST_R(NB_LIST);
	TMP_I(0, 0)++;
}
