/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer_sidebar_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:03:34 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/13 15:03:34 by madelmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction dessine le contenu de la barre latérale.                  */
/*   Elle affiche les contrôles, le niveau de zoom actuel, le facteur         */
/*   d'altitude et le mode de projection en cours. Les textes sont            */
/*   positionnés verticalement avec un espacement régulier.                   */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	print_live_values(t_app *app, int *y_pos);
static void	print_controls(t_app *app, int *y_pos);

void	draw_sidebar_content(t_app *app)
{
	int		y_pos;

	y_pos = PADDING + 30;
	print_controls(app, &y_pos);
	print_live_values(app, &y_pos);
}


static void	print_controls(t_app *app, int *y_pos)
{
	char	*mlx;
	char	*win;

	mlx = app->win.mlx;
	win = app->win.win;
	mlx_string_put(mlx, win, PADDING + 20, *y_pos, TEXT_COLOR, "FdF Controls:");
	*y_pos += 40;
	mlx_string_put(mlx, win, PADDING, *y_pos, TEXT_COLOR, "Move:");
	mlx_string_put(mlx, win, PADDING + 100, *y_pos, TEXT_COLOR, "wasd");
	*y_pos += 20;
	mlx_string_put(mlx, win, PADDING, *y_pos, TEXT_COLOR, "Rotate:");
	mlx_string_put(mlx, win, PADDING + 100, *y_pos, TEXT_COLOR, "Q/E");
	*y_pos += 20;
	mlx_string_put(mlx, win, PADDING, *y_pos, TEXT_COLOR, "View:");
	mlx_string_put(mlx, win, PADDING + 100, *y_pos, TEXT_COLOR, "v");
	*y_pos += 20;
	mlx_string_put(mlx, win, PADDING, *y_pos, TEXT_COLOR, "Full Scr:");
	mlx_string_put(mlx, win, PADDING + 100, *y_pos, TEXT_COLOR, "f");
	*y_pos += 20;
	mlx_string_put(mlx, win, PADDING, *y_pos, TEXT_COLOR, "Zoom:");
	mlx_string_put(mlx, win, PADDING + 60, *y_pos, TEXT_COLOR, "Mouse Wheel");
	*y_pos += 20;
	mlx_string_put(mlx, win, PADDING, *y_pos, TEXT_COLOR, "Scale:");
	mlx_string_put(mlx, win, PADDING + 100, *y_pos, TEXT_COLOR, "+/-");
}

static void	print_live_values(t_app *app, int *y_pos)
{
	char	*num_str;
	char	*mlx;
	char	*win;

	mlx = app->win.mlx;
	win = app->win.win;
	*y_pos += 40;
	mlx_string_put(mlx, win, PADDING + 20, *y_pos, TEXT_COLOR, "Live Values:");
	*y_pos += 40;
	num_str = ft_itoa((int)(app->matrix.zoom * 100));
	if (num_str)
	{
		mlx_string_put(mlx, win, PADDING, *y_pos, TEXT_COLOR, "Zoom: ");
		mlx_string_put(mlx, win, PADDING + 100, *y_pos, TEXT_COLOR, num_str);
		mlx_string_put(mlx, win, PADDING + 110, *y_pos, TEXT_COLOR, "%");
		free(num_str);
	}
}
