/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:49:12 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/10 21:44:45 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	resize_image(t_app *app);

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction applique un facteur de zoom à la carte.                   */
/*   Elle modifie le niveau de zoom en multipliant le zoom actuel par         */
/*   le facteur donné, puis rafraîchit l'affichage via resize_image           */
/*   pour appliquer la nouvelle échelle.                                      */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - factor : facteur multiplicateur de zoom (> 1 pour zoomer,              */
/*             < 1 pour dézoomer)                                             */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
void	zoom(t_app *app, float factor)
{
	app->matrix.zoom *= factor;
	resize_image(app);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction reconstruit l'image de la carte aux dimensions actuelles. */
/*   Elle détruit l'image existante, en crée une nouvelle, configure          */
/*   ses propriétés, redessine la carte et met à jour l'affichage.            */
/*   Cette fonction est utilisée après les modifications nécessitant un       */
/*   rafraîchissement complet de l'image.                                     */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
static void	resize_image(t_app *app)
{
	mlx_destroy_image(app->win.mlx, app->win.img);
	app->win.img = mlx_new_image(app->win.mlx, app->win.w_win, app->win.h_win);
	app->win.addr = mlx_get_data_addr(app->win.img, &app->win.bbp, \
								&app->win.line_len, &app->win.endian);
	draw_map(app);
	mlx_put_image_to_window(app->win.mlx, app->win.win, app->win.img, 0, 0);
}
