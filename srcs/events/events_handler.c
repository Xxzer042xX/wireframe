/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:24:18 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/11 10:25:33 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	handle_move(t_app *app, int keycode);
static void	handle_view(t_app *app, int keycode);

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction centrale gère tous les événements clavier.                */
/*   Elle identifie la touche pressée et redirige vers le gestionnaire        */
/*   approprié : sortie (ESC), vue (V,F,+,-) ou mouvement (W,A,S,D,Q,E).      */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - keycode : code de la touche pressée                                    */
/*   - param : pointeur vers les données de l'application (casté en t_app)    */
/*                                                                            */
/*   Retourne:                                                                */
/*   - SUCCESS dans tous les cas normaux                                      */
/*   - Résultat de handle_exit si ESC est pressé                              */
/*                                                                            */
/* ************************************************************************** */
int	handle_key(int keycode, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (keycode == KEY_ESC)
		return (handle_exit(app));
	if (keycode == KEY_V || keycode == KEY_F || \
		keycode == KEY_PLUS || keycode == KEY_MINUS)
		handle_view(app, keycode);
	else if (keycode == KEY_W || keycode == KEY_S || \
			keycode == KEY_A || keycode == KEY_D || \
			keycode == KEY_Q || keycode == KEY_E)
		handle_move(app, keycode);
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction gère la sortie propre de l'application.                   */
/*   Elle change l'état de l'application à STATE_KILL pour déclencher         */
/*   l'arrêt du programme.                                                    */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*                                                                            */
/*   Retourne:                                                                */
/*   - La nouvelle valeur de app->state (STATE_KILL)                          */
/*                                                                            */
/* ************************************************************************** */
int	handle_exit(t_app *app)
{
	return (app->state = STATE_KILL);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction gère les modifications de vue de la carte.                */
/*   Elle traite les touches V (vue), F (plein écran), + (zoom in) et         */
/*   - (zoom out) pour modifier l'affichage de la carte.                      */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - keycode : code de la touche pressée                                    */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
static void	handle_view(t_app *app, int keycode)
{
	if (keycode == KEY_V)
		toggle_view(app);
	if (keycode == KEY_F)
		toggle_window_size(app);
	if (keycode == KEY_PLUS)
		zoom(app, Z_IN);
	if (keycode == KEY_MINUS)
		zoom(app, Z_OUT);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction gère les déplacements et rotations de la carte.           */
/*   Elle traite les touches WASD pour les déplacements dans les 4            */
/*   directions et Q/E pour les rotations gauche/droite.                      */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - keycode : code de la touche pressée                                    */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
static void	handle_move(t_app *app, int keycode)
{
	if (keycode == KEY_W)
		shift_map(app, SHIFT_UP);
	if (keycode == KEY_A)
		shift_map(app, SHIFT_LEFT);
	if (keycode == KEY_S)
		shift_map(app, SHIFT_DOWN);
	if (keycode == KEY_D)
		shift_map(app, SHIFT_RIGHT);
	if (keycode == KEY_Q)
		rotate_map(app, ROT_LEFT);
	if (keycode == KEY_E)
		rotate_map(app, ROT_RIGHT);
}
