/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:12:31 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/05/02 20:18:09 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <math.h>
#include <libc.h>
#include <mlx.h>


typedef struct s_fractol
{
    float a;
    float b;
    float x;
    float y;
    void *mlx;
    void *win;
    void *img;
    float	interpolation;
    float	xmn;
	float	ymn;
	float	xmx;
	float	ymx;
    char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    int     mandell;
    int     julia;
    int     burningship;
    int     julia1;
    int     julia2;
}               t_fractol;

int iteration_mandelbrot(t_fractol *mlx);
void draw_mandelbrot(t_fractol *mlx);
int	ft_strcmp(char *str1, char *str2);
void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
int iteration_julia(t_fractol *mlx);
void draw_julia(t_fractol *mlx);
int iteration_burningship(t_fractol *mlx);
void draw_burningship(t_fractol *mlx);
float	interpolate(float start, float end, float interpolation);
int key(int key, t_fractol *mlx);
void    which_julia(char **argv, t_fractol *mlx);
void	apply_zoom(t_fractol *mlx, double x, double y);

#endif