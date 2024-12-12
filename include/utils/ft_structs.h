/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:32:26 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/10 03:30:34 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

/* ************************************************************************** */
/*                         ROTATION AND SHIFT MAP ENUMS                       */
/* ************************************************************************** */
enum e_shift_dir
{
	SHIFT_UP,
	SHIFT_DOWN,
	SHIFT_LEFT,
	SHIFT_RIGHT
};

enum e_rot_dir
{
	ROT_LEFT,
	ROT_RIGHT
};

/* ************************************************************************** */
/*                                ERROR AND STATE ENUMS                       */
/* ************************************************************************** */

enum e_error
{
	SUCCESS,
	ERR_ARGS,
	ERR_MALLOC,
	ERR_DATA,
	ERR_FILE,
	ERR_FORMAT,
	ERR_MLX,
	DEBUG
};

enum e_app_state
{
	STATE_KILL,
	STATE_INIT,
	STATE_RUNNING
};

/* ************************************************************************** */
/*                                COLOR AND COORD UNIONS                      */
/* ************************************************************************** */

typedef union u_color
{
	int	ref;
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	};
}	t_color;

typedef union u_coord
{
	struct
	{
		int	x;
		int	y;
		int	z;
	};
	int	coords[3];
}	t_coord;

/* ************************************************************************** */
/*                              SIDEBAR STRUCTURE                             */
/* ************************************************************************** */
typedef struct s_sidebar
{
	int		width;
	int		height;
	char	**options;
	int		selected;
}	t_sidebar;

/* ************************************************************************** */
/*                                POINT STRUCTURE                             */
/* ************************************************************************** */
typedef struct s_rot_point
{
	double	x;
	double	y;
}	t_rot_point;

typedef struct s_point
{
	t_rot_point	rot;
	t_coord		original_pos;
	t_coord		pos;
	t_color		color;
	float		elevation;
}	t_point;

/* ************************************************************************** */
/*                                WINDOWS STRUCTURE                           */
/* ************************************************************************** */

typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		w_scr;
	int		h_scr;
	int		w_win;
	int		h_win;
	int		bbp;
	int		line_len;
	int		endian;
	int		mouse_x;
	int		mouse_y;
	int		mouse_pressed;
}	t_win;

/* ************************************************************************** */
/*                                MAP STRUCTURE                               */
/* ************************************************************************** */

typedef struct s_map
{
	t_point	**points;
	float	z_min;
	float	z_max;
	float	z_range;
	float	z_scale;
	float	center_x;
	float	center_y;
	int		color_mode;
	int		is_iso;
	int		w_map;
	int		h_map;
}	t_map;

/* ************************************************************************** */
/*                              TRANSFORM STRUCTURE                           */
/* ************************************************************************** */

typedef struct s_matrix
{
	float	angle_x;
	float	angle_y;
	float	angle_z;
	float	scale;
	float	shift_x;
	float	shift_y;
	float	zoom;
	float	space;
	float	iso_angle;
	int		auto_rot;
}	t_matrix;

/* ************************************************************************** */
/*                              MAIN APP STRUCTURE                            */
/* ************************************************************************** */

typedef struct s_app
{
	t_map				map;
	t_win				win;
	t_matrix			matrix;
	t_sidebar			sidebar;
	enum e_app_state	state;
	enum e_shift_dir	shift_dir;
	enum e_rot_dir		rot_dir;
	int					projection_mode;
	float				altitude_factor;
}	t_app;

#endif
