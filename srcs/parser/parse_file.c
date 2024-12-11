/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:39:43 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/11 08:22:14 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	parse_line(t_app *app, char *line, int num_line);
static int	save_points_on_database(t_app *app, char **tokens, int num_line);

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction réalise le parsing complet du fichier.                    */
/*   Elle lit chaque ligne et appelle parse_line pour l'analyser.             */
/*   Les lignes vides sont ignorées et la lecture s'arrête à la fin           */
/*   du fichier ou en cas d'erreur.                                           */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - filename : nom du fichier à parser                                     */
/*                                                                            */
/*   Retourne:                                                                */
/*   - SUCCESS si le parsing est réussi                                       */
/*   - ERR_FILE en cas d'erreur de lecture                                    */
/*                                                                            */
/* ************************************************************************** */
int	parse_file(t_app *app, char *filename)
{
	int		status;
	int		num_line;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), ERR_FILE);
	num_line = 0;
	while (line)
	{
		if (*line != '\n')
		{
			status = parse_line(app, line, num_line);
			if (status != SUCCESS)
				return (close(fd), free(line), status);
			num_line++;
		}
		free (line);
		line = get_next_line(fd);
	}
	return (close(fd), SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction analyse une ligne individuelle du fichier.                */
/*   Elle nettoie la ligne, la découpe en tokens, vérifie sa largeur,         */
/*   alloue l'espace pour les points et les sauvegarde dans la structure.     */
/*   La première ligne définit la largeur de référence pour la carte.         */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - line : ligne à parser                                                  */
/*   - num_line : numéro de la ligne courante                                 */
/*                                                                            */
/*   Retourne:                                                                */
/*   - SUCCESS si le parsing est réussi                                       */
/*   - Codes d'erreur appropriés en cas d'échec                               */
/*                                                                            */
/* ************************************************************************** */
static int	parse_line(t_app *app, char *line, int num_line)
{
	char	**tokens;
	int		width;
	char	*clear_line;

	clear_line = ft_strtrim(line, "\n");
	if (!clear_line)
		return (ERR_MALLOC);
	tokens = ft_split(clear_line, ' ');
	free (clear_line);
	if (!tokens)
		return (ERR_MALLOC);
	width = 0;
	while (tokens[width])
		width++;
	if (num_line == 0)
		app->map.w_map = width;
	else if (width != app->map.w_map)
		return (ft_free_split(tokens, width), ERR_FORMAT);
	app->map.points[num_line] = malloc(sizeof(t_point) * width);
	if (!app->map.points[num_line])
		return (ft_free_split(tokens, width), ERR_MALLOC);
	if (save_points_on_database(app, tokens, num_line) != SUCCESS)
		return (ft_free_split(tokens, width), ERR_DATA);
	return (ft_free_split(tokens, width), SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction sauvegarde les points dans la base de données.            */
/*   Elle traite chaque token pour extraire les valeurs z et les couleurs,    */
/*   puis initialise les coordonnées x et y des points dans la structure.     */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - tokens : tableau de chaînes contenant les valeurs à parser             */
/*   - num_line : numéro de la ligne courante                                 */
/*                                                                            */
/*   Retourne:                                                                */
/*   - SUCCESS si la sauvegarde est réussie                                   */
/*   - ERR_FORMAT si le format des données est invalide                       */
/*                                                                            */
/* ************************************************************************** */
static int	save_points_on_database(t_app *app, char **tokens, int num_line)
{
	int	col;

	col = 0;
	while (tokens[col] && tokens[col][0] != '\n' && col < app->map.w_map)
	{
		if (parsing_z(app, tokens[col], num_line, col) != SUCCESS)
			return (ERR_FORMAT);
		app->map.points[num_line][col].pos.x = col;
		app->map.points[num_line][col].pos.y = num_line;
		col++;
	}
	return (SUCCESS);
}
