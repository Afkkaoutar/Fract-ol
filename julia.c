/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:26:59 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/06/09 22:38:10 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iter_julia(t_fractol *mlx, int px, int py, double reel, double imaginaire)
{
	double	x0;
	double	y0;
	double	xtemp;
	int		iteration;

	x0 = mlx->xmin + px * (mlx->xmax - mlx->xmin) / 800.0;
	y0 = mlx->ymin + py * (mlx->ymax - mlx->ymin) / 800.0;
	iteration = 0;

	while (x0 * x0 + y0 * y0 < 4 && iteration < 200)
	{
		xtemp = x0 * x0 - y0 * y0 + reel;
		y0 = 2 * x0 * y0 + imaginaire;
		x0 = xtemp;
		iteration++;
	}
	return (iteration);
}


void	draw_julia(t_fractol mlx, double reel, double imaginaire)
{
	int	i;

	mlx_clear_window(mlx.mlx, mlx.mlx_win);
	mlx.y = 0;
	while (mlx.y < 800)
	{
		mlx.x = 0;
		while (mlx.x < 800)
		{
			i = iter_julia(&mlx, mlx.x, mlx.y, reel, imaginaire);
			if (i == 200)
				my_mlx_pixel_put(&mlx, mlx.x, mlx.y, 0x000000);
			else
				my_mlx_pixel_put(&mlx, mlx.x, mlx.y, 0xFF0000 * i);
			mlx.x++;
		}
		mlx.y++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.mlx_img, 0, 0);
}
