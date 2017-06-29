/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 21:20:35 by jcasino           #+#    #+#             */
/*   Updated: 2017/06/26 08:06:09 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fract_error(int n)
{
	if (n == 0)
	{
		ft_putendl("No parameter. Usage: ./fractol [map name]");
		ft_putendl("M(m)andlebrot, J(j)ulia, N(n)ewton");
	}
	if (n == 1)
		ft_putendl("Incorrect parameter");
	write(1, "\n", 1);
	ft_putendl("M(m)andlebrot, J(j)ulia, N(n)ewton");
	ft_putendl("-Pause 'Spacebar' ");
	ft_putendl("-Move Window Left, Right, Up, Down");
	ft_putendl("-Zoom Scroll up to zoom in down to zoom out");
	ft_putendl("-Change Colors 'C'");
	ft_putendl("-Quit hit 'esc'");
	exit(1);
}

void	valid(int ac)
{
	if (ac < 2)
		fract_error(0);
	if (ac > 2)
		fract_error(1);
	else
		return ;
}

int		expose(t_world *world)
{
	if (world->fractol == 1)
		mandelbrot(world);
	else if (world->fractol == 2)
		julia(world);
	else if (world->fractol == 3)
		newton(world);
	mlx_put_image_to_window(world->mlx, world->win, world->img.ptr, 0, 0);
	return (1);
}

int		main(int ac, char **av)
{
	t_world *world;

	valid(ac);
	world = init_world(av);
	mlx_key_hook(world->win, keys, world);
	mlx_mouse_hook(world->win, mouse, world);
	mlx_hook(world->win, 6, 64, move, world);
	mlx_expose_hook(world->win, expose, world);
	mlx_loop(world->mlx);
	return (0);
}
