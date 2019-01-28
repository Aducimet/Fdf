/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wnds_utils.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 17:47:42 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 17:14:23 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	set_line(t_point_2d *step, t_point_2d *src, t_point_2d *dst)
{
	step->x = dst->x - src->x;
	step->y = dst->y - src->y;
}

void	new_point(t_point_2d *pos, t_point_2d src, int i, t_point_2d step)
{
	pos->x = src.x + i * step.x;
	pos->y = src.y + i * step.y;
}

void	img_put_pixel(t_fdf *fdf, t_point_2d pos, int color)
{
	if ((pos.x > 0 && pos.x < fdf->win_size_x) &&
	(pos.y > 0 && pos.y < fdf->win_size_y))
		fdf->img->tab[((int)pos.y * fdf->win_size_y + (int)pos.x)] = color;
}

void	put_pixel(t_point_2d pos, t_fdf *fdf, int color)
{
	if ((pos.x >= 0 && pos.x < fdf->win_size_x) &&
	(pos.y >= 0 && pos.y < fdf->win_size_y))
	{
		img_put_pixel(fdf, pos, color);
	}
}

int		leading_coefficiant(t_point_2d *step)
{
	float	tmp;
	float	tmp1;
	int		n;

	tmp = ABS(step->x);
	tmp1 = ABS(step->y);
	if (tmp > tmp1)
	{
		n = ABS(step->x);
		step->y /= ABS(step->x);
		step->x /= ABS(step->x);
	}
	else
	{
		n = ABS(step->y);
		step->x /= ABS(step->y);
		step->y /= ABS(step->y);
	}
	return (n);
}
