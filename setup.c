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
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		return (1);
	else if (ft_strncmp(argv[1], "Julia", 5) == 0)
		return (1);
	else
		return (0);
}

void	params(void)
{
	write(2, "mandelbrot\n", 11);
	write(2, "julia\n", 6);
}

int	init_struct(t_list *mlx, char *argv[])
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (0);
	mlx->win = mlx_new_window(mlx->ptr, 500, 500, "FRACT'OL");
	if (!mlx->win)
		return (free(mlx->ptr), 0);
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 1)
		mlx->fractol = MANDELBROT;
	else if (ft_strncmp(argv[1], "julia", 5) == 1)
		mlx->fractol = JULIA;
	mlx->zoom = 1;
	mlx->x = 10;
	mlx->y = 50;
	mlx->shift_x = 0;
	mlx->shift_y = 0;
	return (1);
}
