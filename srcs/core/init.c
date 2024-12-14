/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:33:36 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/13 09:23:00 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction initialise l'ensemble de l'application FdF.               */
/*   configure la matrice initiale des transformations.                       */
/*   Elle procède ensuite au parsing des données du fichier(init_map),        */
/*   initialise la connexion MLX et configure les événements.                 */
/*   Et definis le status machine  RUNNING.                                   */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - ac : nombre d'arguments reçus                                          */
/*   - filename : chemin vers le fichier à traiter                            */
/*                                                                            */
/*   Retourne:                                                                */
/*   - SUCCESS si l'initialisation est réussie                                */
/*   - Code d'erreur approprié si une étape échoue                            */
/*                                                                            */
/* ************************************************************************** */
int	init_app(t_app *app, char *filename)
{
	int	status;

	status = init_map(app, filename);
	if (status != SUCCESS)
		return (error_exit(status));
	status = init_mlx(app);
	if (status != SUCCESS)
		return (error_exit(status));
	status = init_event(app);
	if (status != SUCCESS)
		return (error_exit(status));
	status = init_data_sidebar(app);
	if (status != SUCCESS)
		return (error_exit(status));
	init_matrix(app);
	app->needs_update = 1;
	app->state = STATE_RUNNING;
	toggle_view(app, VIEW_ISO);
	return (SUCCESS);
}
