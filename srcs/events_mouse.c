/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events_mouse.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 19:46:22 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 15:13:50 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_out(t_fdf **afdf)
{
	t_fdf	*fdf;

	fdf = *afdf;
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->ptr_img);
	fdf->scale /= 1.2;
	free(fdf->img);
	fdf->img = define_img(fdf->mlx_ptr, fdf->win_size_x, fdf->win_size_y);
	ft_convert(&fdf);
}

void	zoom_in(t_fdf **afdf)
{
	t_fdf	*fdf;

	fdf = *afdf;
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->ptr_img);
	fdf->scale *= 1.2;
	free(fdf->img);
	fdf->img = define_img(fdf->mlx_ptr, fdf->win_size_x, fdf->win_size_y);
	ft_convert(&fdf);
}

int		ft_mousepress(int keycode, int x, int y, t_fdf **fdf)
{
	x = y;
	if (keycode == 4)
		zoom_in(fdf);
	else if (keycode == 5)
		zoom_out(fdf);
	else if (keycode == 17)
		exit(0);
	return (0);
}
