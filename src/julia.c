/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 09:15:03 by jcasino           #+#    #+#             */
/*   Updated: 2017/06/26 09:20:52 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_j(t_world *world, double x0, double y0, double i)
{
	double x1;
	double y1;
	double sco;

	sco = exp(-sqrt(x0 * x0 + y0 * y0));
	while (++i < world->iter && (x0 + y0) < 4.0)
	{
		x1 = x0;
		y1 = y0;
		x0 = x1 * x1 - y1 * y1 + world->mouse_x;
		y0 = 2.0 * x1 * y1 + world->mouse_y;
		sco += exp(-sqrt(x0 * x0 + y0 * y0));
	}
	if (world->fractol < 3)
		i = mathorizer(i, sco, 1.0);
	world->color =
		kaluh(i, (world->shade > 2) ? world->shade - 3 : world->shade);
	draw_pix(world);
}

void	julia(t_world *world)
{
	world->y = -1;
	while ((world->y += 1) < world->img.height)
	{
		world->x = -1;
		while ((world->x += 1) < world->img.width)
			calc_j(world, scale_x(world, world->x),
			scale_y(world, world->y), -1.0);
	}
}
