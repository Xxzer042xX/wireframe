/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:46:16 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/10 21:41:45 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static t_rot_point	rotate_point(double x, double y, double angle);
static t_rot_point	get_iso_coords(int grid_x, int grid_y, int z);
static void			apply_transformations(t_point *point, t_app *app);

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction applique les transformations mathématiques à un point     */
/*   de la carte. Elle gère la projection (isométrique ou plane), la          */
/*   rotation et les transformations finales (zoom, décalage, centrage).      */
/*   C'est la fonction centrale qui transforme les coordonnées de la grille   */
/*   en coordonnées d'affichage.                                              */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - x : coordonnée x dans la grille                                        */
/*   - y : coordonnée y dans la grille                                        */
/*                                                                            */
/*   Retourne:                                                                */
/*   - Le point transformé avec ses nouvelles coordonnées                     */
/*                                                                            */
/* ************************************************************************** */
t_point	matrix(t_app *app, int x, int y)
{
	t_point		point;
	t_rot_point	coords;
	t_rot_point	final;
	int			grid_x;
	int			grid_y;

	point = app->map.points[y][x];
	grid_x = x * app->matrix.space;
	grid_y = y * app->matrix.space;
	if (app->map.is_iso)
	{
		coords = get_iso_coords(grid_x, grid_y, point.pos.z);
		final = rotate_point(coords.x, coords.y, app->matrix.angle_z);
	}
	else
		final = rotate_point(grid_x, grid_y, app->matrix.angle_z);
	point.pos.x = final.x;
	point.pos.y = final.y;
	apply_transformations(&point, app);
	return (point);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction calcule les coordonnées en projection isométrique.        */
/*   Elle applique les formules de projection isométrique standard avec       */
/*   un angle de 30 degrés (0.523599 radians), prenant en compte la           */
/*   hauteur (z) pour créer l'effet de profondeur.                            */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - grid_x : position x dans la grille                                     */
/*   - grid_y : position y dans la grille                                     */
/*   - z : hauteur du point                                                   */
/*                                                                            */
/*   Retourne:                                                                */
/*   - Structure t_rot_point contenant les coordonnées projetées              */
/*                                                                            */
/* ************************************************************************** */
static t_rot_point	get_iso_coords(int grid_x, int grid_y, int z)
{
	t_rot_point	iso;

	iso.x = (grid_x - grid_y) * cos(0.523599);
	iso.y = -z + (grid_x + grid_y) * sin(0.523599);
	return (iso);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction effectue la rotation 2D d'un point autour de l'origine.   */
/*   Elle applique les formules standards de rotation matricielle en          */
/*   utilisant les fonctions trigonométriques cos et sin.                     */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - x : coordonnée x du point à tourner                                    */
/*   - y : coordonnée y du point à tourner                                    */
/*   - angle : angle de rotation en radians                                   */
/*                                                                            */
/*   Retourne:                                                                */
/*   - Structure t_rot_point contenant les coordonnées après rotation         */
/*                                                                            */
/* ************************************************************************** */
static t_rot_point	rotate_point(double x, double y, double angle)
{
	t_rot_point	result;

	result.x = x * cos(angle) - y * sin(angle);
	result.y = x * sin(angle) + y * cos(angle);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction applique les transformations finales à un point.          */
/*   Elle gère le zoom, le décalage (shift) et le centrage dans la fenêtre.   */
/*   Les transformations sont appliquées dans l'ordre : zoom, décalage,       */
/*   centrage fenêtre, ajustement grille.                                     */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - point : pointeur vers le point à transformer                           */
/*   - app : pointeur vers la structure principale de l'application           */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
static void	apply_transformations(t_point *point, t_app *app)
{
	point->pos.x *= app->matrix.zoom;
	point->pos.y *= app->matrix.zoom;
	point->pos.x += app->matrix.shift_x;
	point->pos.y += app->matrix.shift_y;
	point->pos.x += app->win.w_win / 2;
	point->pos.y += app->win.h_win / 2;
	point->pos.x -= (app->map.w_map * app->matrix.zoom * app->matrix.space) / 2;
	point->pos.y -= (app->map.h_map * app->matrix.zoom * app->matrix.space) / 2;
}
