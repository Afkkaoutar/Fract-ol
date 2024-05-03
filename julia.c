/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:16:11 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/05/02 18:49:21 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int iteration_julia(t_fractol *mlx)
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
    while(x0*x0 + y0*y0 <= 2*2 && i < 100)
    {
        xtemp = x0*x0 - y0*y0 + mlx->a;
        y0 = 2*x0*y0 + mlx->b;
        x0 = xtemp;
        i++;
    }
    return i;
}

void draw_julia(t_fractol *mlx)
{
    int iteration;
    mlx->y = 0;
    while (mlx->y < 700)
    {
        mlx->x = 0;
        while (mlx->x < 700)
        {
            iteration = iteration_julia(mlx);
            if (iteration == 100)
                my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x3B22aa * iteration);
            else
                my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0xFBF3F2 * iteration);
            mlx->x++;
        }
        mlx->y++;
    }
}