/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:04:31 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/06/09 22:33:26 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interpolation(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	apply_zoom(t_fractol *mlx, double x, double y)
{
	x = (double)x / (800 / (mlx->xmax - mlx->xmin)) + mlx->xmin;
	y = (double)y / (800 / (mlx->ymax - mlx->ymin)) + mlx->ymin;
	mlx->xmin = interpolation(x, mlx->xmin, mlx->interpolation);
	mlx->ymin = interpolation(y, mlx->ymin, mlx->interpolation);
	mlx->xmax = interpolation(x, mlx->xmax, mlx->interpolation);
	mlx->ymax = interpolation(y, mlx->ymax, mlx->interpolation);
}
