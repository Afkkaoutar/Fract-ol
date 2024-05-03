/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 01:00:29 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/05/02 20:17:01 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fractol.h"

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	apply_zoom(t_fractol *mlx, double x, double y)
{
	x = (double)x / (1000 / (mlx->xmx - mlx->xmn)) + mlx->xmn;
	y = (double)y / (1000 / (mlx->ymx - mlx->ymn)) + mlx->ymn;
	mlx->xmn = interpolate(x, mlx->xmn, mlx->interpolation);
	mlx->ymn = interpolate(y, mlx->ymn, mlx->interpolation);
	mlx->xmx = interpolate(x, mlx->xmx, mlx->interpolation);
	mlx->ymx = interpolate(y, mlx->ymx, mlx->interpolation);
}