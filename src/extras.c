/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 03:24:39 by kradoste          #+#    #+#             */
/*   Updated: 2019/02/26 15:01:18 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		change_color(t_fractol *all)
{
	if (all->color == 0xFFD700)
		all->color = 0xFF9DBB;
	else if (all->color == 0xFF9DBB)
		all->color = 0xF0000FF;
	else if (all->color == 0xF0000FF)
		all->color = 0x8B4513;
	else if (all->color == 0x8B4513)
		all->color = 0xEE7600;
	else if (all->color == 0xEE7600)
		all->color = 0x8E388E;
	else if (all->color == 0x8E388E)
		all->color = 0xEECBAD;
	else if (all->color == 0xEECBAD)
		all->color = 0xFFE4E1;
	else if (all->color == 0xFFE4E1)
		all->color = 0xFFD700;
}

int			deal_key(int key, t_fractol *all)
{
	(key == 123) && (all->x0 += 30 / all->zoom);
	(key == 124) && (all->x0 -= 30 / all->zoom);
	(key == 125) && (all->y0 -= 30 / all->zoom);
	(key == 126) && (all->y0 += 30 / all->zoom);
	if (key == 53)
		exit(1);
	else if (key == 18)
		change_color(all);
	(key == 1) && (all->mouse = (all->mouse == 1) ? 0 : 1);
	mlx_clear_window(all->mlx, all->win);
	draw_map(all);
	return (0);
}

int			deal_mouse(int x, int y, t_fractol *all)
{
	if (all->name == 1 && all->mouse == 1)
	{
		all->c_x = x * 2 - 900;
		all->c_y = y * 2 - 900;
		mlx_clear_window(all->mlx, all->win);
		draw_map(all);
	}
	return (0);
}

int			deal_mouse_zoom(int mouse, int x, int y, t_fractol *all)
{
	if (mouse == 4)
	{
		all->x0 = (all->x1 / all->zoom + all->x0) - ((all->zoom / 1.3) / 2);
		all->x0 += ((all->zoom / 1.3) / 2) - (all->x1 / (all->zoom / 1.3));
		all->y0 = (all->y1 / all->zoom + all->y0) - ((all->zoom / 1.3) / 2);
		all->y0 += ((all->zoom / 1.3) / 2) - (all->y1 / (all->zoom / 1.3));
		all->zoom /= 1.3;
		all->iter_max--;
	}
	else if (mouse == 5)
	{
		all->x1 = x;
		all->y1 = y;
		all->x0 = (x / all->zoom + all->x0) - ((all->zoom * 1.3) / 2);
		all->x0 += ((all->zoom * 1.3) / 2) - (x / (all->zoom * 1.3));
		all->y0 = (y / all->zoom + all->y0) - ((all->zoom * 1.3) / 2);
		all->y0 += ((all->zoom * 1.3) / 2) - (y / (all->zoom * 1.3));
		all->zoom *= 1.3;
		all->iter_max++;
	}
	mlx_clear_window(all->mlx, all->win);
	draw_map(all);
	return (0);
}
