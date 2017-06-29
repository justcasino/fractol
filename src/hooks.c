/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 03:54:16 by jcasino           #+#    #+#             */
/*   Updated: 2017/06/26 07:42:12 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		keys(int keycode, t_world *world)
{
	double tmp;

	if (keycode == 53)
	{
		mlx_destroy_window(world->mlx, world->win);
		exit(0);
	}
	else if (keycode == 126 || keycode == 125)
	{
		tmp = (world->ytop - world->ybot) / 4;
		world->ytop += (keycode == 125 ? tmp : -tmp);
		world->ybot += (keycode == 125 ? tmp : -tmp);
	}
	else if (keycode == 123 || keycode == 124)
	{
		tmp = (world->xtop - world->xbot) / 4;
		world->xtop += (keycode == 124 ? tmp : -tmp);
		world->xbot += (keycode == 124 ? tmp : -tmp);
	}
	else if (keycode == 8)
		world->shade += (world->shade == 5) ? -5 : 1;
	else if (keycode == 49)
		world->pause = (world->pause) ? 0 : 1;
	expose(world);
	return (1);
}

void	zoom_in(t_world *world, double x, double y)
{
	world->xbot = x + ((world->xbot - x) / 2);
	world->xtop = world->xtop + ((x - world->xtop) / 2);
	world->ybot = y + ((world->ybot - y) / 2);
	world->ytop = world->ytop + ((y - world->ytop) / 2);
}

void	zoom_out(t_world *world)
{
	world->xbot = world->xbot - ((world->xtop - world->xbot) / 2);
	world->xtop = world->xtop + ((world->xtop - world->xbot) / 2);
	world->ybot = world->ybot - ((world->ytop - world->ybot) / 2);
	world->ytop = world->ytop + ((world->ytop - world->ybot) / 2);
}

int		mouse(int scroll, int x, int y, t_world *world)
{
	double x1;
	double y1;

	x1 = scale_x(world, x);
	y1 = scale_y(world, y);
	if (scroll == 4)
		zoom_in(world, x1, y1);
	else if (scroll == 5)
		zoom_out(world);
	expose(world);
	return (1);
}

int		move(int x, int y, t_world *world)
{
	if (world->pause)
	{
		world->mouse_x = scale_x(world, x);
		world->mouse_y = scale_y(world, y);
		if (world->fractol == 3)
			world->mouse_x = x;
	}
	expose(world);
	return (1);
}
