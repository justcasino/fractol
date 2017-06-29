/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 08:52:09 by jcasino           #+#    #+#             */
/*   Updated: 2017/06/26 09:07:00 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_m(t_world *world, double x0, double y0, double i)
{
	double x;
	double x2;
	double y;
	double y2;

	x = 0.0;
	y = 0.0;
	x2 = world->mouse_x;
	y2 = world->mouse_y;
	while (++i < world->iter && (x2 + y2) < world->iter)
	{
		y = 2.0 * x * y + y0;
		x = x2 - y2 + x0;
		x2 = x * x;
		y2 = y * y;
	}
	if (world->fractol < 3)
		i = (i * (1 - 1.0) + (i - log2(log2(x2 + y2))) * 1.0);
	world->color = kaluh(i, (world->shade > 2
				? world->shade - 3 : world->shade));
	draw_pix(world);
}

void	mandelbrot(t_world *world)
{
	world->y = -1;
	while ((world->y += 1) < world->img.height)
	{
		world->x = -1;
		while ((world->x += 1) < world->img.width)
			calc_m(world, scale_x(world, world->x),
					scale_y(world, world->y), -1.0);
	}
}
