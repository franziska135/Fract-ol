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

int	c_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	mix_colors(t_list *mlx, int i, int color)
{
	if (color == BLUE)
	{
		if (i == mlx->max_iter)
			mlx->col = c_rgb(1, 30, 60);
		else
			mlx->col = c_rgb((i * 1) % 255, (i * 2 + 10) % 255, (i * 5) % 255);
	}
	else if (color == RED)
	{
		if (i == mlx->max_iter)
			mlx->col = c_rgb(48, 1, 1);
		else
			mlx->col = c_rgb((i * 5 + 50) % 255, (i * 2) % 255, (i * 2) % 255);
	}
	else if (color == GREEN)
	{
		if (i == mlx->max_iter)
			mlx->col = c_rgb(1, 70, 20);
		else
			mlx->col = c_rgb((i * 1) % 255, (i * 5) % 255, (i * 2) % 255);
	}
}
