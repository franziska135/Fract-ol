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

int	shutdown(t_list *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	free(mlx->ptr);
	//free(mlx->win); mall
	exit (1);
	return (0);
}

int	key_press(int keycode, t_list *mlx)
{
	if (keycode == XK_Escape)
		shutdown(mlx);
	else if (keycode == XK_Up || keycode == XK_Down || keycode == XK_Left
		|| keycode == XK_Right)
	{
		move_window(keycode, mlx);
		return (0);
	}
	//printf("keycode: %d\n", keycode);
	else if (keycode == XK_i)
		mlx->max_iter += 10;
	else if (keycode == XK_d)
		mlx->max_iter -= 10;
	else if (keycode == XK_r)
		mlx->color_param = RED;
	else if (keycode == XK_b)
		mlx->color_param = BLUE;
	else if (keycode == XK_g)
		mlx->color_param = GREEN;
	put_image(mlx);
	return (0);
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
		{
			zoom_factor *= 0.95;
		}
		else if (button == Button4 && mlx->zoom < 2147483647)
		{
			zoom_factor *= 1.05;
		}
		else
			return (0);
	}
	mouse_x_norm = (mlx->mouse_x - WIDTH / 2) / (0.5 * mlx->zoom * WIDTH);
	mouse_y_norm = (mlx->mouse_y - HEIGHT / 2) / (0.5 * mlx->zoom * HEIGHT);
	mlx->shift_x -= mouse_x_norm * (1 - zoom_factor);
	mlx->shift_y -= mouse_y_norm * (1 - zoom_factor);
	mlx->zoom *= zoom_factor; 
	//printf("zoom:%f\n", mlx->zoom);
	put_image(mlx);
	return (0);
}
int	follow_mouse(int x, int y, t_list *mlx)
{
	mlx->mouse_x = x;
	mlx->mouse_y = y;
	if (mlx->shift_image == 1)
		put_image(mlx);
	return (0);
}

int	mouse(int button, int x, int y, t_list *mlx)
{
	if (button == Button1)
	{
		if (x > WIDTH || y > HEIGHT)
			return (0);
		put_image(mlx);
		mlx->shift_image = 1;
		//printf("shift: %d\n", mlx->shift_image);
	}
	if (button == Button4 || button == Button5)
		zoom(button, mlx);
	return (0);
}

int	mouse_release(int button, int x, int y, t_list *mlx)
{
	if (button == Button1)
		mlx->shift_image = 0;
	//printf("released %d\n", mlx->shift_image);
	if (x < 0 || y < 0)
		return (0);
	return (0);
}
//02: KeyPress
//17: Destroy Notify
//04: Button press
//05: Button Release
//06: Motion Notify
//0L: no event mask
//1L << 0: Keypress Mask
//1L << 8: Button1Motion Mask
//1L<<13: ButtonMotion Mask

void	events(t_list *mlx)
{
	mlx_hook(mlx->win, 2, 1L << 0, (key_press), mlx);
	mlx_hook(mlx->win, 17, 1L << 8, (shutdown), mlx);
	mlx_hook(mlx->win, 4, 1L<<2, (mouse), mlx);
	mlx_hook(mlx->win, 5, 1L<<3, (mouse_release), mlx);
	mlx_hook(mlx->win, 6, 1L<<6, (follow_mouse), mlx);
	//mlx_hook(mlx->win, 4, (1L<<2), (mouse_down), mlx);
	//mlx_mouse_hook(mlx->win, (mouse), mlx);
	mlx_loop(mlx->ptr);
}
