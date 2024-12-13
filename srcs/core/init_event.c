/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:12:53 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/13 10:06:17 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction initialise la gestion des événements de l'application.    */
/*   Elle configure les hooks MLX pour gérer les événements clavier et la     */
/*   fermeture de la fenêtre via la croix. Elle assure la liaison entre       */
/*   les événements utilisateur et les fonctions de traitement.               */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*                                                                            */
/*   Retourne:                                                                */
/*   - SUCCESS si l'initialisation est réussie                                */
/*   - ERR_MLX si l'initialisation des hooks échoue                           */
/*                                                                            */
/* ************************************************************************** */
int	init_event(t_app *app)
{
	if (mlx_hook(app->win.win, 2, 1L << 0, handle_key, (void *)app) == -1)
		return (error_exit(ERR_MLX));
	if (mlx_hook(app->win.win, 17, 1L << 17, handle_exit, app) == -1)
		return (error_exit(ERR_MLX));
	return (SUCCESS);
}
