/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_live_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:47:03 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/14 20:25:12 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/fdf.h"

static void	print_zoom_value(t_app *app, int x_pos, int x_value_pos, int y_pos);
static void	print_rot_value(t_app *app, int x_pos, int x_value_pos, int y_pos);
static void	print_view_mode(t_app *app, int x_pos, int x_value_pos, int y_pos);
static void	print_scale_value(t_app *app, int x_pos, int x_value_pos, int y_pos);

void	print_live_values(t_app *app, int start_y)
{
	char	*mlx;
	char	*win;
	int		x_pos;
	int		x_value_pos;
	int		current_y;

	x_pos = app->sidebar.x_pos;
	mlx = app->win.mlx;
	win = app->win.win;
	x_value_pos = app->sidebar.x_offset;
	current_y = start_y + 30;
	mlx_string_put(mlx, win, x_pos + 20, current_y, TEXT_COLOR, "Live Values:");
	current_y += app->sidebar.y_space_title;
	print_zoom_value(app, x_pos, x_value_pos, current_y);
	current_y += app->sidebar.y_space_ctrl;
	print_scale_value(app, x_pos, x_value_pos, current_y);
	current_y += app->sidebar.y_space_ctrl;
	print_rot_value(app, x_pos, x_value_pos, current_y);
	current_y += app->sidebar.y_space_ctrl;
	print_view_mode(app, x_pos, x_value_pos, current_y);
}

static void	print_zoom_value(t_app *app, int x_pos, int x_value_pos, int y_pos)
{
	char	*num_str;
	char	*mlx;
	char	*win;

	mlx = app->win.mlx;
	win = app->win.win;
	num_str = ft_itoa((int)(app->matrix.zoom * 100));
	if (num_str)
	{
		mlx_string_put(mlx, win, x_pos, y_pos, TEXT_COLOR, "Zoom: ");
		mlx_string_put(mlx, win, x_value_pos, y_pos, TEXT_COLOR, num_str);
		mlx_string_put(mlx, win, x_value_pos + 30, y_pos, TEXT_COLOR, "%");
		free(num_str);
	}
}

static void	print_scale_value(t_app *app, int x_pos, int x_value_pos, int y_pos)
{
	char	*num_str;
	char	*mlx;
	char	*win;

	mlx = app->win.mlx;
	win = app->win.win;
	num_str = ft_itoa((int)(app->matrix.scale));
	if (num_str)
	{
		mlx_string_put(mlx, win, x_pos, y_pos, TEXT_COLOR, "Scale: ");
		mlx_string_put(mlx, win, x_value_pos, y_pos, TEXT_COLOR, num_str);
		mlx_string_put(mlx, win, x_value_pos + 30, y_pos, TEXT_COLOR, "%");
		free(num_str);
	}
}

static void	print_rot_value(t_app *app, int x_pos, int x_value_pos, int y_pos)
{
	char	*num_str;
	char	*mlx;
	char	*win;

	mlx = app->win.mlx;
	win = app->win.win;
	num_str = ft_itoa((int)(app->matrix.angle_z * 180 / M_PI));
	if (num_str)
	{
		mlx_string_put(mlx, win, x_pos, y_pos, TEXT_COLOR, "Rotation: ");
		mlx_string_put(mlx, win, x_value_pos, y_pos, TEXT_COLOR, num_str);
		mlx_string_put(mlx, win, x_value_pos + 30, y_pos, TEXT_COLOR, "deg");
		free(num_str);
	}
}

static void	print_view_mode(t_app *app, int x_pos, int x_value_pos, int y_pos)
{
	char	*mlx;
	char	*win;

	mlx = app->win.mlx;
	win = app->win.win;
	mlx_string_put(mlx, win, x_pos, y_pos, TEXT_COLOR, "View: ");
	if (app->map.view_mode == VIEW_ISO)
		mlx_string_put(mlx, win, x_value_pos, y_pos, TEXT_COLOR, "ISO");
	else if (app->map.view_mode == VIEW_SIDE)
		mlx_string_put(mlx, win, x_value_pos, y_pos, TEXT_COLOR, "PARALLEL");
	else if (app->map.view_mode == VIEW_TOP)
		mlx_string_put(mlx, win, x_value_pos, y_pos, TEXT_COLOR, "TOP");
}
