/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:58:24 by fmarggra          #+#    #+#             */
/*   Updated: 2023/12/05 15:25:32 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define RED 2
# define BLUE 1
# define GREEN 3
# define OTHER 10
# define HEIGHT 500
# define WIDTH 500
# define MANDELBROT 0
# define JULIA 1
# define BS 2
# define RANGE 50

typedef struct s_number
{
	double		re;
	double		im;
}	t_number;

typedef struct s_data
{
	double	pi;
	double	pr;
}	t_data;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	void		*loop;
	void		*img;
	void		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	double		zoom;
	int			fractol;
	double		shift_x;
	double		shift_y;
	int			x;
	int			y;
	int			mouse_x;
	int			mouse_y;
	int			shift_image;
	double		new_re;
	double		new_im;
	double		old_im;
	double		old_re;
	int			max_iter;
	int			col;
	int			i;
	double		pr;
	double		pi;
	int			color_param;
}	t_list;

//setup
int		main(int argc, char *argv[]);
int		valid_fractol(char *argv[]);
int		init_struct(t_list *mlx, char *argv[], int argc);
void	params(void);
void	setup_fractal(t_list *mlx, char *argv[], int argc);
void	setup_julia(t_list *mlx, char *argv[], int argc);
void	help(void);
int		cleanup(t_list *mlx);
void	init_mlx(t_list *mlx);

//image
void	put_image(t_list *mlx);
void	move_window(int keycode, t_list *mlx);
void	my_mlx_pixel_put(t_list *mlx, int x, int y, int color);
void	mandelbrot(t_list *mlx);
void	julia(t_list *mlx);
void	calculate_set_mb(t_list *mlx, t_number *old, t_number *new);
void	calculate_set_julia(t_list *mlx, t_number *old, t_number *new);
void	mandelbrot_setup(t_list *mlx);
void	calc_pi_pr(t_list *mlx);
void	calc_pi_pr_julia(t_list *mlx);
void	calculate_set_bs(t_list *mlx, t_number *old, t_number *new);
void	burningship(t_list *mlx);
void	calc_pi_pr_bs(t_list *mlx);

//events
void	events(t_list *mlx);
int		zoom(int button, t_list *mlx);
int		no_event(void *data);
int		follow_mouse(int x, int y, t_list *mlx);
int		mouse_release(int button, int x, int y, t_list *mlx);
int		mouse_down(int button, int x, int y, t_list *mlx);
int		redraw_image(int x, int y, t_list *mlx);
int		mouse(int button, int x, int y, t_list *mlx);
void	mix_colors(t_list *mlx, int i, int color);

//color
int		c_rgb(int r, int g, int b);

//libft
int		ft_strncmp(char *s1, const char *s2, size_t n);
double	ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif
