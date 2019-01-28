/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events_keys2.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/17 19:24:05 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/28 16:15:42 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	scale_down(t_fdf **afdf)
{
	t_fdf	*fdf;

	fdf = *afdf;
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->ptr_img);
	fdf->scale_z *= 0.9;
	free(fdf->img);
	fdf->img = define_img(fdf->mlx_ptr, fdf->win_size_x, fdf->win_size_y);
	ft_convert(&fdf);
}

void	scale_up(t_fdf **afdf)
{
	t_fdf	*fdf;

	fdf = *afdf;
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->ptr_img);
	fdf->scale_z *= 1.1;
	free(fdf->img);
	fdf->img = define_img(fdf->mlx_ptr, fdf->win_size_x, fdf->win_size_y);
	ft_convert(&fdf);
}

void	switch_colors(t_fdf **afdf, int keycode)
{
	t_fdf *fdf;

	fdf = *afdf;
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->ptr_img);
	if (keycode == 12)
	{
		fdf->clr.in_color = 0xCC00CC;
		fdf->clr.out_color = 0x00CCC0;
	}
	if (keycode == 13)
	{
		fdf->clr.in_color = 0xBFFF00;
		fdf->clr.out_color = 0x007FFF;
	}
	if (keycode == 14)
	{
		fdf->clr.in_color = 0xFF9E01;
		fdf->clr.out_color = 0x4BB918;
	}
	free(fdf->img);
	fdf->img = define_img(fdf->mlx_ptr, fdf->win_size_x, fdf->win_size_y);
	ft_convert(&fdf);
}

void	move_arrows(t_fdf **afdf, int keycode)
{
	t_fdf	*fdf;

	fdf = *afdf;
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->ptr_img);
	if (keycode == 126)
		fdf->zero.y -= 12;
	if (keycode == 125)
		fdf->zero.y += 12;
	if (keycode == 124)
		fdf->zero.x += 12;
	if (keycode == 123)
		fdf->zero.x -= 12;
	free(fdf->img);
	fdf->img = define_img(fdf->mlx_ptr, fdf->win_size_x, fdf->win_size_y);
	ft_convert(&fdf);
}

void	ft_proj_o(t_fdf **afdf)
{
	t_fdf	*fdf;

	fdf = *afdf;
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->ptr_img);
	fdf->x_vector = define_vector(10, 4);
	fdf->y_vector = define_vector(-10, 4);
	fdf->z_vector = define_vector(0, -5.8);
	free(fdf->img);
	fdf->img = define_img(fdf->mlx_ptr, fdf->win_size_x, fdf->win_size_y);
	ft_convert(&fdf);
}
