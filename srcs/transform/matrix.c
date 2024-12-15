/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:46:16 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/15 02:38:45 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static t_rot_point	rotate_point(double x, double y, double angle, t_app *app);
static t_rot_point	get_proj_coords(t_app *app, int grid_x, int grid_y, int z);
static void			apply_transformations(t_point *point, t_app *app);

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction centrale applique toutes les transformations à un point.  */
/*   Elle gère la rotation, la projection isométrique si activée, et les      */
/*   transformations finales. Les coordonnées de la grille sont d'abord       */
/*   calculées, puis transformées selon le mode de projection choisi.         */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - x : position x dans la grille                                          */
/*   - y : position y dans la grille                                          */
/*                                                                            */
/*   Retourne:                                                                */
/*   - Le point avec ses coordonnées transformées                             */
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
	final = rotate_point(grid_x, grid_y, app->matrix.angle_z, app);
	coords = get_proj_coords(app, final.x, final.y, point.pos.z);
	point.pos.x = coords.x;
	point.pos.y = coords.y;
	apply_transformations(&point, app);
	return (point);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction effectue la rotation d'un point autour du centre de la    */
/*   carte. Elle calcule d'abord le centre (pivot), puis applique une         */
/*   rotation matricielle autour de ce point selon l'angle donné.             */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - x : coordonnée x du point à tourner                                    */
/*   - y : coordonnée y du point à tourner                                    */
/*   - angle : angle de rotation en radians                                   */
/*   - app : pointeur vers la structure principale de l'application           */
/*                                                                            */
/*   Retourne:                                                                */
/*   - Structure t_rot_point contenant les coordonnées après rotation         */
/*                                                                            */
/* ************************************************************************** */
static t_rot_point	rotate_point(double x, double y, double angle, t_app *app)
{
	t_rot_point	result;
	int			pivot_x;
	int			pivot_y;
	int			dx;
	int			dy;

	pivot_x = (app->map.w_map * app->matrix.space) / 2;
	pivot_y = (app->map.h_map * app->matrix.space) / 2;
	dx = x - pivot_x;
	dy = y - pivot_y;
	result.x = pivot_x + (dx * cos(angle) - dy * sin(angle));
	result.y = pivot_y + (dx * sin(angle) + dy * cos(angle));
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction calcule les coordonnées en projection isométrique.        */
/*   Elle applique une projection à 30 degrés (0.523599 radians) pour         */
/*   transformer les coordonnées 3D en vue isométrique 2D, en prenant         */
/*   en compte la hauteur z pour créer l'effet de profondeur.                 */
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
static t_rot_point	get_proj_coords(t_app *app, int grid_x, int grid_y, int z)
{
	t_rot_point	result;

	if (app->map.view_mode == VIEW_ISO)
	{
		result.x = (grid_x - grid_y) * cos(ISO_ANGLE);
		result.y = -z + (grid_x + grid_y) * sin(ISO_ANGLE);
	}
	else if (app->map.view_mode == VIEW_TOP)
	{
		result.x = grid_x;
		result.y = grid_y;
	}
	else if (app->map.view_mode == VIEW_SIDE)
	{
		result.x = grid_x;
		result.y = -z;
	}
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
	point->pos.x *= app->matrix.scale;
	point->pos.y *= app->matrix.scale;
	point->pos.x *= app->matrix.zoom;
	point->pos.y *= app->matrix.zoom;
	point->pos.x += app->matrix.shift_x;
	point->pos.y += app->matrix.shift_y;
	point->pos.x += app->win.w_win / 2;
	point->pos.y += app->win.h_win / 2;
	point->pos.x -= (app->map.w_map * app->matrix.zoom * app->matrix.space) / 2;
	point->pos.y -= (app->map.h_map * app->matrix.zoom * app->matrix.space) / 2;
	point->pos.x += app->sidebar.width + 40;
}
