/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_frac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 02:30:13 by kradoste          #+#    #+#             */
/*   Updated: 2019/02/26 16:59:10 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fractol.h"

void	initialize(t_fractol *all)
{
	int	pixels;
	int	line;
	int	last;

	all->iter_max = 50;
	all->zoom = 200;
	all->color = 0xffd700;
	all->x0 = -2.1;
	all->y0 = -2.1;
	all->mouse = 1;
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, WIDTH, WIDTH, "42 Fractol");
	all->img = mlx_new_image(all->mlx, WIDTH, WIDTH);
	all->img_ptr = mlx_get_data_addr(all->img, &pixels, &line, &last);
}

void	image_saver(t_fractol *all, int x, int y, int color)
{
	if (all->x < WIDTH && all->y < WIDTH)
	{
		color = mlx_get_color_value(all->mlx, color);
		ft_memcpy(all->img_ptr + sizeof(int) * WIDTH * y +
		sizeof(int) * x, &color, sizeof(int));
	}
}

void	draw_map(t_fractol *all)
{
	t_fractol	tab[9];
	int			i;
	double		tmp;

	i = -1;
	(all->iter_max < 0) && (all->iter_max = 0);
	while (++i < 9)
	{
		ft_memcpy((void*)&tab[i], (void*)all, sizeof(t_fractol));
		tab[i].y = 100 * i;
		tab[i].y_max = 100 * (i + 1);
		tab[i].x = 0;
		tmp = tab[i].y;
		while (tab[i].x < WIDTH)
		{
			tab[i].y = tmp;
			while (tab[i].y < tab[i].y_max)
			{
				get_points(&tab[i]);
				tab[i].y++;
			}
			tab[i].x++;
		}
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
}

int		main(int ac, char **argv)
{
	t_fractol	*all;

	if (!(all = (t_fractol*)malloc(sizeof(t_fractol))))
		return (-1);
	if (ac == 2 && fractol_selector(argv, all) != 0)
	{
		initialize(all);
		draw_map(all);
		mlx_hook(all->win, 6, 1L < 6, deal_mouse, all);
		mlx_mouse_hook(all->win, deal_mouse_zoom, all);
		mlx_key_hook(all->win, deal_key, all);
		mlx_loop(all->mlx);
	}
	else
		ft_putendl("usage : fractol [fractals]\nJulia\nMandelbrot\nShip");
	return (0);
}
