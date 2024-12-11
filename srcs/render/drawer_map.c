/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:30:00 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/10 21:38:44 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	draw_horizontal_lines(t_app *app, int y);
static void	draw_vertical_lines(t_app *app, int y);

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction dessine la carte complète en fil de fer (wireframe).      */
/*   Elle parcourt chaque ligne de la carte et appelle les fonctions de       */
/*   dessin pour tracer les lignes horizontales et verticales, créant         */
/*   ainsi le maillage complet de la représentation 3D.                       */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
void	draw_map(t_app *app)
{
	int	current_y;

	current_y = 0;
	while (current_y < app->map.h_map)
	{
		draw_horizontal_lines(app, current_y);
		draw_vertical_lines(app, current_y);
		current_y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction dessine les lignes horizontales pour une rangée donnée.   */
/*   Pour chaque point de la rangée, elle calcule les transformations         */
/*   matricielles des points actuels et suivants, puis trace une ligne        */
/*   entre eux pour créer les connexions horizontales du maillage.            */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - y : index de la rangée courante                                        */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
static void	draw_horizontal_lines(t_app *app, int y)
{
	t_point	current_point;
	t_point	next_point;
	int		current_x;

	current_x = 0;
	while (current_x < app->map.w_map - 1)
	{
		current_point = matrix(app, current_x, y);
		next_point = matrix(app, current_x + 1, y);
		draw_line(app, current_point, next_point);
		current_x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction dessine les lignes verticales pour une rangée donnée.     */
/*   Elle calcule les transformations matricielles des points actuels et      */
/*   des points de la rangée suivante, puis trace des lignes verticales       */
/*   pour créer les connexions verticales du maillage.                        */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - y : index de la rangée courante                                        */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
static void	draw_vertical_lines(t_app *app, int y)
{
	t_point	current_point;
	t_point	next_point;
	int		current_x;

	current_x = 0;
	while (current_x < app->map.w_map)
	{
		if (y < app->map.h_map - 1)
		{
			current_point = matrix(app, current_x, y);
			next_point = matrix(app, current_x, y + 1);
			draw_line(app, current_point, next_point);
		}
		current_x++;
	}
}
