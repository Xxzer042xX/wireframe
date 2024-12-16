/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_sidebar_control.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:13:51 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/15 22:13:51 by madelmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	define_color_opacity(t_app *app);
static int	define_color_opacity_aux(t_app *app);

void	change_sidebar_color(t_app *app)
{
	int		color;

	app->sidebar.color_mode = (app->sidebar.color_mode + 1) % 16;
	color = define_color_opacity(app);
	app->sidebar.color.hex = color;
	ft_memset(app->win.addr, 0, app->win.line_len * app->win.h_win);
	app->needs_update = 1;
	render(app);
}

static int	define_color_opacity(t_app *app)
{
	int		color;

	color = 0;
	if (app->sidebar.color_mode == 0)
		color = PURPLE_50;
	else if (app->sidebar.color_mode == 1)
		color = GREEN_50;
	else if (app->sidebar.color_mode == 2)
		color = BLUE_50;
	else if (app->sidebar.color_mode == 3)
		color = RED_50;
	else if (app->sidebar.color_mode == 4)
		color = CYAN_50;
	else if (app->sidebar.color_mode == 5)
		color = ORANGE_50;
	else if (app->sidebar.color_mode == 6)
		color = BROWN_50;
	else if (app->sidebar.color_mode == 7)
		color = GREY_50;
	else if (app->sidebar.color_mode == 8)
		color = WHITE_50;
	else
		color = define_color_opacity_aux(app);
	return (color);
}

static int	define_color_opacity_aux(t_app *app)
{
	int	color;

	color = 0;
	if (app->sidebar.color_mode == 9)
		color = SILVER_50;
	else if (app->sidebar.color_mode == 10)
		color = GOLD_50;
	else if (app->sidebar.color_mode == 11)
		color = BRONZE_50;
	else if (app->sidebar.color_mode == 12)
		color = PLATINUM_50;
	else if (app->sidebar.color_mode == 13)
		color = COPPER_50;
	else if (app->sidebar.color_mode == 14)
		color = BRASS_50;
	else if (app->sidebar.color_mode == 15)
		color = YELLOW_50;
	return (color);
}
