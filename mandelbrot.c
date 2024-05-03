/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:16:51 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/05/02 18:48:20 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int iteration_mandelbrot(t_fractol *mlx)
{
    float x;
    float y;
    float y0;
    float x0;
    float xtemp;
    int i;

    x0 = -2 + mlx->x * (mlx->xmx - mlx->xmn) / 700;
    y0 = -2 + mlx->y * (mlx->ymx - mlx->ymn) / 700;
    x = 0;
    y = 0;
    i = 0;
    while(x*x + y*y <= 2*2 && i < 30)
    {
        xtemp = x*x - y*y + x0;
        y = 2*x*y + y0;
        x = xtemp;
        i++;
    }
    return i;
}

void draw_mandelbrot(t_fractol *mlx)
{
    int iteration;
    mlx->y = 0;
    while (mlx->y < 700)
    {
        mlx->x = 0;
        while (mlx->x < 700)
        {
            iteration = iteration_mandelbrot(mlx);
            if (iteration == 30)
                my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x00000);
            else
                my_mlx_pixel_put(mlx, mlx->x, mlx->y,  0xaa3aeab * iteration);
            mlx->x++;
        }
        mlx->y++;
    }
}
