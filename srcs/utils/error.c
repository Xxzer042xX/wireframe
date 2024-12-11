/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:42:39 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/10 21:45:15 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction gère l'affichage des messages d'erreur du programme.      */
/*   Elle écrit sur la sortie d'erreur (fd 2) un message explicatif           */
/*   correspondant au code d'erreur reçu. Les erreurs gérées incluent :       */
/*   - Arguments invalides (ERR_ARGS)                                         */
/*   - Échec d'allocation mémoire (ERR_MALLOC)                                */
/*   - Problème d'accès fichier (ERR_FILE)                                    */
/*   - Format de fichier invalide (ERR_FORMAT)                                */
/*   - Échec d'initialisation MLX (ERR_MLX)                                   */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - error : code d'erreur à traiter                                        */
/*                                                                            */
/*   Retourne:                                                                */
/*   - Le même code d'erreur reçu en paramètre                                */
/*                                                                            */
/* ************************************************************************** */
int	error_exit(int error)
{
	ft_putstr_fd("Error: ", 2);
	if (error == ERR_ARGS)
		ft_putstr_fd("Invalide arguments\n", 2);
	else if (error == ERR_MALLOC)
		ft_putstr_fd("Memory allocation failed\n", 2);
	else if (error == ERR_FILE)
		ft_putstr_fd("Cannot open file\n", 2);
	else if (error == ERR_FORMAT)
		ft_putstr_fd("Invalide file format\n", 2);
	else if (error == ERR_MLX)
		ft_putstr_fd("MLX initialisation failed\n", 2);
	else if (error == DEBUG)
		ft_putstr_fd("et ben faut bosser tes examens\n", 2);
	return (error);
}
