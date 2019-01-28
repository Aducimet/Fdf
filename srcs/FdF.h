/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 18:05:09 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 17:05:40 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include "../libft/libft.h"
# include "math.h"
# include <unistd.h>

# define ABS(x)  ( (x<0) ? -(x) : x )

typedef struct		s_img
{
	void			*ptr_img;
	int				bpp;
	int				s_l;
	int				endian;
	int				*tab;
}					t_img;

typedef struct		s_vector
{
	float			xv;
	float			yv;
}					t_vector;

typedef struct		s_point_3d
{
	int				x;
	int				y;
	int				z;
}					t_point_3d;

typedef struct		s_point_2d
{
	float			x;
	float			y;
	int				color;
}					t_point_2d;

typedef struct		s_map

{
	t_point_3d		**coord;
	t_point_2d		size;
}					t_map;

typedef struct		s_i_color
{
	int				in_color;
	int				out_color;
}					t_i_color;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_map			*map;
	t_point_2d		zero;
	t_vector		x_vector;
	t_vector		y_vector;
	t_vector		z_vector;
	float			scale;
	float			scale_z;
	int				win_size_x;
	int				win_size_y;
	t_img			*img;
	int				min_value;
	int				max_value;
	t_i_color		clr;
}					t_fdf;

int					ft_len_2dtab(char **tmp);
int					ft_parse_util(t_fdf **afdf, char *line);
int					ft_convert(t_fdf **afdf);
int					ft_convert(t_fdf **afdf);
int					ft_keypress(int keycode, t_fdf **fdf);
int					ft_mousepress(int keycode, int x, int y, t_fdf **fdf);
int					leading_coefficiant(t_point_2d *step);
int					set_color(t_fdf **afdf, int current);
int					malloc_t_point(int len, t_fdf **afdf, int index);
void				ft_parse(t_fdf **afdf, int index, int len, char **tmp);
void				scale_down(t_fdf **afdf);
void				scale_up(t_fdf **afdf);
void				switch_colors(t_fdf **afdf, int keycode);
void				move_arrows(t_fdf **afdf, int keycode);
void				ft_proj_o(t_fdf **afdf);
void				set_line(t_point_2d *step, t_point_2d *src,
					t_point_2d *dst);
void				new_point(t_point_2d *pos, t_point_2d src, int i,
					t_point_2d step);
void				img_put_pixel(t_fdf *fdf, t_point_2d pos, int color);
void				put_pixel(t_point_2d pos, t_fdf *fdf, int color);
void				draw_line(t_fdf *fdf, t_point_2d src, t_point_2d dst);
void				ft_find_proj(t_fdf **afdf, t_point_3d point);
void				ft_free_me(t_point_3d ***coord);
t_fdf				*define_fdf(void);
t_point_3d			define_point_3d(int x, int y, int z);
t_point_2d			define_point_2d(float x, float y);
t_img				*define_img(void *mlx_ptr, int win_size_x, int win_size_y);
t_vector			define_vector(float x, float y);
t_fdf				*define_fdf(void);
t_map				*define_map(void);
#endif
