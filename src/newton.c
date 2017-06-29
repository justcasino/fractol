/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 09:07:44 by jcasino           #+#    #+#             */
/*   Updated: 2017/06/27 23:59:02 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_n(t_world *world, double x0, double y0, int i)
{
	double xx;
	double yy;
	double j;

	j = 0;
	while (++i < world->iter)
	{
		xx = 2 * x0 / 3 - (x0 * x0 - y0 * y0) / (x0 * x0 + y0 * y0)
			/ (x0 * x0 + y0 * y0) / 3;
		yy = 2 * y0 / 3 + 2 * x0 * y0 / (x0 * x0 + y0 * y0)
			/ (x0 * x0 + y0 * y0) / 3;
		x0 = xx;
		y0 = yy;
		if (x0 * x0 + y0 * y0 < (world->mouse_x / world->img.width))
			j = i;
	}
	world->color =
		kaluh(j, (world->shade > 2 ? world->shade - 3 : world->shade));
	draw_pix(world);
}

void	newton(t_world *world)
{
	world->y = -1;
	while ((world->y += 1) < world->img.height)
	{
		world->x = -1;
		while ((world->x += 1) < world->img.width)
			calc_n(world,
				scale_x(world, world->x), scale_y(world, world->y), 0);
	}
}
