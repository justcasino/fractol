/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 07:42:49 by jcasino           #+#    #+#             */
/*   Updated: 2017/06/26 09:23:26 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_pix(t_world *world)
{
	int i;

	i = (world->x * world->img.bpp / 8) + (world->y * world->img.sl);
	world->img.img[i] = ((int)(world->color.z * 256) % 256);
	world->img.img[i + 1] = ((int)(world->color.y * 256) % 256);
	world->img.img[i + 2] = ((int)(world->color.x * 256) % 256);
}

double	scale_x(t_world *world, int x)
{
	return ((((world->xtop - world->xbot) * x) /
	world->img.height) + world->xbot);
}

double	scale_y(t_world *world, int y)
{
	return ((((world->ytop - world->ybot) * y) /
	world->img.height) + world->ybot);
}

t_vec	kaluh(double x, int ch_col)
{
	t_vec color;

	color.x = 0.5 + 0.5 * cos(3.0 + x * 0.15 + (ch_col == 0));
	color.y = 0.5 + 0.5 * cos(3.0 + x * 0.15 + (ch_col == 1));
	color.z = 0.5 + 0.5 * cos(3.0 + x * 0.15 + (ch_col == 2));
	return (color);
}

double	mathorizer(double x, double y, double a)
{
	double value;

	value = (x * (1 - a) + y * a);
	return (value);
}
