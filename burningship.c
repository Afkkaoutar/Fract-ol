/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:29:24 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/06/09 22:38:17 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iter_burningship(t_fractol *mlx)
{
	double	x;
	double	y;
	double	x0;
	double	y0;
	double	xtemp;

	x = 0;
	y = 0;
	mlx->iteration = 0;
	x0 = mlx->xmin + mlx->x * (mlx->xmax - mlx->xmin) / 800;
	y0 = mlx->ymin + mlx->y * (mlx->ymax - mlx->ymin) / 800;
	while (x * x + y * y < 4 && mlx->iteration < 100)
	{
		xtemp = x * x - y * y + x0;
		y = fabs(2 * x * y) + y0;
		x = xtemp;
		mlx->iteration++;
	}
	return (mlx->iteration);
}

void	draw_burningship(t_fractol mlx)
{
	int	iteration;

	mlx_clear_window(mlx.mlx, mlx.mlx_win);
	mlx.y = 0;
	while (mlx.y < 800)
	{
		mlx.x = 0;
		while (mlx.x < 800)
		{
			iteration = iter_burningship(&mlx);
			if (iteration == 100)
				my_mlx_pixel_put(&mlx, mlx.x, mlx.y, 0x000000);
			else
				my_mlx_pixel_put(&mlx, mlx.x, mlx.y, 0xaaaaaa * iteration);
			mlx.x++;
		}
		mlx.y++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.mlx_img, 0, 0);
}
