/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sidebar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:18:36 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/12 09:18:36 by madelmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

// Fonction pour initialiser la sidebar
void	init_sidebar(t_app *app)
{
	app->sidebar.width = app->win.w_win / 4;
	app->sidebar.height = app->win.h_win;
	app->sidebar.state.last_zoom = -1;
	app->sidebar.state.last_altitude = -1;
	app->sidebar.state.last_projection = -1;
	app->sidebar.state.last_angle_z = -1;
	app->sidebar.state.needs_update = 1;
}
