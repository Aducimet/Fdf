/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   define_fdf.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 15:10:43 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/28 15:59:20 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*define_fdf(void)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		return (NULL);
	fdf->map = define_map();
	fdf->zero = define_point_2d(500, 500);
	fdf->win_size_x = 1000;
	fdf->win_size_y = 1000;
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_size_x,
			fdf->win_size_y, "FdF || Aducimet");
	fdf->x_vector = define_vector(10, 4);
	fdf->y_vector = define_vector(-10, 4);
	fdf->z_vector = define_vector(0, -5.8);
	fdf->clr.in_color = 0xFF9E01;
	fdf->clr.out_color = 0x4BB918;
	fdf->scale = 5;
	fdf->scale_z = 1;
	fdf->img = define_img(fdf->mlx_ptr, fdf->win_size_x, fdf->win_size_y);
	return (fdf);
}
