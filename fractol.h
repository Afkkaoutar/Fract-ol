/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:47:05 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/06/09 23:08:50 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H 

# include <unistd.h>
# include "minilibx_opengl_20191021/mlx.h"
# include <libc.h>
# include <math.h>

typedef struct s_fractol
{
	int		ac;
	int		whish_fractol;
	double	reel;
	double	imaginaire;
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lentgh;
	int		endian;
	int		x;
	int		y;
	double	xmax;
	double	xmin;
	double	ymax;
	double	ymin;
	double	interpolation;
	double	zoom;
	int		iteration;
}	t_fractol;

int		ft_strcmp(char *str1, char *str2);
void	my_mlx_pixel_put(t_fractol *mlx, int x, int y, int color);
void	draw_mandel(t_fractol data);
void	draw_julia(t_fractol mlx, double reel, double imaginaire);
double	ft_atod(char *str);
void	draw_burningship(t_fractol mlx);
int		key(int key, t_fractol *mlx);
void	draw_fractals(int ac, t_fractol mlx);
int		mouse(int key, int x, int y, t_fractol *mlx);
void	apply_zoom(t_fractol *mlx, double x, double y);
double	interpolation(double start, double end, double interpolation);

#endif