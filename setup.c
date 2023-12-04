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

int	valid_fractol(char *argv[])
{
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 1)
		return (1);
	else if (ft_strncmp(argv[1], "Julia", 5) == 1)
		return (1);
	else if (ft_strncmp(argv[1], "-h", 2) == 1 || 
		ft_strncmp(argv[1], "--help", 6) == 1)
		return (-1);
	else
		return (0);
}

void	help()
{
	write (2, "\n", 1);
	write (2, "[fractol] [if Julia: x] [if Julia: y]\n", 39);
	write (2, "d:\t\tdecrease resolution\n", 24);
	write (2, "i:\t\tincrease resolution\n", 24);
	write (2, "arrow keys:\tshift image\n", 24);
	write (2, "mouse scroll:\tzoom in/out\n", 26);
	write (2, "a || b || g:\tchange color scheme\n\n", 34);
	write(2, "[Julia]:\t -1.478 0\n", 19);
	write(2, "[Julia]:\t -0.162 1.04\n", 22);
	//write(2, "[Julia]:\t -0.12 -0.77\n\n", 22);
	write(2, "[Julia]:\t 0.28 0.008\n\n", 22);
}

void	params(void)
{
	write(2, "Mandelbrot\n", 11);
	write(2, "Julia\n", 6);
}

int	init_struct(t_list *mlx, char *argv[], int argc)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (0);
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "FRACT'OL");
	if (!mlx->win)
	 	return (free(mlx->ptr), 0);
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	if (!mlx->img)
		return (0);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_length, &mlx->endian);
	if (!mlx->addr)
		return (0);
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 1)
		mlx->fractol = MANDELBROT;
	else if (ft_strncmp(argv[1], "Julia", 5) == 1)
		mlx->fractol = JULIA;
	mlx->color_param = GREEN;
	if (argv[1])
		setup_fractal(mlx, argv, argc);
	return (1);
}

void	setup_fractal(t_list *mlx, char *argv[], int argc)
{
	mlx->shift_x = 0;
	mlx->shift_y = 0;
	mlx->zoom = 1;
	mlx->x = 0;
	mlx->y = 0;
	mlx->shift_image = 0;
	mlx->max_iter = 60;
	if (mlx->fractol == JULIA)
		setup_julia(mlx, argv, argc);
}

void	setup_julia(t_list *mlx, char *argv[], int argc)
{
	if (argc == 4)
	{
		mlx->pr = ft_atoi(argv[2]);
    	mlx->pi = ft_atoi(argv[3]);
		printf("pr%f", mlx->pr);
		printf("pi%f", mlx->pi);
	}
	else
	{
		mlx->pr = -0.79;
   		mlx->pi = -0.15;
	}
}
