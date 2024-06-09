/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:42:19 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/06/09 22:43:19 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iteration_mandel(t_fractol mlx)
{
	double	x;
	double	y;
	double	x0;
	double	y0;
	double	xtmp;

	x = 0;
	y = 0;
	x0 = mlx.xmin + mlx.x * (mlx.xmax - mlx.xmin) / 800;
	y0 = mlx.ymin + mlx.y * (mlx.ymax - mlx.ymin) / 800;
	mlx.iteration = 0;
	while (x * x + y * y <= 2 * 2 && mlx.iteration < 200)
	{
		xtmp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = xtmp;
		mlx.iteration++;
	}
	return (mlx.iteration);
}

int	ft_color2(t_fractol fractol, int iter)
{
	int		green;
	int		red;
	int		blue;
	double	t;

	iter = iteration_mandel(fractol);
	t = (double)iter / (double)200;
	red = (int)(9 * (1 - t) * t * t * t * 255);
	green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((red << 16) | (green << 8) | blue);
}

void	draw_mandel(t_fractol mlx)
{
	int	iteration;

	mlx_clear_window(mlx.mlx, mlx.mlx_win);
	mlx.y = 0;
	while (mlx.y < 800)
	{
		mlx.x = 0;
		while (mlx.x < 800)
		{
			iteration = iteration_mandel(mlx);
			if (iteration == 200)
				my_mlx_pixel_put(&mlx, mlx.x, mlx.y, 0x000000);
			else
				my_mlx_pixel_put(&mlx, mlx.x, mlx.y, ft_color2(mlx, iteration));
			mlx.x++;
		}
		mlx.y++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.mlx_img, 0, 0);
}
