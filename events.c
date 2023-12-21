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

int	key_press(int keycode, t_list *mlx)
{
	if (keycode == XK_Escape)
		cleanup(mlx);
	else if (keycode == XK_Up || keycode == XK_Down || keycode == XK_Left
		|| keycode == XK_Right)
	{
		move_window(keycode, mlx);
		return (0);
	}
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
	}
	if (button == Button4 || button == Button5)
		zoom(button, mlx);
	return (0);
}

int	mouse_release(int button, int x, int y, t_list *mlx)
{
	if (button == Button1)
		mlx->shift_image = 0;
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
	mlx_hook(mlx->win, 17, 1L << 8, (cleanup), mlx);
	mlx_hook(mlx->win, 4, 1L << 2, (mouse), mlx);
	mlx_hook(mlx->win, 5, 1L << 3, (mouse_release), mlx);
	mlx_hook(mlx->win, 6, 1L << 6, (follow_mouse), mlx);
	mlx_loop(mlx->ptr);
}
