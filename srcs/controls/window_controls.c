/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:44:49 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/10 21:43:59 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	resize_window(t_app *app, int new_width, int new_height);

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
void	toggle_window_size(t_app *app)
{
	if (app->win.w_win == app->win.w_scr)
		resize_window(app, app->win.w_scr / 2, app->win.h_scr / 2);
	else
		resize_window(app, app->win.w_scr, app->win.h_scr);
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
	mlx_destroy_image(app->win.mlx, app->win.img);
	mlx_destroy_window(app->win.mlx, app->win.win);
	app->win.w_win = new_width;
	app->win.h_win = new_height;
	app->win.win = mlx_new_window(app->win.mlx, new_width, new_height, TITLE);
	app->win.img = mlx_new_image(app->win.mlx, app->win.w_win, app->win.h_win);
	app->win.addr = mlx_get_data_addr(app->win.img, &app->win.bbp, \
								&app->win.line_len, &app->win.endian);
	init_event(app);
	draw_map(app);
	mlx_put_image_to_window(app->win.mlx, app->win.win, app->win.img, 0, 0);
}