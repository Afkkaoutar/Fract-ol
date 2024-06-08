/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:58:46 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/06/08 02:34:44 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void keys(int key, t_fractol *mlx)
{
    if (key == 124)
    {
        mlx->xmin += 0.2;
        mlx->xmax += 0.2;
    }
    if (key == 123)
    {
        mlx->xmin -= 0.2;
        mlx->xmax -= 0.2;
    }
    if (key == 126)
    {
        mlx->ymax -= 0.2;
        mlx->ymin -= 0.2;
    }
    if (key == 125)
    {
        mlx->ymax += 0.2;
        mlx->ymin += 0.2;
    }
}

int key(int key, t_fractol *mlx)
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

double interpolation(double start, double end, double interpolation)
{
    return(start + ((end - start) * interpolation));
}

void    apply_zoom(t_fractol *mlx, double x, double y)
{
    x = (double)x / (800 / (mlx->xmax - mlx->xmin)) + mlx->xmax;
    y = (double)y / (800 / (mlx->ymax - mlx->ymin) + mlx->ymin);
    mlx->xmin = interpolation(x, mlx->xmin, mlx->interpolation);
    mlx->ymin = interpolation(y, mlx->ymin, mlx->interpolation);
    mlx->xmax = interpolation(x, mlx->xmax, mlx->interpolation);
    mlx->ymax = interpolation(x, mlx->ymax, mlx->interpolation);
}

int mouse(int key, int x, int y, t_fractol *mlx)
{
    if (key == 4)
        mlx->interpolation = 1.2;
    else if(key == 5)
        mlx->interpolation = 0.8;
    else 
        return(0);
    apply_zoom(mlx, x, y);
    draw_fractals(mlx->ac, *mlx);
    return(0);
}
