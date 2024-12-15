/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:35:56 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/15 02:06:49 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction modifie l'échelle de la carte.                            */
/*   Elle augmente ou diminue la valeur du scale selon la direction donnée,   */
/*   avec une limite minimale de 0.1 pour éviter une échelle trop petite.     */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - direction : direction du changement d'échelle                          */
/*                (SCALE_INCREASE/SCALE_DECREASE)                             */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
void	scale_map(t_app *app, int direction)
{
	if (direction == SCALE_INCREASE)
		app->matrix.scale += SCALE_STEP;
	else if (direction == SCALE_DECREASE)
		app->matrix.scale -= SCALE_STEP;
	if (app->matrix.scale < 0.1f)
		app->matrix.scale = 0.1f;
	ft_memset(app->win.addr, 0, app->win.line_len * app->win.h_win);
	app->needs_update = 1;
	render(app);
}
