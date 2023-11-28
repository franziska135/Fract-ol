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
#include <X11/X.h>
#include <X11/keysym.h>

# define RED 0xFF0000
# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define BLACK 0x000000

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
# define HEIGTH 500
# define WIDTH 500
# define MANDELBROT 0
# define JULIA 1
# define DOWN 0
# define UP 1
# define LEFT 2
# define RIGHT 3
# define RANGE 50

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	int			pixel;
	void		*image;
	void		*loop;
	double		zoom;
	int			fractol;
	int			shift_x;
	int			shift_y;
	int			x;
	int			y;
	int			mouse_x;
	int			mouse_y;
	int			shift_image;
	double		z_real;
	double		z_im;
	double		new_re;
	double		new_im;
	double		old_im;
	double		old_re;
	int			blue;
	int			green;
	int			red;
}	t_list;

int		main(int argc, char *argv[]);
int		valid_fractol(char *argv[]);
int		init_struct(t_list *mlx, char *argv[]);
void	params(void);

//image
void	put_image(t_list *mlx, int color, int x, int y);
void	put_black(t_list *mlx);
void	move_window(int keycode, t_list *mlx);

//events
void	events(t_list *mlx);
int		zoom(int button, t_list *mlx);
int		no_event(void *data);
int		shutdown(t_list *mlx);
int		follow_mouse(int x, int y, t_list *mlx);
int		mouse_up(int button, int x, int y, t_list *mlx);
int		mouse_down(int button, int x, int y, t_list *mlx);
int		redraw_image(int x, int y, t_list *mlx);
int		mouse(int button, int x, int y, t_list *mlx);

//libft
int		ft_strncmp(char *s1, const char *s2, size_t n);

#endif
