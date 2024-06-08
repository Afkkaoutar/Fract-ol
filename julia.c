/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:26:59 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/06/08 02:27:41 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int iteration_julia(t_fractol mlx)
{
    double x;
    double y;
    double x0;
    double y0;
    double xtmp;
    int iteration;

    x = 0;
    y = 0;
    x0 = -2 + mlx.x * (mlx.xmax - mlx.xmin) / 800;
    y0 = -2 + mlx.y * (mlx.ymax - mlx.ymin) / 800;
    iteration = 0;
    while (x0*x0 + y0*y0 <= 2*2  && iteration < 700)
    {
        xtmp = x0*x0 - y0*y0 + mlx.reel;
        y0 = 2*x0*y0 + mlx.imaginaire;
        x0 = xtmp;
        iteration++;
    }
    return (iteration);
}

void    draw_julia(t_fractol mlx)
{
    mlx_clear_window(mlx.mlx, mlx.mlx_win);
    int iteration;

    mlx.y = 0;
    while(mlx.y < 800)
    {
        mlx.x = 0;
        while (mlx.x < 800)
        {
            iteration = iteration_julia(mlx);
            if (iteration == 700)
                my_mlx_pixel_put(&mlx, mlx.x, mlx.y, 0x000000);
            else
                my_mlx_pixel_put(&mlx, mlx.x, mlx.y, 0xfffee * iteration);
            mlx.x++;
        }
        mlx.y++;
    }
    mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.mlx_img, 0, 0);
}