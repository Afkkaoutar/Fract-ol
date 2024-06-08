/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:47:05 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/06/08 02:29:01 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H 

#include <unistd.h>
#include <mlx.h>
#include <libc.h>
#include <math.h>


typedef struct s_fractol
{
    int ac;
    int whish_fractol;
    double  reel;
    double  imaginaire;
    void    *mlx;
    void    *mlx_win;
    void    *mlx_img;
    char    *addr;
    int     bits_per_pixel;
    int     line_lentgh;
    int     endian;
    int    x;
    int    y;
    double  xmax;
    double  xmin;
    double  ymax;
    double  ymin;
    double	interpolation;
} t_fractol;

void	my_mlx_pixel_put(t_fractol *mlx, int x, int y, int color);
void    draw_mandel(t_fractol data);
void    draw_julia(t_fractol mlx);
void    draw_burningship(t_fractol mlx);
int     key(int key, t_fractol *mlx);
void    draw_fractals(int ac, t_fractol mlx);
int     mouse(int key, int x, int y, t_fractol *mlx);

#endif