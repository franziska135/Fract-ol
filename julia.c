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

void	julia(t_list *mlx)
{
	t_number	old;
	t_number	new;
	int			i;

	i = 0;
	mlx->x = 0;
	mlx->y = 0;
	//mlx->max_iter = 200;
	while (mlx->y < HEIGHT)
	{
		while (mlx->x < WIDTH)
		{
			calculate_set_julia(mlx, &old, &new);
			my_mlx_pixel_put(mlx, mlx->x, mlx->y, mlx->color);
			mlx->x++;
		}
		mlx->x = 0;
		mlx->y++;
	}
}

void calculate_set_julia(t_list *mlx, t_number *old, t_number *new)
{
    double i = 0;
    double	tmp;

   old->re = 1.9 * (mlx->x - WIDTH / 2) / (0.5 * mlx->zoom * WIDTH) + mlx->shift_x;
   old->im = 1.5 * (mlx->y - HEIGHT / 2) / (0.5 * mlx->zoom * HEIGHT) + mlx->shift_y;
   new->re = old->re;
   new->im = old->im;

   while (i < mlx->max_iter)
   {
       if ((new->re * new->re + new->im * new->im) > 4.0)
           break ;
       tmp = 2 * new->re * new->im + mlx->pi;
       new->re = new->re * new->re - new->im * new->im + mlx->pr;
       new->im = tmp;
       i++;
    }
    mix_colors(mlx, i, mlx->color_param);
}