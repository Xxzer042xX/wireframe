/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:58:05 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/12 16:00:15 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	is_fdf_file(const char *filename);

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction est le point d'entrée principal du programme FdF.         */
/*   Elle vérifie d'abord le nombre d'arguments, initialise la structure      */
/*   Elle initialise l'application via init_app() et vérifie son succès.      */
/*   En cas d'échec, elle nettoie et termine avec le code d'erreur.           */
/*   Si l'initialisation réussit, elle entre dans une boucle de rendu qui     */
/*   continue tant que l'état est STATE_RUNNING. Dans cette boucle, elle      */
/*   configure le hook de rendu et lance la boucle principale de la MLX.      */
/*   À la fin, elle nettoie les ressources et retourne SUCCESS.               */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - ac : nombre d'arguments reçus                                          */
/*   - av : tableau des arguments, où av[1] est le fichier à traiter          */
/*                                                                            */
/*   Retourne:                                                                */
/*   - SUCCESS en cas de succès                                               */
/*   - Code d'erreur approprié en cas d'échec                                 */
/*                                                                            */
/* ************************************************************************** */
int	main(int ac, char **av)
{
	t_app	app;
	char	*filename;
	int		error;

	if (ac != 2 || !is_fdf_file(av[1]))
		return (error_exit(ERR_ARGS));
	filename = av[1];
	ft_memset(&app, 0, sizeof(t_app));
	error = init_app(&app, filename);
	if (error != SUCCESS)
		return (cleanup_app(&app), error);
	mlx_loop_hook(app.win.mlx, render, &app);
	mlx_loop(app.win.mlx);
	return (cleanup_app(&app), SUCCESS);
}

static int	is_fdf_file(const char *filename)
{
	const char	*ext;

	ext = ft_strrchr(filename, '.');
	if (!ext)
		return (0);
	if (ft_strncmp(ext, ".fdf", 4))
		return (0);
	return (1);
}
