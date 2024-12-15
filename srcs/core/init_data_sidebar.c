/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_sidebar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:39:31 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/14 20:32:55 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	init_data_sidebar(t_app *app)
{
	app->sidebar.title = "FdF Controls:";
	app->sidebar.width = INIT_WIN_W / 4;
	app->sidebar.height = INIT_WIN_H;
	app->sidebar.y_offset = PADDING_OF_Y;
	app->sidebar.x_offset = PADDING_OF_X;
	app->sidebar.x_pos = PADDING_X;
	app->sidebar.y_pos = PADDING_Y;
	app->sidebar.y_space_title = SPACE_TITLE;
	app->sidebar.y_space_ctrl = SPACE_CTRL;
	app->sidebar.ctrl_pairs = malloc(sizeof(t_control_pair) * 6);
	if (!app->sidebar.ctrl_pairs)
		return (ERR_MALLOC);
	app->sidebar.ctrl_count = 6;
	app->sidebar.ctrl_pairs[0] = (t_control_pair){"Move:", "wasd"};
	app->sidebar.ctrl_pairs[1] = (t_control_pair){"Rotate:", "Q/E"};
	app->sidebar.ctrl_pairs[2] = (t_control_pair){"View:", "F1,2,3"};
	app->sidebar.ctrl_pairs[3] = (t_control_pair){"Full Scr:", "f"};
	app->sidebar.ctrl_pairs[4] = (t_control_pair){"Zoom:", "Wheel"};
	app->sidebar.ctrl_pairs[5] = (t_control_pair){"Scale:", "z/c"};
	return (SUCCESS);
}
