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

/*z(n+1) = z(n)^2 + c*/

void	mandelbrot(t_list *mlx)
{
//each iteration, it calculates: newz = oldz*oldz + p, where p is the current pixel, and oldz stars at the origin          
	int	max_iter;
	int y;
	int x;
	int i;
	//real and imaginary part of the pixel p
	double pr;
	double pi;

	y = 0;
	x = 0;
	i = 0;
	max_iter = 300; //after how much iterations the function should stop
	//loop through every pixel
	while (y < HEIGTH)
	{
		while(x < WIDTH)
		{
			//calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
			pr = 1.5 * (x - WIDTH / 2) / (0.5 * mlx->zoom * WIDTH) + mlx->shift_x;
			pi = (y - HEIGTH / 2) / (0.5 * mlx->zoom * HEIGTH) + mlx->shift_y;
			mlx->new_re = mlx->new_im = mlx->old_re = mlx->old_im = 0; //these should start at 0,0
			//"i" will represent the number of iterations
			//start the iteration process
			while(i < max_iter)
			{
				//remember value of previous iteration
				mlx->old_re = mlx->new_re;
				mlx->old_im = mlx->new_im;
				//the actual iteration, the real and imaginary part are calculated
				mlx->new_re = mlx->old_re * mlx->old_re - mlx->old_im * mlx->old_im + pr;
				mlx->new_im = 2 * mlx->old_re * mlx->old_im + pi;
				//if the point is outside the circle with radius 2: stop
				if((mlx->new_re * mlx->new_re + mlx->new_im * mlx->new_im) > 4) break;
				i++;
			}
			//use color model conversion to get rainbow palette, make brightness black if maxIterations reached
			mlx->blue = i % 256;
			mlx->green = 255;
			mlx->red = 255 * (i < max_iter);
			//draw the pixel
			//mlx_pixel_put(mlx, x, y, color);
			ft_putpixel(mlx, x, y);
			x++;
		}
		y++;
	}
}

void	ft_putpixel(t_list *mlx, int x, int y)
{
	int		pos;
	char	*img;

	pos = (mlx->bpp / 8) * x;
	if (y)
		pos += y * mlx->size;
	img = mlx->image;
	img[pos] = (char)mlx->red; // Red
	img[pos + 1] = (char)mlx->green; // Green
	img[pos + 2] = (char)mlx->blue; // Blue
}