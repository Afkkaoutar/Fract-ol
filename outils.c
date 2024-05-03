#include "fractol.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void draw_again(t_fractol *mlx)
{
	if (mlx->burningship == 1)
		draw_burningship(mlx);
	else if(mlx->mandell == 1)
		draw_mandelbrot(mlx);
	else if(mlx->julia == 1)
	{
        mlx->a = 0;
        mlx->b = 0.8;
        draw_julia(mlx);
    }
	else if (mlx->julia1 == 1)
	{
        mlx->a = -0.70176;
		mlx->b = -0.3842;
        draw_julia(mlx);
    }
	else if (mlx->julia2 == 1)
    {
        mlx->a = 0.285;
		mlx->b = 0.01;
        draw_julia(mlx);
    }
}

int key(int key, t_fractol *mlx)
{
    if (key == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
    else if (key == 124)
    {
		mlx->xmn = mlx->xmn - 0.2;
		mlx->xmn = mlx->xmx - 0.2;
    }
    else if (key == 123)
    {
        mlx->xmn = mlx->xmn + 0.2;
		mlx->xmx = mlx->xmx + 0.2;
    }
    else if (key == 126)
    {
        mlx->ymx = mlx->ymx + 0.2;
		mlx->ymn = mlx->ymn + 0.2;
    }
    else if (key == 125)
    {
        mlx->ymx = mlx->ymx - 0.2;
		mlx->ymn = mlx->ymn - 0.2;
    }
	draw_again(mlx);
	return 0;
    // 124 123 126 125
}