/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:12:28 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/13 20:33:16 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction configure les paramètres initiaux de transformation.      */
/*   Elle définit les valeurs par défaut pour l'affichage du modèle 3D :      */
/*   l'espacement entre les points, l'angle isométrique, le zoom et           */
/*   l'échelle. Ces valeurs sont essentielles pour le rendu initial.          */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
void	init_matrix(t_app *app)
{
	app->matrix.space = SPACE;
	app->matrix.iso_angle = ISO_ANGLE;
	app->matrix.zoom = Z_DEFAULT;
	app->matrix.scale = SCALE;
}
