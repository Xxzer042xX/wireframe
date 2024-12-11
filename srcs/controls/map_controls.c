/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:01:34 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/11 11:01:43 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	redraw_map(t_app *app);

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction déplace la carte dans la direction spécifiée.             */
/*   Elle modifie les valeurs de décalage (shift_x, shift_y) en fonction      */
/*   de la direction donnée, avec un pas de déplacement fixe de 10 unités.    */
/*   Après le déplacement, la carte est automatiquement redessinée.           */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - direction : direction du déplacement (SHIFT_UP/DOWN/LEFT/RIGHT)        */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
void	shift_map(t_app *app, int direction)
{
	const float	shift_step = 10.0f;

	if (direction == SHIFT_UP)
		app->matrix.shift_y -= shift_step;
	else if (direction == SHIFT_DOWN)
		app->matrix.shift_y += shift_step;
	else if (direction == SHIFT_LEFT)
		app->matrix.shift_x -= shift_step;
	else if (direction == SHIFT_RIGHT)
		app->matrix.shift_x += shift_step;
	redraw_map(app);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction fait pivoter la carte autour de l'axe Z.                  */
/*   Elle modifie l'angle de rotation (angle_z) selon la direction donnée,    */
/*   avec un pas de rotation de 0.1 radian. L'angle est normalisé pour        */
/*   rester dans l'intervalle [0, 2π]. La carte est redessinée après          */
/*   la rotation.                                                             */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - direction : sens de rotation (ROT_LEFT/RIGHT)                          */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
void	rotate_map(t_app *app, int direction)
{
	const float	rot_step = 0.1f;

	if (direction == ROT_LEFT)
		app->matrix.angle_z -= rot_step;
	else if (direction == ROT_RIGHT)
		app->matrix.angle_z += rot_step;
	while (app->matrix.angle_z >= 2 * M_PI)
		app->matrix.angle_z -= 2 * M_PI;
	while (app->matrix.angle_z < 0)
		app->matrix.angle_z += 2 * M_PI;
	redraw_map(app);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction rafraîchit l'affichage de la carte.                       */
/*   Elle efface d'abord le contenu de l'image en la remplissant de noir,     */
/*   redessine la carte complète, puis met à jour l'affichage de la fenêtre.  */
/*   Cette opération n'est effectuée que si l'application est en cours        */
/*   d'exécution (STATE_RUNNING).                                             */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
static void	redraw_map(t_app *app)
{
	if (app->state == STATE_RUNNING)
	{
		ft_memset(app->win.addr, 0, app->win.line_len * app->win.h_win);
		draw_map(app);
		mlx_put_image_to_window(app->win.mlx, app->win.win, app->win.img, 0, 0);
	}
}
