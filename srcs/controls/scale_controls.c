/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:35:56 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/13 20:57:12 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

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
