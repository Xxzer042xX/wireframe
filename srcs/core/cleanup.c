/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:18:05 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/10 21:22:14 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	cleanup_map(t_app *app, int current_line);
static void	cleanup_windows(t_app *app);
static void	free_data_sidebar(t_app *app);

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction principale de nettoyage libère toutes les ressources      */
/*   allouées par l'application. Elle coordonne le nettoyage de la carte      */
/*   et des ressources graphiques en appelant les fonctions spécialisées.     */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
void	cleanup_app(t_app *app)
{
	if (!app)
		return ;
	cleanup_map(app, app->map.h_map);
	cleanup_windows(app);
	free_data_sidebar(app);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction libère la mémoire allouée pour la carte.                  */
/*   Elle parcourt le tableau de points jusqu'à la ligne spécifiée,           */
/*   libère chaque ligne, puis le tableau principal. Elle gère les cas        */
/*   où les pointeurs sont NULL pour éviter les erreurs de segmentation.      */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - current_line : nombre de lignes à nettoyer                             */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
static void	cleanup_map(t_app *app, int current_line)
{
	int	i;

	if (!app || !app->map.points)
		return ;
	i = 0;
	while (i < current_line)
	{
		if (app->map.points[i])
			free (app->map.points[i]);
		i++;
	}
	free (app->map.points);
	app->map.points = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction nettoie les ressources graphiques de l'application.       */
/*   Elle libère dans l'ordre : l'image MLX, la fenêtre, et l'instance MLX.   */
/*   Elle vérifie chaque pointeur avant libération pour éviter les erreurs    */
/*   et réinitialise les pointeurs à NULL après nettoyage.                    */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
static void	cleanup_windows(t_app *app)
{
	if (!app)
		return ;
	if (app->win.img)
		mlx_destroy_image(app->win.mlx, app->win.img);
	if (app->win.win)
		mlx_destroy_window(app->win.mlx, app->win.win);
	if (app->win.mlx)
	{
		mlx_destroy_display(app->win.mlx);
		free(app->win.mlx);
	}
	app->win.img = NULL;
	app->win.win = NULL;
	app->win.mlx = NULL;
}

static void	free_data_sidebar(t_app *app)
{
	if (app->sidebar.ctrl_pairs)
		free(app->sidebar.ctrl_pairs);
	app->sidebar.ctrl_pairs = NULL;
}
