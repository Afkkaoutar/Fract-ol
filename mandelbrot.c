/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:42:19 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/06/08 02:30:17 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int iteration_mandel(t_fractol mlx)
{
    double x;
    double y;
    double x0;
    double y0;
    double xtmp;
    int iteration;

    x = 0;
    y = 0;
    x0 = mlx.xmin + mlx.x * (mlx.xmax - mlx.xmin) / 800;
    y0 = mlx.ymin + mlx.y * (mlx.ymax - mlx.ymin) / 800;
    iteration = 0;
    while (x*x + y*y <= 2*2  && iteration < 100)
    {
        xtmp = x*x - y*y + x0;
        y = 2*x*y + y0;
        x = xtmp;
        iteration++;
    }
    return (iteration);
}

void    draw_mandel(t_fractol mlx)
{
    mlx_clear_window(mlx.mlx, mlx.mlx_win);
    int iteration;

    mlx.y = 0;
    while(mlx.y < 800)
    {
        mlx.x = 0;
        while (mlx.x < 800)
        {
            iteration = iteration_mandel(mlx);
            if (iteration == 100)
                my_mlx_pixel_put(&mlx, mlx.x, mlx.y, 0x000000);
            else
                my_mlx_pixel_put(&mlx, mlx.x, mlx.y, 0xfffee * iteration);
            mlx.x++;
        }
        mlx.y++;
    }
    mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.mlx_img, 0, 0);
}