/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 01:49:42 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/16 01:49:42 by madelmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	define_colors(t_app *app);
static int	define_colors_aux(t_app *app);

void	change_grid_color(t_app *app)
{
	int		i;
	int		j;
	int		color;

	app->map.color_mode = (app->map.color_mode + 1) % 16;
	i = 0;
	while (i < app->map.h_map)
	{
		j = 0;
		while (j < app->map.w_map)
		{
			if (app->map.points[i][j].color.is_parsed == 0)
			{
				color = define_colors(app);
				app->map.points[i][j].color.ref = color;
			}
			j++;
		}
		i++;
	}
	ft_memset(app->win.addr, 0, app->win.line_len * app->win.h_win);
	app->needs_update = 1;
	render(app);
}

static int	define_colors(t_app *app)
{
	int		color;

	color = 0;
	ft_printf("color_mode: %d\n", app->map.color_mode);
	if (app->map.color_mode == 0)
		color = PURPLE;
	else if (app->map.color_mode == 1)
		color = GREEN;
	else if (app->map.color_mode == 2)
		color = BLUE;
	else if (app->map.color_mode == 3)
		color = RED;
	else if (app->map.color_mode == 4)
		color = CYAN;
	else if (app->map.color_mode == 5)
		color = ORANGE;
	else if (app->map.color_mode == 6)
		color = BROWN;
	else if (app->map.color_mode == 7)
		color = GREY;
	else if (app->map.color_mode == 8)
		color = WHITE;
	else
		color = define_colors_aux(app);
	return (color);
}

static int	define_colors_aux(t_app *app)
{
	int	color;

	color = 0;
	if (app->map.color_mode == 9)
		color = SILVER;
	else if (app->map.color_mode == 10)
		color = GOLD;
	else if (app->map.color_mode == 11)
		color = BRONZE;
	else if (app->map.color_mode == 12)
		color = PLATINUM;
	else if (app->map.color_mode == 13)
		color = COPPER;
	else if (app->map.color_mode == 14)
		color = BRASS;
	else if (app->map.color_mode == 15)
		color = YELLOW;
	return (color);
}
