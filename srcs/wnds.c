/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wnds.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/04 18:17:39 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 18:09:53 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		lerp(int start, int end, double percent)
{
	int r;
	int g;
	int b;

	r = (start >> 16) + percent * ((end >> 16) - (start >> 16));
	g = ((start >> 8) & 0xFF) + percent * (((end >> 8) & 0xFF)
	- ((start >> 8) & 0xFF));
	b = ((start & 0xFF) + percent * ((end & 0xFF) - (start & 0xFF)));
	return ((r << 16) | (g << 8) | (b | 0));
}

int		set_color(t_fdf **afdf, int current)
{
	t_fdf	*fdf;
	double	prop;
	int		color;

	fdf = *afdf;
	prop = (double)(current - fdf->min_value) /
	(double)(fdf->max_value - fdf->min_value);
	color = lerp(fdf->clr.in_color, fdf->clr.out_color, prop);
	return (color);
}

void	draw_line(t_fdf *fdf, t_point_2d src, t_point_2d dst)
{
	t_point_2d		step;
	t_point_2d		pos;
	int				n;
	int				i;
	int				color;

	i = -1;
	set_line(&step, &src, &dst);
	n = leading_coefficiant(&step);
	while (++i < n)
	{
		new_point(&pos, src, i, step);
		color = lerp(src.color, dst.color, (double)i / (double)n);
		put_pixel(pos, fdf, color);
	}
}

int		ft_convert(t_fdf **afdf)
{
	t_fdf		*fdf;
	t_point_3d	point;

	fdf = *afdf;
	point = define_point_3d(0, 0, 0);
	while (point.y < (fdf->map->size.y))
	{
		point.x = 0;
		while (point.x < fdf->map->size.x)
		{
			ft_find_proj(&fdf, point);
			point.x++;
		}
		point.y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
	fdf->img->ptr_img, 0, 0);
	return (0);
}
