/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_live_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:47:03 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/14 20:25:12 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/fdf.h"

static void	print_zoom_val(t_app *app, int x_pos, int x_value_pos, int y_pos);
static void	print_rot_val(t_app *app, int x_pos, int x_value_pos, int y_pos);
static void	print_view_mode(t_app *app, int x_pos, int x_value_pos, int y_pos);
static void	print_scale_val(t_app *app, int x_pos, int x_value_pos, int y_pos);

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction principale affiche les valeurs en temps réel des          */
/*   paramètres de visualisation dans la barre latérale.                      */
/*                                                                            */
/*   Organisation de l'affichage :                                            */
/*   1. Titre "Live Values:" (décalé de 20px, espacé de 30px)                 */
/*   2. Affichage séquentiel des valeurs :                                    */
/*      - Niveau de zoom (en pourcentage)                                     */
/*      - Échelle verticale (en pourcentage)                                  */
/*      - Angle de rotation (en degrés)                                       */
/*      - Mode de vue actuel (ISO/PARALLEL/TOP)                               */
/*                                                                            */
/*   Espacements :                                                            */
/*   - Entre le titre et la première valeur : y_space_title                   */
/*   - Entre chaque valeur : y_space_ctrl                                     */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale                            */
/*   - start_y : position verticale initiale pour l'affichage                 */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
void	print_live_values(t_app *app, int start_y)
{
	char	*mlx;
	char	*win;
	int		x_pos;
	int		x_value_pos;
	int		current_y;

	x_pos = app->sidebar.x_pos;
	mlx = app->win.mlx;
	win = app->win.win;
	x_value_pos = app->sidebar.x_offset;
	current_y = start_y + 20;
	mlx_string_put(mlx, win, x_pos + 20, current_y, SILVER, "Live Values:");
	current_y += app->sidebar.y_space_title;
	print_zoom_val(app, x_pos, x_value_pos, current_y);
	current_y += app->sidebar.y_space_ctrl;
	print_scale_val(app, x_pos, x_value_pos, current_y);
	current_y += app->sidebar.y_space_ctrl;
	print_rot_val(app, x_pos, x_value_pos, current_y);
	current_y += app->sidebar.y_space_ctrl;
	print_view_mode(app, x_pos, x_value_pos, current_y);
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction affiche le niveau de zoom actuel dans la barre latérale.  */
/*                                                                            */
/*   Format d'affichage :                                                     */
/*   - Label "Zoom: " aligné à gauche                                         */
/*   - Valeur numérique convertie en pourcentage (zoom * 100)                 */
/*   - Symbole "%" après la valeur                                            */
/*                                                                            */
/*   Gestion mémoire :                                                        */
/*   - Conversion du nombre avec ft_itoa                                      */
/*   - Libération de la mémoire après affichage                               */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale                            */
/*   - x_pos : position horizontale du label                                  */
/*   - x_value_pos : position horizontale de la valeur                        */
/*   - y_pos : position verticale de la ligne                                 */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
static void	print_zoom_val(t_app *app, int x_pos, int x_value_pos, int y_pos)
{
	char	*num_str;
	char	*mlx;
	char	*win;

	mlx = app->win.mlx;
	win = app->win.win;
	num_str = ft_itoa((int)(app->matrix.zoom * 100));
	if (num_str)
	{
		mlx_string_put(mlx, win, x_pos, y_pos, SILVER, "Zoom: ");
		mlx_string_put(mlx, win, x_value_pos, y_pos, SILVER, num_str);
		mlx_string_put(mlx, win, x_value_pos + 30, y_pos, SILVER, "%");
		free(num_str);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction affiche l'échelle verticale actuelle dans la barre        */
/*   latérale.                                                                */
/*                                                                            */
/*   Format d'affichage :                                                     */
/*   - Label "Scale: " aligné à gauche                                        */
/*   - Valeur numérique entière                                               */
/*   - Symbole "%" après la valeur                                            */
/*                                                                            */
/*   Gestion mémoire :                                                        */
/*   - Conversion du nombre avec ft_itoa                                      */
/*   - Libération de la mémoire après affichage                               */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale                            */
/*   - x_pos : position horizontale du label                                  */
/*   - x_value_pos : position horizontale de la valeur                        */
/*   - y_pos : position verticale de la ligne                                 */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
static void	print_scale_val(t_app *app, int x_pos, int x_value_pos, int y_pos)
{
	char	*num_str;
	char	*mlx;
	char	*win;

	mlx = app->win.mlx;
	win = app->win.win;
	num_str = ft_itoa((int)(app->matrix.scale));
	if (num_str)
	{
		mlx_string_put(mlx, win, x_pos, y_pos, SILVER, "Scale: ");
		mlx_string_put(mlx, win, x_value_pos, y_pos, SILVER, num_str);
		mlx_string_put(mlx, win, x_value_pos + 30, y_pos, SILVER, "%");
		free(num_str);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction affiche l'angle de rotation actuel dans la barre          */
/*   latérale.                                                                */
/*                                                                            */
/*   Format d'affichage :                                                     */
/*   - Label "Rotation: " aligné à gauche                                     */
/*   - Valeur en degrés (conversion radians -> degrés : angle * 180/π)        */
/*   - Unité "deg" après la valeur                                            */
/*                                                                            */
/*   Gestion mémoire :                                                        */
/*   - Conversion du nombre avec ft_itoa                                      */
/*   - Libération de la mémoire après affichage                               */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale                            */
/*   - x_pos : position horizontale du label                                  */
/*   - x_value_pos : position horizontale de la valeur                        */
/*   - y_pos : position verticale de la ligne                                 */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
static void	print_rot_val(t_app *app, int x_pos, int x_value_pos, int y_pos)
{
	char	*num_str;
	char	*mlx;
	char	*win;

	mlx = app->win.mlx;
	win = app->win.win;
	num_str = ft_itoa((int)(app->matrix.angle_z * 180 / M_PI));
	if (num_str)
	{
		mlx_string_put(mlx, win, x_pos, y_pos, SILVER, "Rotation: ");
		mlx_string_put(mlx, win, x_value_pos, y_pos, SILVER, num_str);
		mlx_string_put(mlx, win, x_value_pos + 30, y_pos, SILVER, "deg");
		free(num_str);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*   Cette fonction affiche le mode de vue actuel dans la barre latérale.     */
/*                                                                            */
/*   Modes de vue possibles :                                                 */
/*   - VIEW_ISO : Affiche "ISO" (vue isométrique)                             */
/*   - VIEW_SIDE : Affiche "PARALLEL" (vue parallèle)                         */
/*   - VIEW_TOP : Affiche "TOP" (vue de dessus)                               */
/*                                                                            */
/*   Format d'affichage :                                                     */
/*   - Label "View: " aligné à gauche                                         */
/*   - Texte du mode actuel aligné avec les autres valeurs                    */
/*                                                                            */
/*   Paramètres:                                                              */
/*   - app : pointeur vers la structure principale                            */
/*   - x_pos : position horizontale du label                                  */
/*   - x_value_pos : position horizontale de la valeur                        */
/*   - y_pos : position verticale de la ligne                                 */
/*                                                                            */
/*   Ne retourne rien (void)                                                  */
/*                                                                            */
/* ************************************************************************** */
static void	print_view_mode(t_app *app, int x_pos, int x_value_pos, int y_pos)
{
	char	*mlx;
	char	*win;

	mlx = app->win.mlx;
	win = app->win.win;
	mlx_string_put(mlx, win, x_pos, y_pos, SILVER, "View: ");
	if (app->map.view_mode == VIEW_ISO)
		mlx_string_put(mlx, win, x_value_pos, y_pos, SILVER, "ISO");
	else if (app->map.view_mode == VIEW_SIDE)
		mlx_string_put(mlx, win, x_value_pos, y_pos, SILVER, "PARALLEL");
	else if (app->map.view_mode == VIEW_TOP)
		mlx_string_put(mlx, win, x_value_pos, y_pos, SILVER, "TOP");
}
