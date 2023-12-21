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

void	burningship(t_list *mlx)
{
	t_number	old;
	t_number	new;
	int			i;

	i = 0;
	mlx->x = 0;
	mlx->y = 0;
	while (mlx->y < HEIGHT)
	{
		while (mlx->x < WIDTH)
		{
			calc_pi_pr_bs(mlx);
			calculate_set_bs(mlx, &old, &new);
			my_mlx_pixel_put(mlx, mlx->x, mlx->y, mlx->col);
			mlx->x++;
		}
		mlx->x = 0;
		mlx->y++;
	}
}

void	calc_pi_pr_bs(t_list *mlx)
{
	mlx->pr = 1 * (mlx->x - WIDTH / 2) / (0.5 * mlx->zoom * WIDTH);
	mlx->pr += mlx->shift_x - 0.5;
	mlx->pi = 1 * (mlx->y - HEIGHT / 2) / (0.5 * mlx->zoom * HEIGHT);
	mlx->pi += mlx->shift_y;
}

void	calculate_set_bs(t_list *mlx, t_number *old, t_number *new)
{
	double	i;

	i = 0;
	new->re = 0;
	new->im = 0;
	old->re = 0;
	old->im = 0;
	while (i < mlx->max_iter)
	{
		old->re = new->re;
		old->im = new->im;
		new->re = fabs(old->re * old->re - old->im * old->im + mlx->pr);
		new->im = fabs(2 * old->re * old->im + mlx->pi);
		if (new->re * new->re + new->im * new->im > 4)
			break ;
		i++;
	}
	mix_colors(mlx, i, mlx->color_param);
}
