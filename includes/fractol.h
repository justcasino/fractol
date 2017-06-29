/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 21:25:19 by jcasino           #+#    #+#             */
/*   Updated: 2017/06/26 09:23:29 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <libc.h>
# include <string.h>
# include "../minilibx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include <time.h>

typedef	struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef	struct		s_img
{
	void			*ptr;
	unsigned char	*img;
	int				bpp;
	int				sl;
	int				end;
	int				width;
	int				height;
}					t_img;

typedef	struct		s_world
{
	void			*mlx;
	void			*win;
	t_vec			color;
	int				fractol;
	t_img			img;
	int				iter;
	int				x;
	int				y;
	int				pause;
	int				shade;
	double			xtop;
	double			xbot;
	double			ytop;
	double			ybot;
	double			mouse_x;
	double			mouse_y;
}					t_world;

void				valid(int ac);
t_vec				kaluh(double x, int ch_col);
double				scale_y(t_world *world, int y);
double				scale_x(t_world *world, int x);
void				draw_pix(t_world *world);
void				fract_error(int n);
void				frac_name(t_world *world, char **av);
void				init_mw(t_world *world);
void				set_sval(t_world *world);
t_world				*init_world(char **av);
int					expose(t_world *world);
int					keys(int keycode, t_world *world);
void				zoom_in(t_world *world, double x, double y);
void				zoom_out(t_world *world);
int					mouse(int scroll, int x, int y, t_world *world);
int					move(int x, int y, t_world *world);
void				julia(t_world *world);
void				mandelbrot(t_world *world);
void				newton(t_world *world);
void				calc_j(t_world *world, double x0, double y0, double i);
void				calc_m(t_world *world, double x0, double y0, double i);
void				calc_n(t_world *world, double x0, double y0, int i);
double				mathorizer(double x, double y, double a);

#endif
