/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:44:36 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/13 09:08:05 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction change le mode de vue de la carte.                        */
/*   Elle définit le mode de vue spécifié via l'enum e_views,                */
/*   efface le buffer d'image actuel pour éviter les artéfacts,              */
/*   puis redessine la carte avec la nouvelle projection.                     */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - views_mode : mode de vue désiré (défini dans l'enum e_views)          */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
void	toggle_view(t_app *app, int views_mode)
{
	app->map.view_mode = views_mode;
	ft_memset(app->win.addr, 0, app->win.line_len * app->win.h_win);
	app->needs_update = 1;
	render(app);
}
