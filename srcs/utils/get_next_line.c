/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:06:59 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/11 08:22:18 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils/get_next_line.h"

static char	*read_file(int fd, char *static_buffer);
static char	*ft_extract_line(char *static_buffer);
static char	*ft_next(char *str);
static int	init_buffer(char **static_buffer);

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction lit une ligne depuis un descripteur de fichier.           */
/*   Elle utilise un buffer statique pour gérer les lectures partielles,      */
/*   vérifie la validité des paramètres, et gère les erreurs. La fonction     */
/*   retourne une ligne complète jusqu'au caractère newline ou EOF.           */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - fd : descripteur de fichier à lire                                     */
/*                                                                            */
/*   Retourne:                                                                */
/*   - La ligne lue ou NULL en cas d'erreur/EOF                               */
/*                                                                            */
/* ************************************************************************** */
char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*extracted_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if ((fd >= 0 && fd < OPEN_MAX) && buffer[fd])
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
		return (NULL);
	}
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	extracted_line = ft_extract_line(buffer[fd]);
	if (!extracted_line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = ft_next(buffer[fd]);
	return (extracted_line);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction lit le fichier par blocs de BUFFER_SIZE octets.           */
/*   Elle accumule les lectures dans le buffer statique jusqu'à trouver       */
/*   un newline ou atteindre EOF. Gère les erreurs de lecture et              */
/*   d'allocation mémoire.                                                    */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - fd : descripteur de fichier                                            */
/*   - static_buffer : buffer de stockage entre les appels                    */
/*                                                                            */
/*   Retourne:                                                                */
/*   - Buffer mis à jour ou NULL en cas d'erreur                              */
/*                                                                            */
/* ************************************************************************** */
static char	*read_file(int fd, char *static_buffer)
{
	char	*temp_buffer;
	char	*remake_file;
	int		byte_read;

	if (!static_buffer)
		if (init_buffer(&static_buffer) != SUCCESS)
			return (NULL);
	temp_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp_buffer)
		return (free(static_buffer), NULL);
	byte_read = 1;
	while (!ft_strchr(static_buffer, '\n') && byte_read > 0)
	{
		byte_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(temp_buffer), free(static_buffer), NULL);
		temp_buffer[byte_read] = '\0';
		remake_file = ft_strjoin(static_buffer, temp_buffer);
		free(static_buffer);
		if (!remake_file)
			return (free(temp_buffer), NULL);
		static_buffer = remake_file;
	}
	return (free(temp_buffer), static_buffer);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction initialise le buffer statique.                            */
/*   Elle alloue un buffer vide de taille 1 pour commencer la lecture.        */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - static_buffer : pointeur vers le buffer à initialiser                  */
/*                                                                            */
/*   Retourne:                                                                */
/*   - SUCCESS ou ERR_MALLOC en cas d'échec                                   */
/*                                                                            */
/* ************************************************************************** */
static int	init_buffer(char **static_buffer)
{
	*static_buffer = ft_calloc(1, 1);
	if (!static_buffer)
		return (ERR_MALLOC);
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction extrait une ligne complète du buffer statique.            */
/*   Elle repère le premier newline ou la fin du buffer, et copie tous        */
/*   les caractères jusqu'à ce point dans une nouvelle chaîne.                */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - static_buffer : buffer contenant les données lues                      */
/*                                                                            */
/*   Retourne:                                                                */
/*   - La ligne extraite ou NULL en cas d'erreur                              */
/*                                                                            */
/* ************************************************************************** */
static char	*ft_extract_line(char *static_buffer)
{
	char	*extracted_line;
	int		i;

	i = 0;
	if (!static_buffer[i])
		return (NULL);
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (static_buffer[i] == '\n')
		i++;
	extracted_line = ft_calloc(i + 1, sizeof(char));
	if (!extracted_line)
		return (NULL);
	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
	{
		extracted_line[i] = static_buffer[i];
		i++;
	}
	if (static_buffer[i] == '\n')
		extracted_line[i] = '\n';
	return (extracted_line);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction prépare le buffer pour la prochaine lecture.              */
/*   Elle supprime la ligne extraite du buffer et déplace le reste            */
/*   au début, libérant la mémoire de l'ancien buffer.                        */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - str : buffer à mettre à jour                                           */
/*                                                                            */
/*   Retourne:                                                                */
/*   - Nouveau buffer préparé ou NULL si plus de données                      */
/*                                                                            */
/* ************************************************************************** */
static char	*ft_next(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	i++;
	line = ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
	if (!line)
		return (free(str), NULL);
	j = 0;
	while (str[i])
		line[j++] = str[i++];
	free(str);
	return (line);
}
