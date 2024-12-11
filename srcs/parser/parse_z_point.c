/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_z_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:37:09 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/11 06:38:46 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction analyse la valeur Z et la couleur d'un point de la carte. */
/*   Elle gère le parsing des nombres négatifs, vérifie les digits, extrait   */
/*   la valeur z et traite la couleur hexadécimale optionnelle (format        */
/*   z,0xCOLOR). Si aucune couleur n'est spécifiée, utilise COLOR_GRID.       */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - z_value : chaîne contenant la valeur z et potentiellement la couleur   */
/*   - num_line : index de la ligne courante                                  */
/*   - col : index de la colonne courante                                     */
/*                                                                            */
/*   Retourne:                                                                */
/*   - SUCCESS si le parsing est réussi                                       */
/*   - ERR_FORMAT si le format des données est invalide                       */
/*                                                                            */
/* ************************************************************************** */
int	parsing_z(t_app *app, char *z_value, int num_line, int col)
{
	int		i;
	char	*hex_color;

	i = 0;
	if (z_value[i] == '-')
		i++;
	while (ft_isdigit(z_value[i]))
		i++;
	if (!z_value[i] || z_value[i] == ',')
	{
		app->map.points[num_line][col].pos.z = ft_atoi(z_value);
		if (z_value[i] == ',')
		{
			i++;
			hex_color = &z_value[i];
			if (!ft_ishexa(hex_color))
				return (ERR_FORMAT);
			app->map.points[num_line][col].color.ref = \
			ft_atoi_base(hex_color, 16);
		}
		else
			app->map.points[num_line][col].color.ref = COLOR_GRID;
		return (SUCCESS);
	}
	return (ERR_FORMAT);
}
