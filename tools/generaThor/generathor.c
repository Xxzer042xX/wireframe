/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generathor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:07:42 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/13 14:07:42 by madelmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "../lib/libftprintf/include/ft_printf.h"

static void	generate_map(int row, int col, char *fp);

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction principale gère la création d'une carte FdF plate.        */
/*   Elle vérifie les arguments, ouvre le fichier destination et appelle      */
/*   la fonction de génération.                                               */
/*                                                                            */
/*   Paramètres attendus :                                                    */
/*   ./generathor colonnes lignes fichier_destination                         */
/*                                                                            */
/*   Retourne:                                                                */
/*   - 0 en cas de succès                                                     */
/*   - 1 si nombre d'arguments incorrect ou erreur d'ouverture fichier        */
/*                                                                            */
/* ************************************************************************** */
int	main(int ac, char **av)
{
	char	*fd;
	int		i;
	int		j;
	int		col;
	int		row;

	if (ac != 4)
	{
		ft_printf("Usage: ./generathor [col] [row] \n");
		return (1);
	}
	col = ft_atoi(av[1]);
	row = ft_atoi(av[2]);
	fd = open("flat.fdf", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!fd)
		return (1);
	generate_map(row, col, fd);
	close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction génère une carte FdF plate composée uniquement de         */
/*   points d'altitude zéro.                                                  */
/*                                                                            */
/*   Format de sortie :                                                       */
/*   - Points séparés par des espaces sur chaque ligne                        */
/*   - Lignes séparées par des retours à la ligne                             */
/*   - Pas d'espace superflu en fin de ligne                                  */
/*   - Pas de retour à la ligne après la dernière ligne                       */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - row : nombre de lignes à générer                                       */
/*   - col : nombre de colonnes par ligne                                     */
/*   - fd : descripteur du fichier de sortie                                  */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
static void	generate_map(int row, int col, char *fd)
{
	int	i;
	int	j;

	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (j < col - 1)
				ft_putstr_fd("0 ", fd);
			else
				ft_putstr_fd("0", fd);
			j++;
		}
		if (i < row - 1)
			ft_putstr_fd("\n", fd);
		i++;
	}
}
