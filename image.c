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

void	put_image(t_list *mlx, int color, int x, int y)
{
	int x_new = x + mlx->shift_x;
	int y_new = y + mlx->shift_y;
	//int zoom = mlx->zoom;
	
	put_black(mlx);
	while (y_new <= y + RANGE + mlx->shift_y)
	{
		while (x_new <= x + RANGE + mlx->shift_x)
		{
			mlx_pixel_put(mlx->ptr, mlx->win, x_new, y_new, color);
			x_new++;
		}
		x_new = x + mlx->shift_x;
		y_new++;
	}
	mlx->x = x + mlx->shift_x;
	mlx->y = y + mlx->shift_y;
}

void	put_black(t_list *mlx)
{
	int x = 0;
	int y = 0;

	while (y <= HEIGTH)
	{
		while (x <= WIDTH)
		{
			mlx_pixel_put(mlx->ptr, mlx->win, x, y, BLACK);
			x++;
		}
		x = 0;
		y++;
	}
}

void	move_window(int keycode, t_list *mlx)
{
	put_black(mlx);
	if (keycode == XK_Up)
		mlx->shift_y += 10;
	else if (keycode == XK_Down)
		mlx->shift_y -= 10;
	else if (keycode == XK_Left)
		mlx->shift_x -= 10;
	else if (keycode == XK_Right)
		mlx->shift_x += 10;
	put_image(mlx, RED, mlx->x, mlx->y);
	mlx->shift_x = 0;
	mlx->shift_y = 0;
}