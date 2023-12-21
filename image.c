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
	if (mlx->img == NULL)
		cleanup(mlx);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->line_length, &mlx->endian);
	if (mlx->addr == NULL)
		cleanup(mlx);
	if (mlx->fractol == MANDELBROT)
		mandelbrot(mlx);
	else if (mlx->fractol == JULIA)
		julia(mlx);
	else if (mlx->fractol == BS)
		burningship(mlx);
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

int	zoom(int button, t_list *mlx)
{
	double	mouse_x_norm;
	double	mouse_y_norm;
	double	zoom_factor;

	zoom_factor = 1;
	if (mlx->mouse_x <= WIDTH && mlx->mouse_y <= HEIGHT
		&& mlx->mouse_x >= 0 && mlx->mouse_y >= 0)
	{
		if (button == Button5 && mlx->zoom > 0.0005)
			zoom_factor *= 0.95;
		else if (button == Button4 && mlx->zoom < 2147483647)
			zoom_factor *= 1.05;
		else
			return (0);
	}
	mouse_x_norm = (mlx->mouse_x - WIDTH / 2) / (0.5 * mlx->zoom * WIDTH);
	mouse_y_norm = (mlx->mouse_y - HEIGHT / 2) / (0.5 * mlx->zoom * HEIGHT);
	mlx->shift_x -= mouse_x_norm * (1 - zoom_factor);
	mlx->shift_y -= mouse_y_norm * (1 - zoom_factor);
	mlx->zoom *= zoom_factor;
	put_image(mlx);
	return (0);
}

void	my_mlx_pixel_put(t_list *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}
