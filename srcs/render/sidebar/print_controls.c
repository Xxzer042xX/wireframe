/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:46:06 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/16 14:47:56 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/fdf.h"

static void	print_padding(t_app *app, int i, int y_pos);

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction affiche les contrôles et commandes dans la barre          */
/*   latérale selon une mise en page à deux colonnes.                         */
/*                                                                            */
/*   Organisation de l'affichage :                                            */
/*   1. Affichage du titre :                                                  */
/*      - Position : x = x_pos + 20, y = y_offset initial                     */
/*      - Texte : sidebar.title                                               */
/*                                                                            */
/*   2. Affichage des paires de contrôles :                                   */
/*      - Colonne gauche (clés) : x = x_pos                                   */
/*      - Colonne droite (valeurs) : x = x_pos + (width/2)                    */
/*      - Espacement vertical :                                               */
/*        * Initial : y_space_title après le titre                            */
/*        * Entre les lignes : y_space_ctrl                                   */
/*                                                                            */
/*   Formats :                                                                */
/*   - Couleur du texte : TEXT_COLOR                                          */
/*   - Alignement : Deux colonnes (description : touche)                      */
/*   - Nombre de contrôles : défini par ctrl_count                            */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale contenant :                */
/*          * win : informations MLX (mlx, win)                               */
/*          * sidebar : paramètres de la barre latérale                       */
/*          * ctrl_pairs : tableau des paires de contrôles                    */
/*                                                                            */
/*   Retourne:                                                                */
/*   - La position verticale finale (y_pos) après tous les contrôles          */
/*     Peut être utilisée pour ajouter d'autres éléments en dessous           */
/*                                                                            */
/* ************************************************************************** */
int	print_controls(t_app *app)
{
	int		y_pos;
	int		i;

	y_pos = app->sidebar.y_offset;
	mlx_string_put(app->win.mlx, app->win.win, app->sidebar.x_pos + 20, y_pos,
		SILVER, app->sidebar.title);
	y_pos += app->sidebar.y_space_title;
	i = 0;
	while (i < app->sidebar.ctrl_count)
	{
		mlx_string_put(app->win.mlx, app->win.win, app->sidebar.x_pos, y_pos,
			SILVER, app->sidebar.ctrl_pairs[i].key);
		print_padding(app, i, y_pos);
		y_pos += app->sidebar.y_space_ctrl;
		i++;
	}
	return (y_pos);
}

static void	print_padding(t_app *app, int i, int y_pos)
{
	int		adjusted_x_offset;

	adjusted_x_offset = app->sidebar.x_pos + (app->sidebar.width / 2);
	if (i == 0 || i == 1 || i == 2)
		mlx_string_put(app->win.mlx, app->win.win, (adjusted_x_offset - 25),
			y_pos, SILVER, app->sidebar.ctrl_pairs[i].value);
	else if (i == 6)
		mlx_string_put(app->win.mlx, app->win.win, adjusted_x_offset + 10,
			y_pos, SILVER, app->sidebar.ctrl_pairs[i].value);
	else
		mlx_string_put(app->win.mlx, app->win.win, adjusted_x_offset,
			y_pos, SILVER, app->sidebar.ctrl_pairs[i].value);
}
