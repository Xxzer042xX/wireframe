/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:33:36 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/11 10:30:02 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	init_mlx(t_app *app);
static int	init_map(t_app *app, char *filename);
static void	init_matrix(t_app *app);

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

	init_matrix(app);
	status = init_map(app, filename);
	if (status != SUCCESS)
		return (error_exit(status));
	status = init_mlx(app);
	if (status != SUCCESS)
		return (error_exit(status));
	status = init_event(app);
	if (status != SUCCESS)
		return (error_exit(status));
	app->state = STATE_RUNNING;
	return (SUCCESS);
}

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
static void	init_matrix(t_app *app)
{
	app->matrix.space = 30.0f;
	app->matrix.iso_angle = 0.523599f;
	app->matrix.zoom = 1.0f;
	app->matrix.scale = 1;
}

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
static int	init_map(t_app *app, char *filename)
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

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction initialise l'environnement graphique MLX.                 */
/*   Elle crée la connexion MLX, récupère les dimensions de l'écran,          */
/*   configure la taille de la fenêtre (moitié de l'écran), crée la           */
/*   fenêtre et l'image MLX. Elle configure également l'adresse de            */
/*   l'image et ses propriétés pour le rendu.                                 */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*                                                                            */
/*   Retourne:                                                                */
/*   - SUCCESS si l'initialisation MLX est réussie                            */
/*   - ERR_MLX si une étape de l'initialisation échoue                        */
/*                                                                            */
/* ************************************************************************** */
static int	init_mlx(t_app *app)
{
	app->win.mlx = mlx_init();
	if (!app->win.mlx)
		return (ERR_MLX);
	mlx_get_screen_size(app->win.mlx, &app->win.w_scr, &app->win.h_scr);
	app->win.w_win = app->win.w_scr / 2;
	app->win.h_win = app->win.h_scr / 2;
	app->win.win = mlx_new_window(app->win.mlx, \
									app->win.w_win, app->win.h_win, TITLE);
	if (!app->win.win)
		return (ERR_MLX);
	app->win.img = mlx_new_image(app->win.mlx, app->win.w_win, app->win.h_win);
	if (!app->win.img)
		return (ERR_MLX);
	app->win.addr = mlx_get_data_addr(app->win.img, &app->win.bbp, \
										&app->win.line_len, &app->win.endian);
	if (!app->win.addr)
		return (ERR_MLX);
	return (SUCCESS);
}

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
