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

// void	calc_pixel(t_list *mlx)
// {
// 	int x;
// 	int y;
// 	double	re;
// 	double	im;

// 	x = 0;
// 	while (x <= WIDTH)
// 	{
// 		y = 0;
// 		while (y <= HEIGTH)
// 		{
// 			//rescale_pixel(x, y, mlx);
// 			re = (((0.5 - (-2)) * x) / ((double)WIDTH)) + (-2);
// 			im = (((((-1.5) - 1.5) * y) / ((double)HEIGTH)) + 1.5);
// 			y++;
// 		}
// 		x++;
// 	}
// }

int	main(int argc, char *argv[])
{
	t_list	mlx;

	if (argc < 2 || valid_fractol(argv) == 0)
	 	return (params(), 0);
	if (init_struct(&mlx, argv) == 0)
		return (0);
	put_image(&mlx, RED, mlx.x, mlx.y);
	events(&mlx);
	(free(mlx.ptr), free(mlx.win));
	return (0);
}
