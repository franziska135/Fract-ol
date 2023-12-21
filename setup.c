/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:46:53 by fmarggra          #+#    #+#             */
/*   Updated: 2023/11/24 13:51:56 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_list *mlx)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->loop = NULL;
	mlx->img = NULL;
	mlx->addr = NULL;
}

int	init_struct(t_list *mlx, char *argv[], int argc)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (0);
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "FRACT'OL");
	if (!mlx->win)
		return (cleanup(mlx), 0);
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	if (!mlx->img)
		return (cleanup(mlx), 0);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->line_length, &mlx->endian);
	if (!mlx->addr)
		return (cleanup(mlx), 0);
	if (ft_strncmp(argv[1], "Mandelbrot\0", 11) == 1)
		mlx->fractol = MANDELBROT;
	else if (ft_strncmp(argv[1], "Julia\0", 6) == 1)
		mlx->fractol = JULIA;
	else if (ft_strncmp(argv[1], "Burningship\0", 12) == 1)
		mlx->fractol = BS;
	setup_fractal(mlx, argv, argc);
	return (1);
}

void	setup_fractal(t_list *mlx, char *argv[], int argc)
{
	mlx->color_param = GREEN;
	mlx->shift_x = 0;
	mlx->shift_y = 0;
	mlx->zoom = 1;
	mlx->x = 0;
	mlx->y = 0;
	mlx->shift_image = 0;
	mlx->max_iter = 60;
	if (mlx->fractol == JULIA)
		setup_julia(mlx, argv, argc);
	if (mlx->fractol == BS)
	{
		mlx->zoom = 0.65;
		mlx->shift_y = -0.5;
		mlx->color_param = RED;
	}
}

void	setup_julia(t_list *mlx, char *argv[], int argc)
{
	if (argc == 4)
	{
		mlx->pr = ft_atoi(argv[2]);
		mlx->pi = ft_atoi(argv[3]);
	}
	else
	{
		mlx->pr = -0.79;
		mlx->pi = -0.15;
	}
}

int	cleanup(t_list *mlx)
{
	if (mlx)
	{
		if (mlx->img)
			mlx_destroy_image(mlx->ptr, mlx->img);
		if (mlx->win)
			mlx_destroy_window(mlx->ptr, mlx->win);
		if (mlx->ptr)
			mlx_destroy_display(mlx->ptr);
		if (mlx->ptr)
			free(mlx->ptr);
		if (mlx->loop)
			free(mlx->loop);
		exit(1);
	}
	return (0);
}
