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

void	params(void)
{
	write(2, "Mandelbrot\n", 11);
	write(2, "Julia\n", 6);
	write(2, "Burningship\n\n", 12);
	write(2, "for help type -h or --help\n", 27);
}

void	help(void)
{
	write (2, "\n", 1);
	write (2, "[fractol] [if Julia: x] [if Julia: y]\n", 39);
	write (2, "d:\t\tdecrease resolution\n", 24);
	write (2, "i:\t\tincrease resolution\n", 24);
	write (2, "arrow keys:\tshift image\n", 24);
	write (2, "mouse scroll:\tzoom in/out\n", 26);
	write (2, "a || b || g:\tchange color scheme\n\n", 34);
	write(2, "[Julia]:\t -1.478 0\n", 19);
	write(2, "[Julia]:\t -0.162 1.04\n", 22);
	write(2, "[Julia]:\t -0.12 -0.77\n\n", 22);
	write(2, "[Julia]:\t 0.28 0.008\n\n", 22);
}

int	valid_fractol(char *argv[])
{
	if (ft_strncmp(argv[1], "Mandelbrot\0", 11) == 1)
		return (1);
	else if (ft_strncmp(argv[1], "Julia\0", 6) == 1)
		return (1);
	else if (ft_strncmp(argv[1], "Burningship\0", 12) == 1)
		return (1);
	else if (ft_strncmp(argv[1], "-h", 2) == 1
		|| ft_strncmp(argv[1], "--help", 6) == 1)
		return (2);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	t_list	mlx;

	init_mlx(&mlx);
	if (argc < 2 || valid_fractol(argv) == 0)
		return (params(), 0);
	if (valid_fractol(argv) == 2)
		return (help(), 0);
	if (init_struct(&mlx, argv, argc) == 0)
		return (cleanup(&mlx), 0);
	put_image(&mlx);
	events(&mlx);
	cleanup(&mlx);
	return (0);
}
