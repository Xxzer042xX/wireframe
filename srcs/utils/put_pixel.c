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

static unsigned int	blend_color_component(unsigned int new_comp, unsigned int old_comp, unsigned int alpha);
static unsigned int	get_color_component(unsigned int color, int shift);

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
/*
void	put_pixel_rgba(t_app *app, int x, int y, int color)
{
	char			*dst;
	unsigned int	current_color;
	unsigned int	new_r, new_g, new_b;
	unsigned int	old_r, old_g, old_b;
	unsigned int	alpha;

	// Vérifier si le pixel est dans les limites de la fenêtre
	if (x >= 0 && x < app->win.w_win && y >= 0 && y < app->win.h_win)
	{
		dst = app->win.addr + (y * app->win.line_len + x * (app->win.bbp / 8));
		current_color = *(unsigned int *)dst;

		// Récupérer les composantes de la couleur existante
		old_r = (current_color >> 16) & 0xFF;
		old_g = (current_color >> 8) & 0xFF;
		old_b = current_color & 0xFF;

		// Récupérer les composantes de la nouvelle couleur
		new_r = (color >> 16) & 0xFF;
		new_g = (color >> 8) & 0xFF;
		new_b = color & 0xFF;
		alpha = (color >> 24) & 0xFF;

		// Si alpha = 0xFF (255), dessiner directement
		if (alpha == 255)
		{
			*(unsigned int *)dst = (new_r << 16) | (new_g << 8) | new_b;
			return;
		}

		// Mélanger les couleurs avec l'alpha
		new_r = (new_r * alpha + old_r * (255 - alpha)) / 255;
		new_g = (new_g * alpha + old_g * (255 - alpha)) / 255;
		new_b = (new_b * alpha + old_b * (255 - alpha)) / 255;

		// Écrire la couleur mélangée
		*(unsigned int *)dst = (new_r << 16) | (new_g << 8) | new_b;
	}
}
*/

static unsigned int	get_color_component(unsigned int color, int shift)
{
	return ((color >> shift) & 0xFF);
}

static unsigned int	blend_color_component(unsigned int new_comp, unsigned int old_comp, unsigned int alpha)
{
	return (new_comp * alpha + old_comp * (255 - alpha)) / 255;
}

void	put_pixel_rgba(t_app *app, int x, int y, int color)
{
	char			*dst;
	unsigned int	current, new_color;
	unsigned int	alpha;

	if (x < 0 || x >= app->win.w_win || y < 0 || y >= app->win.h_win)
		return ;
	dst = app->win.addr + (y * app->win.line_len + x * (app->win.bbp / 8));
	current = *(unsigned int *)dst;
	alpha = (color >> 24) & 0xFF;
	if (alpha == 255)
	{
		*(unsigned int *)dst = color & 0x00FFFFFF;
		return ;
	}
	new_color = (blend_color_component(get_color_component(color, 16), \
		get_color_component(current, 16), alpha) << 16) \
		| (blend_color_component(get_color_component(color, 8), \
		get_color_component(current, 8), alpha) << 8) \
		| blend_color_component(get_color_component(color, 0), \
		get_color_component(current, 0), alpha);
	*(unsigned int *)dst = new_color;
}
