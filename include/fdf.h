/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:39:56 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/16 13:10:17 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* ************************************************************************** */
/*                              TITLE                                         */
/* ************************************************************************** */
# define TITLE "FDF madelmen"

/* ************************************************************************** */
/*                              DEFAULT VALUES                                */
/* ************************************************************************** */
//matrix
# define SCALE 10.0f
# define SCALE_STEP 1.0f
# define SPACE 25.0f
# define ISO_ANGLE 0.523599f

//zoom
# define Z_OUT 0.8f
# define Z_IN 1.2f
# define Z_DEFAULT 0.01f

//rotation
# define ROT_STEP 0.1f

//shift_map
# define SHIFT_STEP 10.0f

//sidebar_content
# define PADDING_X 20
# define PADDING_Y 40
# define PADDING_OF_X 100
# define PADDING_OF_Y 30
# define SPACE_TITLE 40
# define SPACE_CTRL 20

//window
# define INIT_WIN_W 640
# define INIT_WIN_H 360
# define MAX_WIN_W 1920
# define MAX_WIN_H 1080

/* ************************************************************************** */
/*                              OWN LIB                                       */
/* ************************************************************************** */
# include "../lib/libftprintf/include/ft_printf.h"
# include "../lib/libftprintf/libft/libft.h"

/* ************************************************************************** */
/*                              SHOOL GRAPH. LIB                              */
/* ************************************************************************** */
# include "../lib/minilibx-linux/mlx.h"

/* ************************************************************************** */
/*                              HEADER UTILS                                  */
/* ************************************************************************** */
# include "utils/ft_structs.h"
# include "utils/get_next_line.h"
# include "utils/keycode.h"
# include "utils/colors.h"

/* ************************************************************************** */
/*                             STANDAR LIB                                    */
/* ************************************************************************** */
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

/* ************************************************************************** */
/*                              CORE                                          */
/* ************************************************************************** */
int			init_app(t_app *app, char *filename);
int			init_map(t_app *app, char *filename);
int			init_mlx(t_app *app);
int			init_event(t_app *app);
int			init_data_sidebar(t_app *app);
void		init_matrix(t_app *app);
void		cleanup_app(t_app *app);

/* ************************************************************************** */
/*                              EVENTS                                        */
/* ************************************************************************** */
int			handle_exit(t_app *app);
int			handle_key(int keycode, void *param);
int			handle_mouse(int keycode, int x, int y, void *param);

/* ************************************************************************** */
/*                              MAP CONTROLS                                  */
/* ************************************************************************** */
void		rotate_map(t_app *app, int direction);
void		shift_map(t_app *app, int direction);
void		scale_map(t_app *app, int direction);
void		change_sidebar_color(t_app *app);
void		change_grid_color(t_app *app);

/* ************************************************************************** */
/*                             WINDOW CONTROLS                                */
/* ************************************************************************** */
int			resize_win(t_app *app);

/* ************************************************************************** */
/*                              VIEWS CONTROLS                                */
/* ************************************************************************** */
void		toggle_view(t_app *app, int views_mode);
void		zoom(t_app *app, float factor);

/* ************************************************************************** */
/*                              RENDER                                        */
/* ************************************************************************** */
int			render(t_app *app);

/* ************************************************************************** */
/*                              MATRIX                                        */
/* ************************************************************************** */
t_point		matrix(t_app *app, int x, int y);

/* ************************************************************************** */
/*                              DRAWER                                        */
/* ************************************************************************** */
void		draw_map(t_app *app);
void		draw_sidebar(t_app *app);
void		draw_line(t_app *app, t_point start, t_point end);
void		put_pixel(t_app *app, int x, int y, int color);
void		put_pixel_rgba(t_app *app, int x, int y, int color);

/* ************************************************************************** */
/*                              PRINT                                         */
/* ************************************************************************** */
void		print_live_values(t_app *app, int start_y);
int			print_controls(t_app *app);

/* ************************************************************************** */
/*                              PARSING                                       */
/* ************************************************************************** */
int			parsing_z(t_app *app, char *z_value, int num_line, int col);
int			parse_file(t_app *app, char *filename);

/* ************************************************************************** */
/*                              UTILS                                         */
/* ************************************************************************** */
char		*get_next_line(int fd);
int			error_exit(int error);
int			count_line(t_app *app, const char *filename);

#endif
