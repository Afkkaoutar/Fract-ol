/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:53:23 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/05/02 18:48:38 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int iteration_burningship(t_fractol *mlx)
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
    while(x*x + y*y <= 2*2 && i < 300)
    {
        xtemp = x*x - y*y + x0;
        y = fabs(2*x*y) + y0;
        x = xtemp;
        i++;
    }
    return i;
}

void draw_burningship(t_fractol *mlx)
{
    int iteration;
    mlx->y = 0;
    while (mlx->y < 700)
    {
        mlx->x = 0;
        while (mlx->x < 700)
        {
            iteration = iteration_burningship(mlx);
            if (iteration == 300)
                my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x00000);
            else
                my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0xE6E6FA * iteration);
            mlx->x++;
        }
        mlx->y++;
    }
}

// 0123456789abcdef