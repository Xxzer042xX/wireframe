/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:44:49 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/14 22:28:06 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	resize_window(t_app *app, int new_width, int new_height);
static void	resize_sidebar(t_app *app, int new_width, int new_height);
static int	setup_new_window(t_app *app, int new_width, int new_height);

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction bascule la taille de la fenêtre entre plein écran         */
/*   et demi-écran. Elle détermine la taille actuelle et appelle la           */
/*   fonction resize_window avec les nouvelles dimensions appropriées.        */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
int	toggle_window_size(t_app *app)
{
	if (app->win.w_win == INIT_WIN_W && app->win.h_win == INIT_WIN_H)
		resize_window(app, MAX_WIN_W, MAX_WIN_H);
	else
		resize_window(app, INIT_WIN_W, INIT_WIN_H);
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction redimensionne la fenêtre aux dimensions spécifiées.       */
/*   Elle détruit la fenêtre et l'image actuelles, recrée la fenêtre          */
/*   aux nouvelles dimensions, réinitialise l'image, reconfigure les          */
/*   événements et redessine la carte.                                        */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - new_width : nouvelle largeur de la fenêtre                             */
/*   - new_height : nouvelle hauteur de la fenêtre                            */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
static void	resize_window(t_app *app, int new_width, int new_height)
{
	if (mlx_destroy_image(app->win.mlx, app->win.img) < 0)
	{
		cleanup_app(app);
		exit(error_exit(ERR_MLX));
	}
	if (mlx_destroy_window(app->win.mlx, app->win.win) < 0)
	{
		cleanup_app(app);
		exit(error_exit(ERR_MLX));
	}
	app->win.w_win = new_width;
	app->win.h_win = new_height;
	app->matrix.shift_x = 0;
	app->matrix.shift_y = 0;
	setup_new_window(app, new_width, new_height);
	resize_sidebar(app, new_width, new_height);
	init_event(app);
	app->needs_update = 1;
	render(app);
}

static int	setup_new_window(t_app *app, int new_width, int new_height)
{
	app->win.win = mlx_new_window(app->win.mlx, new_width, new_height, TITLE);
	if (!app->win.win)
	{
		cleanup_app(app);
		exit(error_exit(ERR_MLX));
	}
	app->win.img = mlx_new_image(app->win.mlx, app->win.w_win, app->win.h_win);
	if (app->win.img == NULL)
	{
		cleanup_app(app);
		exit(error_exit(ERR_MLX));
	}
	app->win.addr = mlx_get_data_addr(app->win.img, &app->win.bbp, \
								&app->win.line_len, &app->win.endian);
	if (app->win.addr == NULL)
	{
		cleanup_app(app);
		exit(error_exit(ERR_MLX));
	}
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction redimensionne la barre latérale en fonction de la         */
/*   nouvelle taille de fenêtre. Elle ajuste tous les paramètres de           */
/*   positionnement et d'espacement en fonction des dimensions.               */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - new_width : nouvelle largeur de la fenêtre                            */
/*   - new_height : nouvelle hauteur de la fenêtre                           */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
static void	resize_sidebar(t_app *app, int new_width, int new_height)
{
	int	scale_y;

	if (new_width == INIT_WIN_W && new_height == INIT_WIN_H)
	{
		app->sidebar.width = INIT_WIN_W / 4;
		app->sidebar.height = INIT_WIN_H;
		app->sidebar.x_pos = PADDING_X;
		app->sidebar.y_pos = PADDING_Y;
		app->sidebar.x_offset = PADDING_OF_X;
		app->sidebar.y_offset = PADDING_OF_Y;
		app->sidebar.y_space_title = SPACE_TITLE;
		app->sidebar.y_space_ctrl = SPACE_CTRL;
	}
	else
	{
		scale_y = new_height / INIT_WIN_H;
		app->sidebar.width = new_width / 10;
		app->sidebar.height = new_height;
		app->sidebar.x_pos = PADDING_X;
		app->sidebar.y_pos = PADDING_Y;
		app->sidebar.x_offset = PADDING_OF_X + PADDING_X;
		app->sidebar.y_offset = PADDING_OF_Y;
		app->sidebar.y_space_title = SPACE_TITLE;
		app->sidebar.y_space_ctrl = SPACE_CTRL * scale_y;
	}
}
