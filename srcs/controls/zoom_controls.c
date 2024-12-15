/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:49:12 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/15 02:08:28 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

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
	ft_memset(app->win.addr, 0, app->win.line_len * app->win.h_win);
	app->needs_update = 1;
	render(app);
}
