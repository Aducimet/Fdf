/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events_keys.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 17:22:08 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/28 16:33:55 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_proj_o_r(t_fdf **afdf)
{
	t_fdf	*fdf;

	fdf = *afdf;
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->ptr_img);
	fdf->x_vector = define_vector(10, 0);
	fdf->y_vector = define_vector(0, 4);
	fdf->z_vector = define_vector(0, -5.8);
	free(fdf->img);
	fdf->img = define_img(fdf->mlx_ptr, fdf->win_size_x, fdf->win_size_y);
	ft_convert(&fdf);
}

void	ft_proj_o_f(t_fdf **afdf)
{
	t_fdf	*fdf;

	fdf = *afdf;
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->ptr_img);
	fdf->x_vector = define_vector(10, 0);
	fdf->y_vector = define_vector(0, -4);
	fdf->z_vector = define_vector(0, -5.8);
	free(fdf->img);
	fdf->img = define_img(fdf->mlx_ptr, fdf->win_size_x, fdf->win_size_y);
	ft_convert(&fdf);
}

void	ft_proj_p_f(t_fdf **afdf)
{
	t_fdf	*fdf;

	fdf = *afdf;
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->ptr_img);
	fdf->x_vector = define_vector(10, 0);
	fdf->y_vector = define_vector(0, 10);
	fdf->z_vector = define_vector(0, 0);
	free(fdf->img);
	fdf->img = define_img(fdf->mlx_ptr, fdf->win_size_x, fdf->win_size_y);
	ft_convert(&fdf);
}

void	ft_proj_p_r(t_fdf **afdf)
{
	t_fdf	*fdf;

	fdf = *afdf;
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->ptr_img);
	fdf->x_vector = define_vector(0, 0);
	fdf->y_vector = define_vector(0, 10);
	fdf->z_vector = define_vector(-10, 0);
	free(fdf->img);
	fdf->img = define_img(fdf->mlx_ptr, fdf->win_size_x, fdf->win_size_y);
	ft_convert(&fdf);
}

int		ft_keypress(int keycode, t_fdf **fdf)
{	
	if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124)
		move_arrows(fdf, keycode);
	else if (keycode == 53)
		exit(0);
	else if (keycode == 91)
		ft_proj_p_f(fdf);
	else if (keycode == 69)
		scale_up(fdf);
	else if (keycode == 78)
		scale_down(fdf);
	else if (keycode == 89)
		ft_proj_p_r(fdf);
	else if (keycode == 86)
		ft_proj_o(fdf);
	else if (keycode == 87)
		ft_proj_o_r(fdf);
	else if (keycode == 88)
		ft_proj_o_f(fdf);
	else if (keycode == 12 || keycode == 13 || keycode == 14 || keycode == 15)
		switch_colors(fdf, keycode);
	return (0);
}
