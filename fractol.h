/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:58:24 by fmarggra          #+#    #+#             */
/*   Updated: 2023/11/24 13:58:51 by fmarggra         ###   ########.fr       */
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

# define RED 0xFF0000
# define BLUE 1
# define GREEN 0x00FF00
# define BLACK 0x000000
# define OTHER 10

//X11events
# define KEYPRESS 2
# define DESTROY_NOTIFY 17
// # define KEY_PRESS 1L<<0
// # define BUTTON_1 1L<<8

//X11masks
// # define XK_ESCAPE 0xff1b
// # define XK_UP 0xff52
// # define XK_DOWN 0xff54
// # define XK_RIGHT 0xff53
// # define XK_LEFT 0xff51
# define HEIGHT 400
# define WIDTH 400
# define MANDELBROT 0
# define JULIA 1
# define DOWN 0
# define UP 1
# define LEFT 2
# define RIGHT 3
# define RANGE 50

typedef struct s_number
{
	double		re;
	double		im;
}	t_number;

typedef struct s_col
{
	char	t;
	char	r;
	char	g;
	char	b;
}	t_col;

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
	int			color;
	int			i;
	double		pr;
	double		pi;
	int			color_param;
	int			r;
	int			g;
	int			b;
}	t_list;

int		main(int argc, char *argv[]);
int		valid_fractol(char *argv[]);
int		init_struct(t_list *mlx, char *argv[], int argc);
void	params(void);
void	setup_fractal(t_list *mlx, char *argv[], int argc);
// void	setup_color(t_list *mlx, char *argv[]);
void	setup_julia(t_list *mlx, char *argv[], int argc);
void	help();

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

//events
void	events(t_list *mlx);
int		zoom(int button, t_list *mlx);
int		no_event(void *data);
int		shutdown(t_list *mlx);
int		follow_mouse(int x, int y, t_list *mlx);
int		mouse_release(int button, int x, int y, t_list *mlx);
int		mouse_down(int button, int x, int y, t_list *mlx);
int		redraw_image(int x, int y, t_list *mlx);
int		mouse(int button, int x, int y, t_list *mlx);
void	mix_colors(t_list *mlx, int i, int color);

//color
int		create_trgb(int t, int r, int g, int b);

//libft
int		ft_strncmp(char *s1, const char *s2, size_t n);
double	ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif
