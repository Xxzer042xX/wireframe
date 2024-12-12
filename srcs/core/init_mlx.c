/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:12:43 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/12 09:12:43 by madelmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction initialise l'environnement graphique MLX.                 */
/*   Elle crée la connexion MLX, récupère les dimensions de l'écran,          */
/*   configure la taille de la fenêtre (moitié de l'écran), crée la           */
/*   fenêtre et l'image MLX. Elle configure également l'adresse de            */
/*   l'image et ses propriétés pour le rendu.                                 */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*                                                                            */
/*   Retourne:                                                                */
/*   - SUCCESS si l'initialisation MLX est réussie                            */
/*   - ERR_MLX si une étape de l'initialisation échoue                        */
/*                                                                            */
/* ************************************************************************** */
int	init_mlx(t_app *app)
{
	app->win.mlx = mlx_init();
	if (!app->win.mlx)
		return (ERR_MLX);
	mlx_get_screen_size(app->win.mlx, &app->win.w_scr, &app->win.h_scr);
	app->win.w_win = 640;
	app->win.h_win = 360;
	app->win.win = mlx_new_window(app->win.mlx, \
									app->win.w_win, app->win.h_win, TITLE);
	if (!app->win.win)
		return (ERR_MLX);
	app->win.img = mlx_new_image(app->win.mlx, app->win.w_win, app->win.h_win);
	if (!app->win.img)
		return (ERR_MLX);
	app->win.addr = mlx_get_data_addr(app->win.img, &app->win.bbp, \
										&app->win.line_len, &app->win.endian);
	if (!app->win.addr)
		return (ERR_MLX);
	return (SUCCESS);
}
