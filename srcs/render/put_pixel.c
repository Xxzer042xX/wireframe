/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelmeni <eljok87@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:59:31 by mdelmeni          #+#    #+#             */
/*   Updated: 2024/12/12 15:13:35 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction dessine un pixel à une position donnée si celle-ci        */
/*   se trouve dans les limites de la fenêtre.                                */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - x : coordonnée x du pixel                                              */
/*   - y : coordonnée y du pixel                                              */
/*   - color : couleur du pixel au format RGB                                 */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */

void	put_pixel(t_app *app, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < app->win.w_win && y >= 0 && y < app->win.h_win)
	{
		dst = app->win.addr + (y * app->win.line_len + x * (app->win.bbp / 8));
		*(unsigned int *)dst = color;
	}
}
