/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   FdF.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 18:05:09 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 18:33:52 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H
#include "../minilibx_macos/mlx.h"
#include <stdio.h>
#include "../libft/libft.h"
#include "math.h"

typedef struct		s_vector
{
	float xV;
	float yV;
}					t_vector;

typedef struct		s_pixel
{
	float	xP;
	float	yP;
	float	xP1;
	float	yP1;
}					t_pixel;	

typedef struct		s_point
{
	float 			x;
	float			y;
	float			z;
}					t_point;

typedef struct		s_index
{
	int 			x;
	int				y;
}					t_index;

typedef struct		s_map
{
	t_point			**coord; 
	t_index			size;
}					t_map;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_map			*map;
	t_pixel			*pixel;
	t_vector		x_vector;
	t_vector		y_vector;
	t_vector		z_vector;
	float			scale;
}					t_fdf;

int 				ft_convert(t_fdf **afdf);
t_fdf				*define_fdf(void);
t_pixel     		*define_pixel(void);
#endif