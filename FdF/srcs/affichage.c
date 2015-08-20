/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 19:02:15 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/20 20:51:19 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void stock_param(t_clist *param, t_clist *a, t_clist *b)
{
	CONTENT(2) = ((t_int*)((t_clist *)a + 3)->bit + 1)->t_x;
	CONTENT(3) = ((t_int*)((t_clist *)a + 3)->bit + 2)->t_x;
	CONTENT(4) = ((t_int*)((t_clist *)b + 3)->bit + 1)->t_x;
	CONTENT(5) = ((t_int*)((t_clist *)b + 3)->bit + 2)->t_x;
}


int set_color(t_clist *a, t_clist *b)
{
	int bob;

	bob = 0;
	if(((t_int*)((t_clist *)b + 3)->bit)->t_x != 0 
			|| ((t_int*)((t_clist *)a + 3)->bit)->t_x != 0)
		bob = 0xFF0000;
	else 
		bob = 0x00FF00;
	return(bob);
	
}

static void norm1(t_clist *param, int *dx, int *dy)
{
	*dx = CONTENT(4) - CONTENT(2);
	*dy = CONTENT(5) - CONTENT(3);
	if(*dx > 0)
		CONTENT(6) = 1;
	else 
		CONTENT(6) = -1;
	if(*dy > 0)
		CONTENT(7) = 1;
	else 
		CONTENT(7) = -1;
	if(*dx < 0)
		*dx = *dx * (-1);
	if(*dy < 0)
		*dy = *dy * (-1);
	CONTENT(8) = 0;
}

void tracer_bresenham(t_clist *param , t_clist *a, t_clist *b)
{
	int dx;
	int dy;
	int cumul;
	
	stock_param(param , a, b);
	CONTENT(9) = set_color(a, b);
	norm1(param, &dx, &dy);
	if(dx > dy)
	{
		cumul = dx / 2;
		while(CONTENT(8) < dx)
		{
			CONTENT(2) += CONTENT(6);
			cumul += dy;
			if( cumul >= dx)
			{
				cumul -= dx ;
				CONTENT(3) += CONTENT(7);
			}	
			mlx_pixel_put(PARAM(0), PARAM(1), CONTENT(2), CONTENT(3), (int)CONTENT(9));
			CONTENT(8) += 1;
		}
	}
	else
	{
		cumul = dy / 2;
		while(CONTENT(8) < dy)
		{
			CONTENT(3) += CONTENT(7);
			cumul += dx ;
			if(cumul >= dy)
			{
				cumul -= dy;
				CONTENT(2) += CONTENT(6);
			}	
			mlx_pixel_put(PARAM(0), PARAM(1), CONTENT(2), CONTENT(3), (int)CONTENT(9));
			CONTENT(8) += 1;
		}
	}

}

void trace_map(t_content *axx, t_clist *param)
{
	int x;
	int y;

	x = 0;
	y = 1;
	LIST_R(0);
	while(x < CONTENT(0))
	{
		while(LIST_IB(x, 0) == 0 && LIST_V(x, 0) != LIST_V(x, 2))
		{

			tracer_bresenham(param, LIST_A(x), LIST_V(x, 0));
		}
		LIST_R(x);
		x++;
	}
	x = 0;
	while(y < CONTENT(0))
	{
		LIST_R(x);
		LIST_R(y);
		while(LIST_IB(y, 0) == 0 && LIST_V(x, 0) != LIST_V(x, 2))
		{
			LIST_I(x, 0);
			tracer_bresenham(param, LIST_A(x), LIST_A(y));
		}
		LIST_R(x);
		LIST_R(y);
		y++;
		x++;
	}
}

int main_aff(t_content *axx, t_clist *param)
{
	int x;
	
	x = 0;
	(void)param;
/*	while(x < 11)
	{
		LIST_R(x);
		while(LIST_IB(x, 0) == 0)
		{
			{
				printf(" %d", VALUE_I(x, 0));
			}
		}
		LIST_R(x);
		printf("\n");
		x++;
	}
	LIST_I(0, 0);*/
	trace_map(axx, param);
	//printf("toto123123123123123123123123123123123123\n");
	return(0);
}


