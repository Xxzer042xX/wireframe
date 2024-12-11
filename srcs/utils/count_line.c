/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:35:09 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/11 08:35:09 by madelmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction compte le nombre de lignes valides dans le fichier.       */
/*   Elle lit le fichier ligne par ligne en ignorant les lignes vides,        */
/*   et stocke le résultat dans app->map.h_map.                               */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale de l'application           */
/*   - filename : nom du fichier à analyser                                   */
/*                                                                            */
/*   Retourne:                                                                */
/*   - SUCCESS si le comptage est réussi                                      */
/*   - ERR_FILE si le fichier est vide ou invalide                            */
/*                                                                            */
/* ************************************************************************** */
int	count_line(t_app *app, const char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (*line != '\n')
			count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (count == 0)
		return (ERR_FILE);
	app->map.h_map = count;
	return (SUCCESS);
}
