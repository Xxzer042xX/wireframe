/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:12:53 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/13 10:06:17 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction configure les gestionnaires d'événements (hooks) MLX      */
/*   pour l'interaction utilisateur. Elle initialise quatre types de hooks :  */
/*                                                                            */
/*   1. Événements clavier (handle_key) :                                     */
/*      - Événement 2 (KeyPress)                                              */
/*      - Masque 1L << 0                                                      */
/*      - Gère les interactions au clavier                                    */
/*                                                                            */
/*   2. Événements souris (handle_mouse) :                                    */
/*      - Gère les clics et le scroll de la souris                            */
/*                                                                            */
/*   3. Événement de fermeture (handle_exit) :                                */
/*      - Événement 17 (DestroyNotify)                                        */
/*      - Masque 1L << 17                                                     */
/*      - Gère la fermeture via le bouton X de la fenêtre                     */
/*                                                                            */
/*   4. Événement de redimensionnement (toggle_window_size) :                 */
/*      - Événement 25                                                        */
/*      - Masque 1L << 18                                                     */
/*      - Gère le changement de taille de la fenêtre                          */
/*                                                                            */
/*   La fonction vérifie la réussite de chaque hook et retourne une erreur    */
/*   si l'un d'entre eux échoue.                                              */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*          utilisé pour accéder à la fenêtre MLX et aux données              */
/*                                                                            */
/*   Retourne:                                                                */
/*   - SUCCESS si tous les hooks sont initialisés correctement                */
/*   - ERR_MLX si l'initialisation d'un hook échoue                           */
/*                                                                            */
/* ************************************************************************** */
int	init_event(t_app *app)
{
	if (mlx_hook(app->win.win, 2, 1L << 0, handle_key, (void *)app) == -1)
		return (error_exit(ERR_MLX));
	if (mlx_mouse_hook(app->win.win, handle_mouse, (void *)app) == -1)
		return (error_exit(ERR_MLX));
	if (mlx_hook(app->win.win, 17, 1L << 17, handle_exit, (void *)app) == -1)
		return (error_exit(ERR_MLX));
	if (mlx_hook(app->win.win, 25, 1L << 18, resize_win, (void *)app) == -1)
		return (error_exit(ERR_MLX));
	return (SUCCESS);
}
