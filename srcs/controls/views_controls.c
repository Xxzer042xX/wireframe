/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:44:36 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/10 21:43:25 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction bascule entre les vues isométrique et plane de la carte.  */
/*   Elle inverse l'état de la vue, recrée l'image pour éviter les artéfacts, */
/*   puis redessine et réaffiche la carte avec la nouvelle projection.        */
/*   La fonction gère la réinitialisation complète du buffer d'image et       */
/*   sa configuration.                                                        */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
void	toggle_view(t_app *app)
{
	app->map.is_iso = !app->map.is_iso;
	mlx_destroy_image(app->win.mlx, app->win.img);
	app->win.img = mlx_new_image(app->win.mlx, app->win.w_win, app->win.h_win);
	app->win.addr = mlx_get_data_addr(app->win.img, &app->win.bbp, \
								&app->win.line_len, &app->win.endian);
	draw_map(app);
	mlx_put_image_to_window(app->win.mlx, app->win.win, app->win.img, 0, 0);
}
