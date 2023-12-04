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

void	put_image(t_list *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->ptr, mlx->img);
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_length, &mlx->endian);
	if (mlx->fractol == MANDELBROT)
		mandelbrot(mlx);
	else if (mlx->fractol == JULIA)
		julia(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
}

void	move_window(int keycode, t_list *mlx)
{
	double	adjusted;

	adjusted = 0.5;
	adjusted /= mlx->zoom;
	if (keycode == XK_Up)
		mlx->shift_y -= adjusted;
	else if (keycode == XK_Down)
		mlx->shift_y += adjusted;
	else if (keycode == XK_Left)
		mlx->shift_x -= adjusted;
	else if (keycode == XK_Right)
		mlx->shift_x += adjusted;
	put_image(mlx);
	mlx->x += mlx->shift_x;
	mlx->y += mlx->shift_y;
}