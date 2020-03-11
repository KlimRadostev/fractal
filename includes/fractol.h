/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 02:30:30 by kradoste          #+#    #+#             */
/*   Updated: 2019/02/26 16:53:32 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "libft.h"
# include "mlx.h"
# include "math.h"

# define WIDTH 900

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			name;
	int			color;
	int			mouse;
	double		x;
	double		y;
	double		x0;
	double		y0;
	double		x1;
	double		y1;
	double		y_max;
	double		xz;
	double		yz;
	double		c_x;
	double		c_y;
	double		tmp;
	int			iter_max;
	int			iter;
	double		zoom;
}				t_fractol;

void			draw_map(t_fractol *all);
void			initialize(t_fractol *all);
void			image_saver(t_fractol *all, int x, int y, int color);
void			get_points(t_fractol *all);
void			ft_julia(t_fractol *all);
void			ft_mandelbrot(t_fractol *all);
void			ft_ship(t_fractol *all);
int				deal_mouse(int x, int y, t_fractol *all);
int				fractol_selector(char **argv, t_fractol *all);
int				deal_key(int key, t_fractol *all);
int				deal_mouse_zoom(int mouse, int x, int y, t_fractol *all);

#endif
