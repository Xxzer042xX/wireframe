/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:29:19 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/10 22:16:09 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction gère le rendu principal de l'application.                 */
/*   Elle met à jour l'affichage de la carte, l'affiche dans la fenêtre,      */
/*   et gère l'arrêt propre du programme. Elle est appelée en continu par     */
/*   la boucle MLX tant que l'application est en cours d'exécution.           */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*                                                                            */
/*   Retourne:                                                                */
/*   - SUCCESS dans tous les cas (valeur non utilisée par MLX)                */
/*                                                                            */
/* ************************************************************************** */
int	render(t_app *app)
{
	if (app->state == STATE_KILL)
		mlx_loop_end(app->win.mlx);
	//draw_menu_box(app);
	draw_map(app);
	mlx_put_image_to_window(app->win.mlx, app->win.win, app->win.img, 0, 0);
	return (SUCCESS);
}
