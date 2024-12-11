/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:44:42 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/10 21:36:15 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static t_coord	init_delta(t_point start, t_point end);
static t_coord	init_direction(t_point start, t_point end);
static void		upd_pos(t_coord *cur, t_coord sign, int *error, t_coord delta);

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction implémente l'algorithme de Bresenham pour dessiner une    */
/*   ligne entre deux points. Elle calcule les deltas et directions, puis     */
/*   trace la ligne pixel par pixel en utilisant une approche incrémentale.   */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - start : point de départ de la ligne                                    */
/*   - end : point d'arrivée de la ligne                                      */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
void	draw_line(t_app *app, t_point start, t_point end)
{
	t_coord	delta;
	t_coord	sign;
	t_coord	cur;
	int		error;

	delta = init_delta(start, end);
	sign = init_direction(start, end);
	error = delta.x - delta.y;
	cur = start.pos;
	while (cur.x != end.pos.x || cur.y != end.pos.y)
	{
		put_pixel(app, cur.x, cur.y, start.color.ref);
		upd_pos(&cur, sign, &error, delta);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction calcule les différences absolues entre les coordonnées    */
/*   x et y des points de départ et d'arrivée.                                */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - start : point de départ                                                */
/*   - end : point d'arrivée                                                  */
/*                                                                            */
/*   Retourne:                                                                */
/*   - Une structure t_coord contenant les deltas en x et y                   */
/*                                                                            */
/* ************************************************************************** */
static t_coord	init_delta(t_point start, t_point end)
{
	t_coord	delta;

	delta.x = abs(end.pos.x - start.pos.x);
	delta.y = abs(end.pos.y - start.pos.y);
	return (delta);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction détermine la direction de progression de la ligne         */
/*   en comparant les coordonnées des points de départ et d'arrivée.          */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - start : point de départ                                                */
/*   - end : point d'arrivée                                                  */
/*                                                                            */
/*   Retourne:                                                                */
/*   - Une structure t_coord contenant les signes (+1/-1) pour x et y         */
/*                                                                            */
/* ************************************************************************** */
static t_coord	init_direction(t_point start, t_point end)
{
	t_coord	sign;

	if (start.pos.x < end.pos.x)
		sign.x = 1;
	else
		sign.x = -1;
	if (start.pos.y < end.pos.y)
		sign.y = 1;
	else
		sign.y = -1;
	return (sign);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction met à jour la position courante lors du tracé de ligne    */
/*   selon l'algorithme de Bresenham. Elle ajuste les coordonnées et          */
/*   l'erreur en fonction des deltas et des directions.                       */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - cur : pointeur vers les coordonnées courantes                          */
/*   - sign : directions de progression                                       */
/*   - error : pointeur vers la variable d'erreur                             */
/*   - delta : différences en x et y                                          */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
static void	upd_pos(t_coord *cur, t_coord sign, int *error, t_coord delta)
{
	int	error_doubled;

	error_doubled = *error * 2;
	if (error_doubled > -delta.y)
	{
		*error -= delta.y;
		cur->x += sign.x;
	}
	if (error_doubled < delta.x)
	{
		*error += delta.x;
		cur->y += sign.y;
	}
}
