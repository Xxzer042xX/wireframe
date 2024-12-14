/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handler_mouse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:59:03 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/13 21:09:43 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction gère les événements de la souris.                         */
/*   Elle traite la molette de souris pour le zoom : molette vers le haut    */
/*   pour zoomer (Z_IN) et vers le bas pour dézoomer (Z_OUT).                */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - button : identifiant du bouton/action de la souris                    */
/*   - x : position x du curseur                                             */
/*   - y : position y du curseur                                             */
/*   - param : pointeur vers la structure principale de l'application        */
/*                                                                            */
/*   Retourne:                                                                */
/*   - SUCCESS dans tous les cas                                             */
/*                                                                            */
/* ************************************************************************** */
int	handle_mouse(int keycode, int x, int y, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	ft_printf("Keycode: %d, x: %d, y: %d\n", keycode, x, y);
	if (keycode == SCROLL_UP)
		zoom(app, Z_IN);
	if (keycode == SCROLL_DOWN)
		zoom(app, Z_OUT);
	return (SUCCESS);
}
