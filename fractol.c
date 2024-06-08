 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:48:24 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/06/07 18:11:05 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_wind(t_fractol *mlx)
{
    mlx_destroy_window(mlx->mlx, mlx->mlx_win);
    exit(0);
    return(0);
}

double ft_atod(const char *str) {
    double num = 0.0;
    int sign = 1;
    int decimal = 0;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    while (str[i]!= '.' && str[i]!= '\0') {
        num = num * 10 + (str[i++] - '0');
    }
    if (str[i] == '.') {
        i++;
        decimal = 1;
    }
    while (str[i]!= '\0') {
        num = num * 10 + (str[i++] - '0');
        decimal *= 10;
    }
    if (decimal) {
        num /= decimal;
    }
    num *= sign;
    return num;
}

void	my_mlx_pixel_put(t_fractol *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_lentgh + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int check_av(char **av, t_fractol mlx)
{
    if (strcmp(av[1], "Mandelbrot") == 0)
        return (1);
    if (strcmp(av[1], "julia") == 0)
    {
        mlx.reel = ft_atod(av[2]);
        mlx.imaginaire = ft_atod(av[3]);
        return(2);
    }
    if (strcmp(av[1], "burningship") == 0)
        return(3);
    else
        return (0);
}

void    draw_fractals(int ac, t_fractol mlx)
{
    if (mlx.whish_fractol == 1 && ac == 2)
        draw_mandel(mlx);
    if (mlx.whish_fractol == 3 && ac == 2)
        draw_burningship(mlx);
    if (mlx.whish_fractol == 2 && ac == 4)
        draw_julia(mlx);
}



int main(int ac, char **av)
{
    t_fractol mlx;

    if (ac == 1)
    {
        write(1, "ERROR : ", 8);
        write(1, "./fract-ol <fractal name>", 26);
        return 0;
    }
    mlx.ac = ac;
    mlx.xmax = 2;
    mlx.xmin= -2;
    mlx.ymax = 2;
    mlx.ymin = -2;
    mlx.whish_fractol = check_av(av, mlx);
    if (mlx.whish_fractol == 0)
    {
        write(1, "ERROR : ", 8);
        write(1, "./fract-ol <fractal name>", 26);
        return 0;
    }
    mlx.mlx = mlx_init();
    mlx.mlx_win = mlx_new_window(mlx.mlx, 800, 800, "fractol");
    mlx.mlx_img = mlx_new_image(mlx.mlx, 800, 800);
    mlx.addr = mlx_get_data_addr(mlx.mlx_img, &mlx.bits_per_pixel, &mlx.line_lentgh, &mlx.endian);
    draw_fractals(ac, mlx);
    mlx_hook(mlx.mlx_win, 17, 0, close_wind, &mlx);
    mlx_key_hook(mlx.mlx_win, key, &mlx);
    mlx_mouse_hook(mlx.mlx_win, mouse, &mlx);
    mlx_loop(mlx.mlx);
}
