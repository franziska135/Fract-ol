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

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	mix_colors(t_list *mlx, int i, int color)
{
	if (color == BLUE)
	{
		if (i == mlx->max_iter)
			mlx->color = create_trgb(255, 7, 15, 48);
		else
			mlx->color = create_trgb(255,(i *2) % 255, (i *2) % 255, (i * i + 50) % 255);
	}
	else if (color == RED)
	{
		if (i == mlx->max_iter)
			mlx->color = create_trgb(255, 48, 10, 7);
		else
			mlx->color = create_trgb(255,(i * i + 50) % 255, (i * 2) % 255, (i * 2) % 255);
	}
	else if (color == GREEN)
	{
		if (i == mlx->max_iter)
			mlx->color = create_trgb(255, 15, 70, 5);
		else
			mlx->color = create_trgb(255,(i * 4) % 255, (i * i + 50) % 255, (i * 2) % 255);
	}
}
