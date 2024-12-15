/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelmeni <eljok87@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:59:31 by mdelmeni          #+#    #+#             */
/*   Updated: 2024/12/12 15:13:35 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction place un pixel de couleur spécifique dans le buffer       */
/*   d'image MLX aux coordonnées données.                                     */
/*                                                                            */
/*   Processus de dessin :                                                    */
/*   1. Vérification des limites :                                            */
/*      - x dans [0, w_win[                                                   */
/*      - y dans [0, h_win[                                                   */
/*                                                                            */
/*   2. Calcul de l'adresse mémoire :                                         */
/*      position = addr + (y * line_len + x * (bbp/8))                        */
/*      - line_len : taille d'une ligne en octets                             */
/*      - bbp/8 : nombre d'octets par pixel                                   */
/*                                                                            */
/*   3. Écriture directe en mémoire :                                         */
/*      - Cast en unsigned int pour écrire la couleur                         */
/*      - Écriture uniquement si dans les limites                             */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale contenant :                */
/*          * win.addr : adresse du buffer d'image                            */
/*          * win.line_len : longueur d'une ligne en octets                   */
/*          * win.bbp : bits par pixel                                        */
/*          * win.w_win, win.h_win : dimensions de la fenêtre                 */
/*   - x, y : coordonnées du pixel                                            */
/*   - color : valeur de couleur au format RGB (0xRRGGBB)                     */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
void	put_pixel(t_app *app, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < app->win.w_win && y >= 0 && y < app->win.h_win)
	{
		dst = app->win.addr + (y * app->win.line_len + x * (app->win.bbp / 8));
		*(unsigned int *)dst = color;
	}
}
