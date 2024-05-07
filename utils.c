/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:25:08 by yabdoul           #+#    #+#             */
/*   Updated: 2024/05/06 12:51:19 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

// todo :  parssing arguments !!!

void	init_fract(t_fractol *fractol, char *name, double x, double y)

{
	if (!ft_strcmp(name, "julia") && !ft_strcmp(name, "mandelbort"))
		exit(0);
	fractol->type = name;
	fractol->mlx_ptr = mlx_init();
	fractol->mlx_window = mlx_new_window(fractol->mlx_ptr, HEIGHT, WIDTH,
			"Hello world!");
	fractol->img.img = mlx_new_image(fractol->mlx_ptr, HEIGHT, WIDTH);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel, &fractol->img.line_length,
			&fractol->img.endian);
	fractol->max_itteration = 42;
	fractol->x = 0;
	fractol->y = 0;
	fractol->julia_const_x = x;
	fractol->julia_const_y = y;
	fractol->zoom = 1.1;
	fractol->over_value = 4;
}

void	my_img_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_mandelbort_pixel(t_fractol *fract, int x, int y)
{
	int			i;
	int			color;
	t_complex	z1;
	t_complex	z2;

	color = WHITE;
	z1.reel = 0.0;
	z1.imagine = 0.0;
	z2.reel = (my_scale_tool(x, -2, 2, WIDTH) * fract->zoom) + fract->x;
	z2.imagine = (my_scale_tool(y, 2, -2, HEIGHT) * fract->zoom) + fract->y;
	i = 1;
	while (i < fract->max_itteration)
	{
		z1 = add_complex(complex_square(z1), z2);
		if ((z1.reel * z1.reel) + (z1.imagine * z1.imagine) > fract->over_value)
		{
			color = color_scale_tool(i, fract->max_itteration);
			my_img_pixel_put(&fract->img, x, y, color);
			return ;
		}
		i++;
	}
	my_img_pixel_put(&fract->img, x, y, PSYCHEDELIC_COLOR);
}

void	draw_julia_pixel(t_fractol *fract, int x, int y)
{
	int			i;
	int			color;
	t_complex	z1;
	t_complex	z2;

	color = WHITE;
	z2.reel = fract->julia_const_x;
	z2.imagine = fract->julia_const_y;
	z1.reel = (my_scale_tool(x, -2, 2, WIDTH) * fract->zoom) + fract->x;
	z1.imagine = (my_scale_tool(y, 2, -2, HEIGHT) * fract->zoom) + fract->y;
	i = 1;
	while (i < fract->max_itteration)
	{
		z1 = add_complex(complex_square(z1), z2);
		if ((z1.reel * z1.reel) + (z1.imagine * z1.imagine) > fract->over_value)
		{
			color = color_scale_tool(i, fract->max_itteration);
			my_img_pixel_put(&fract->img, x, y, color);
			return ;
		}
		i++;
	}
	my_img_pixel_put(&fract->img, x, y, PSYCHEDELIC_COLOR);
}

void	draw_all_fractol(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (ft_strcmp(fractol->type, "mandelbort"))
				draw_mandelbort_pixel(fractol, x, y);
			else if (ft_strcmp(fractol->type, "julia"))
				draw_julia_pixel(fractol, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->mlx_window,
		fractol->img.img, 0, 0);
}
