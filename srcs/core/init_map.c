/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:12:35 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/12 09:12:35 by madelmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction gère le parsing principal du fichier de données FdF.      */
/*   Elle compte d'abord le nombre de lignes, alloue l'espace mémoire         */
/*   nécessaire pour stocker les points de la carte, puis lance le parsing    */
/*   complet du fichier.                                                      */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - filename : nom du fichier à parser                                     */
/*                                                                            */
/*   Retourne:                                                                */
/*   - SUCCESS si le parsing est réussi                                       */
/*   - ERR_FILE en cas d'erreur de lecture                                    */
/*   - ERR_MALLOC en cas d'échec d'allocation                                 */
/*                                                                            */
/* ************************************************************************** */
int	init_map(t_app *app, char *filename)
{
	if (count_line(app, filename) != SUCCESS)
		return (ERR_FILE);
	app->map.points = malloc(sizeof(t_point *) * app->map.h_map);
	if (!app->map.points)
		return (ERR_MALLOC);
	if (parse_file(app, filename) != SUCCESS)
		return (ERR_FILE);
	return (SUCCESS);
}
