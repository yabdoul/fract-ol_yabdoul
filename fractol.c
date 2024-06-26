/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:25:15 by yabdoul           #+#    #+#             */
/*   Updated: 2024/05/07 13:08:26 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int	handle_keypress(int keysym, t_fractol *fractol)
{
	if (keysym == 53)
	{
		mlx_destroy_image(fractol->mlx_ptr, fractol->img.img);
		mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_window);
		exit(0);
	}
	if (keysym == 123)
		fractol->x += 0.1 * fractol->zoom;
	if (keysym == 124)
		fractol->x -= 0.1 * fractol->zoom;
	if (keysym == 125)
		fractol->y -= 0.1 * fractol->zoom;
	if (keysym == 126)
		fractol->y += 0.1 * fractol->zoom;
	draw_all_fractol(fractol);
	return (0);
}

int	handle_mouse_move(int keysym, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (keysym == 5)
		fractol->zoom *= 1.1;
	if (keysym == 4)
		fractol->zoom /= 1.1;
	draw_all_fractol(fractol);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractol	*fractol;
	t_float		*float_data;

	float_data = NULL;
	if (ac < 2 || (ft_strcmp(av[1], "mandelbort") && ac > 2))
		return (0);
	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (ac == 4)
	{
		if (ft_strcmp(av[2], "") || ft_strcmp(av[3], ""))
			exit(0);
		init_fract(fractol, av[1], ft_atof(av[2],
				init_float_struct(float_data)), ft_atof(av[3],
				init_float_struct(float_data)));
	}
	else if (ac == 2)
	{
		init_fract(fractol, av[1], 0.4, 0.4);
	}
	draw_all_fractol(fractol);
	mlx_hook(fractol->mlx_window, 02, (1L << 0), &handle_keypress, fractol);
	mlx_mouse_hook(fractol->mlx_window, &handle_mouse_move, fractol);
	mlx_loop(fractol->mlx_ptr);
	free(fractol);
}
