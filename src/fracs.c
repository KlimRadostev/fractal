/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:15:39 by kradoste          #+#    #+#             */
/*   Updated: 2019/02/26 15:05:25 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_fractol *all)
{
	while (all->xz * all->xz + all->yz * all->yz < 4
			&& all->iter < all->iter_max)
	{
		all->tmp = all->xz * all->xz - all->yz * all->yz + all->c_x / WIDTH;
		all->yz = 2 * all->yz * all->xz + all->c_y / WIDTH;
		all->xz = all->tmp;
		all->iter++;
	}
}

void	ft_mandelbrot(t_fractol *all)
{
	while (all->xz * all->xz + all->yz * all->yz < 4
			&& all->iter < all->iter_max)
	{
		all->tmp = all->xz * all->xz - all->yz * all->yz + all->c_x;
		all->yz = 2 * all->yz * all->xz + all->c_y;
		all->xz = all->tmp;
		all->iter++;
	}
}

void	ft_ship(t_fractol *all)
{
	while (all->xz * all->xz + all->yz * all->yz < 4
			&& all->iter < all->iter_max)
	{
		all->tmp = all->xz * all->xz - all->yz * all->yz + all->c_x;
		all->yz = fabs(2 * all->xz * all->yz) + all->c_y;
		all->xz = all->tmp;
		all->iter++;
	}
}

int		fractol_selector(char **argv, t_fractol *all)
{
	if (ft_strcmp(argv[1], "Julia") == 0)
		all->name = 1;
	else if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		all->name = 2;
	else if (ft_strcmp(argv[1], "Ship") == 0)
		all->name = 3;
	else
		return (0);
	return (1);
}

void	get_points(t_fractol *all)
{
	if (all->name != 1)
	{
		all->c_x = all->x / all->zoom + all->x0;
		all->c_y = all->y / all->zoom + all->y0;
	}
	all->xz = 0;
	all->yz = 0;
	all->iter = 0;
	if (all->name == 1)
	{
		all->xz = all->x / all->zoom + all->x0;
		all->yz = all->y / all->zoom + all->y0;
		all->mouse = 1;
		ft_julia(all);
	}
	else if (all->name == 2)
		ft_mandelbrot(all);
	else if (all->name == 3)
		ft_ship(all);
	if (all->iter == all->iter_max)
		image_saver(all, all->x, all->y, 0x000000);
	else
		image_saver(all, all->x, all->y, (all->color * all->iter));
}
