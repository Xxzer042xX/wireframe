/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:46:06 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/14 10:46:06 by madelmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/fdf.h"

int	print_controls(t_app *app)
{
	int		adjusted_x_offset;
	int		y_pos;
	int		i;
	char	*mlx;
	char	*win;

	mlx = app->win.mlx;
	win = app->win.win;
	y_pos = app->sidebar.y_offset;
	adjusted_x_offset = app->sidebar.x_pos + (app->sidebar.width / 2);
	mlx_string_put(mlx, win, app->sidebar.x_pos + 20, y_pos, TEXT_COLOR,
		app->sidebar.title);
	y_pos += app->sidebar.y_space_title;
	i = 0;
	while (i < app->sidebar.ctrl_count)
	{
		mlx_string_put(mlx, win, app->sidebar.x_pos, y_pos, TEXT_COLOR,
			app->sidebar.ctrl_pairs[i].key);
		mlx_string_put(mlx, win, adjusted_x_offset,
			y_pos, TEXT_COLOR, app->sidebar.ctrl_pairs[i].value);
		y_pos += app->sidebar.y_space_ctrl;
		i++;
	}
	return (y_pos);
}
