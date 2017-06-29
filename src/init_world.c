/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 20:28:42 by jcasino           #+#    #+#             */
/*   Updated: 2017/06/26 20:28:46 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_world	*init_world(char **av)
{
	t_vec		colors;
	t_world		*world;

	world = (t_world*)malloc(sizeof(t_world));
	frac_name(world, av);
	init_mw(world);
	world->mouse_x = 0;
	world->mouse_y = 0;
	world->iter = 50;
	world->shade = 0;
	world->pause = 0;
	colors = (t_vec){0.0, 0.0, 0.0};
	world->color = colors;
	set_sval(world);
	return (world);
}

void	frac_name(t_world *world, char **av)
{
	if (!ft_strcmp(av[1], "Julia") || !ft_strcmp(av[1], "julia"))
		world->fractol = 2;
	else if (!ft_strcmp(av[1], "Mandelbrot") || !ft_strcmp(av[1], "mandelbrot"))
		world->fractol = 1;
	else if (!ft_strcmp(av[1], "Newton") || !ft_strcmp(av[1], "newton"))
		world->fractol = 3;
	else
		fract_error(1);
}

void	init_mw(t_world *world)
{
	world->img.width = 800;
	world->img.height = 500;
	world->mlx = mlx_init();
	world->win = mlx_new_window(world->mlx, world->img.width,
		world->img.height, "fractol");
	world->img.ptr =
	mlx_new_image(world->mlx, world->img.width, world->img.height);
	world->img.img = (unsigned char*)mlx_get_data_addr(world->img.ptr,
		&(world->img.bpp), &(world->img.sl), &(world->img.end));
}

void	set_sval(t_world *world)
{
	if (world->fractol == 1)
	{
		world->xtop = 1;
		world->xbot = -2.5;
		world->ytop = 1;
		world->ybot = -1;
	}
	else if (world->fractol == 2)
	{
		world->xtop = 2;
		world->xbot = -2;
		world->ytop = 2;
		world->ybot = -2;
	}
	else if (world->fractol == 3)
	{
		world->xtop = 4;
		world->xbot = -4;
		world->ytop = 4;
		world->ybot = -4;
		world->mouse_x = world->img.width / 2;
	}
}
