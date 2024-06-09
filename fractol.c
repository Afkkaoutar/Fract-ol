/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:11:42 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/06/09 23:30:13 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_wind(t_fractol *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit (0);
	return (0);
}

void	my_mlx_pixel_put(t_fractol *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_lentgh + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	check_av(char **av, t_fractol *mlx)
{
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
		return (1);
	if (ft_strcmp(av[1], "julia") == 0)
	{
		if (mlx->ac != 4)
		{
			write(1, "ERROR : ", 8);
			write(1, "./fract-ol julia <imaginaire> <reel>", 37);
			exit (0);
		}
		mlx->imaginaire = ft_atod(av[2]);
		mlx->reel = ft_atod(av[3]);
		return (2);
	}
	if (ft_strcmp(av[1], "burningship") == 0)
		return (3);
	else
	{
		write(1, "ERROR : ", 8);
		write(1, "./fract-ol <fractal name>", 26);
		exit (0);
	}
}

void	draw_fractals(int ac, t_fractol mlx)
{
	if (mlx.whish_fractol == 1 && ac == 2)
		draw_mandel(mlx);
	else if (mlx.whish_fractol == 3 && ac == 2)
		draw_burningship(mlx);
	else if (mlx.whish_fractol == 2 && ac == 4)
		draw_julia(mlx, mlx.reel, mlx.imaginaire);
	else
	{
		write(1, "ERROR : ", 8);
		write(1, "bad agrs", 8);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_fractol	mlx;

	if (ac == 1)
	{
		write(1, "ERROR : ", 8);
		write(1, "./fract-ol <fractal name>", 26);
		return (0);
	}
	mlx.ac = ac;
	mlx.xmax = 2;
	mlx.xmin = -2;
	mlx.ymax = 2;
	mlx.ymin = -2;
	mlx.whish_fractol = check_av(av, &mlx);
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, 800, 800, "fractol");
	mlx.mlx_img = mlx_new_image(mlx.mlx, 800, 800);
	mlx.addr = mlx_get_data_addr(mlx.mlx_img, &mlx.bits_per_pixel,
			&mlx.line_lentgh, &mlx.endian);
	draw_fractals(ac, mlx);
	mlx_hook(mlx.mlx_win, 17, 0, close_wind, &mlx);
	mlx_key_hook(mlx.mlx_win, key, &mlx);
	mlx_mouse_hook(mlx.mlx_win, mouse, &mlx);
	mlx_loop(mlx.mlx);
}
