/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer_sidebar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:48:18 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/12 08:48:18 by madelmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"


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

void    draw_sidebar_content(t_app *app)
{
    int     y_pos;
    char    *num_str;

    // Dessiner le fond
    draw_sidebar(app);
    y_pos = PADDING;
    mlx_string_put(app->win.mlx, app->win.win, PADDING, y_pos, TEXT_COLOR, "FdF Controls:");
    y_pos += 30;
    
    mlx_string_put(app->win.mlx, app->win.win, PADDING, y_pos, TEXT_COLOR, "Zoom: + / -");
    y_pos += 20;
    
    mlx_string_put(app->win.mlx, app->win.win, PADDING, y_pos, TEXT_COLOR, "Move: Arrows");
    y_pos += 20;

    mlx_string_put(app->win.mlx, app->win.win, PADDING, y_pos, TEXT_COLOR, "Rotate: Q/E");
    y_pos += 20;

    // Affichage des valeurs actuelles
    num_str = ft_itoa((int)(app->matrix.zoom * 100));
    if (num_str)
    {
        mlx_string_put(app->win.mlx, app->win.win, PADDING, y_pos, TEXT_COLOR, "Zoom: ");
        mlx_string_put(app->win.mlx, app->win.win, PADDING + 50, y_pos, TEXT_COLOR, num_str);
        mlx_string_put(app->win.mlx, app->win.win, PADDING + 80, y_pos, TEXT_COLOR, "%");
        free(num_str);
    }
    y_pos += 20;

    num_str = ft_itoa((int)app->altitude_factor);
    if (num_str)
    {
        mlx_string_put(app->win.mlx, app->win.win, PADDING, y_pos, TEXT_COLOR, "Altitude: ");
        mlx_string_put(app->win.mlx, app->win.win, PADDING + 70, y_pos, TEXT_COLOR, num_str);
        free(num_str);
    }
    y_pos += 20;

    // Affichage du mode de projection
    mlx_string_put(app->win.mlx, app->win.win, PADDING, y_pos, TEXT_COLOR, 
        app->projection_mode ? "Mode: ISO" : "Mode: Parallel");
}

