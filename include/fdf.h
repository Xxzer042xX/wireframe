/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:39:56 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/11 18:49:38 by madelmen         ###   LAUSANNE.ch       */
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
# define Z_OUT 0.8f
# define Z_IN 1.2f
# define SHIFT_STEP 10.0f
# define ROT_STEP 0.1f

/* ************************************************************************** */
/*                              DEFAULT COLOR                                 */
/* ************************************************************************** */
# define COLOR_GRID 0xFFFFFF
# define COLOR_MENU 0xFFFFFF

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
void		cleanup_app(t_app *app);

/* ************************************************************************** */
/*                              EVENTS                                        */
/* ************************************************************************** */
int			handle_exit(t_app *app);
int			handle_key(int keycode, void *param);
int			init_event(t_app *app);

/* ************************************************************************** */
/*                              MAP CONTROLS                                  */
/* ************************************************************************** */
void		rotate_map(t_app *app, int direction);
void		shift_map(t_app *app, int direction);

/* ************************************************************************** */
/*                              RENDER                                        */
/* ************************************************************************** */
t_point		matrix(t_app *app, int x, int y);
int			render(t_app *app);
void		draw_map(t_app *app);
void		draw_line(t_app *app, t_point start, t_point end);
void		toggle_view(t_app *app);
void		toggle_window_size(t_app *app);
void		zoom(t_app *app, float factor);
void		shift_map(t_app *app, int direction);
void		rotate_map(t_app *app, int direction);
void		put_pixel(t_app *app, int x, int y, int color);
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
