/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer_sidebar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:48:18 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/13 00:28:27 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/fdf.h"

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction dessine le fond de la barre latérale.                     */
/*   Elle remplit la zone définie par la largeur et hauteur de la sidebar     */
/*   avec la couleur de menu spécifiée, pixel par pixel.                      */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
void	draw_sidebar(t_app *app)
{
	int		x;
	int		y;
	int		h_win;
	int		w_win;

	x = 0;
	y = 0;
	h_win = app->sidebar.height;
	w_win = app->sidebar.width;
	while (y < h_win)
	{
		x = 0;
		while (x < w_win)
		{
			if (y < h_win && x < w_win)
				put_pixel(app, x, y, COLOR_MENU);
			x++;
		}
		y++;
	}
}
