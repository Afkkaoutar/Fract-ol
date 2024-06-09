/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:58:46 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/06/09 19:05:31 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	keys(int key, t_fractol *mlx)
{
	if (key == 124)
	{
		mlx->xmin += 0.05;
		mlx->xmax += 0.05;
	}
	if (key == 123)
	{
		mlx->xmin -= 0.05;
		mlx->xmax -= 0.05;
	}
	if (key == 126)
	{
		mlx->ymax -= 0.05;
		mlx->ymin -= 0.05;
	}
	if (key == 125)
	{
		mlx->ymax += 0.05;
		mlx->ymin += 0.05;
	}
}

int	key(int key, t_fractol *mlx)
{
	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		exit(0);
	}
	keys(key, mlx);
	draw_fractals(mlx->ac, *mlx);
	return (0);
}

int	mouse(int key, int x, int y, t_fractol *mlx)
{
	if (key == 4)
		mlx->interpolation = 1.2;
	else if (key == 5)
		mlx->interpolation = 0.8;
	else
		return (0);
	apply_zoom(mlx, x, y);
	draw_fractals(mlx->ac, *mlx);
	return (0);
}
