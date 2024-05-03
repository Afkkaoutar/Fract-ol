/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:14:38 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/05/02 19:10:25 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include <libc.h>

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int destroy(t_fractol *mlx)
{
    mlx_clear_window(mlx->mlx, mlx->win);
    exit(0);
    return 0;
}

void    which_julia(char **argv, t_fractol *mlx)
{
    if (ft_strcmp("julia", argv[1]) == 0)
    {
        mlx->julia = 1;
        mlx->a = 0;
        mlx->b = 0.8;
        draw_julia(mlx);
    }
    else if (ft_strcmp("julia1", argv[1]) == 0)
    {
        mlx->julia1 = 1;
        mlx->a = -0.70176;
		mlx->b = -0.3842;
        draw_julia(mlx);
    }
    else if (ft_strcmp("julia2", argv[1]) == 0)
    {
        mlx->julia2 = 1;
        mlx->a = 0.285;
		mlx->b = 0.01;
        draw_julia(mlx);
    }
}

void    check_argv(char **argv, t_fractol *mlx)
{
    if (ft_strcmp(argv[1], "Mandelbrot") == 0)
    { 
        draw_mandelbrot(mlx);
        mlx->mandell = 1;
        // write(1, "Mandelbrot", 10);
    }
    else if (ft_strcmp(argv[1], "julia") == 0 || ft_strcmp(argv[1], "julia1") == 0 || ft_strcmp(argv[1], "julia2") == 0)
    {
        which_julia(argv, mlx);
        mlx->julia = 1;
        // draw_julia(mlx);
        // write(1, "julia", 5);   
    }
    else if (ft_strcmp(argv[1], "burningship") == 0)
    {
        draw_burningship(mlx);
        mlx->burningship = 1;
        // write(1, "burningship", 11);
    }
    else
    {
        write(1, "ERROR : ", 8);
        write(1, "entre one of the folowing fractal \n \tjulia\n \tMandelbrot\n \tburningship", 70);
        exit(0);
    }
}


int main(int argc, char **argv)
{
    t_fractol *mlx;
    if (argc != 2)
    {
        write(1, "ERROR : ", 8);
        write(1, "./fract-ol <fractal name>", 26);
        return 0;
    }
    mlx = malloc(sizeof(t_fractol));
    if(!mlx)
        return 0;
    mlx->julia = 0;
    mlx->julia1 = 0;
    mlx->julia2 = 0;
    mlx->mandell = 0;
    mlx->burningship = 0;
    mlx->xmn = -2;
    mlx->xmx = 2;
    mlx->ymn = -2;
    mlx->ymx = 2;
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, 700, 700, "Fractol");
    mlx->img = mlx_new_image(mlx->mlx, 700, 700);
    mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
    check_argv(argv, mlx);
    // draw_mandelbrot(mlx);
    // draw_burningship(mlx);
    // draw_julia(mlx);
    
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
    // mlx_hook(mlx->win, 17, 0, destroy, mlx);
    mlx_key_hook(mlx->win, key, mlx);
    mlx_loop(mlx->mlx);
}
