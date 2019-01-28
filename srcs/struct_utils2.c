/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils2.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 17:15:48 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 16:43:26 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_point_2d	ft_proj_x(t_fdf **afdf, t_point_3d point)
{
	t_fdf		*fdf;
	t_point_2d	proj2;

	fdf = *afdf;
	proj2 = define_point_2d(fdf->zero.x + ((point.x + 1)
	* fdf->x_vector.xv * fdf->scale)
	+ (point.y * fdf->y_vector.xv * fdf->scale)
	+ (fdf->map->coord[(int)point.y][(int)point.x + 1].z
	* fdf->z_vector.xv * fdf->scale),
	fdf->zero.y + ((point.x + 1) * fdf->x_vector.yv * fdf->scale)
	+ (point.y * fdf->y_vector.yv * fdf->scale)
	+ (fdf->map->coord[(int)point.y][(int)point.x + 1].z
	* (fdf->z_vector.yv * fdf->scale) * fdf->scale_z));
	proj2.color = set_color(&fdf, fdf->map->coord
	[(int)point.y][(int)point.x + 1].z);
	return (proj2);
}

t_point_2d	ft_proj_y(t_fdf **afdf, t_point_3d point)
{
	t_fdf		*fdf;
	t_point_2d	proj2;

	fdf = *afdf;
	proj2 = define_point_2d(fdf->zero.x + (point.x
	* fdf->x_vector.xv * fdf->scale)
	+ ((point.y + 1) * fdf->y_vector.xv * fdf->scale)
	+ (fdf->map->coord[(int)point.y + 1]
	[(int)point.x].z * fdf->z_vector.xv * fdf->scale),
	fdf->zero.y + (point.x * fdf->x_vector.yv * fdf->scale)
	+ ((point.y + 1) * fdf->y_vector.yv * fdf->scale)
	+ (fdf->map->coord[(int)point.y + 1]
	[(int)point.x].z * (fdf->z_vector.yv * fdf->scale) * fdf->scale_z));
	proj2.color = set_color(&fdf, fdf->map->coord[(int)point.y + 1]
	[(int)point.x].z);
	return (proj2);
}

void		ft_find_proj(t_fdf **afdf, t_point_3d point)
{
	t_fdf		*fdf;
	t_point_2d	proj;
	t_point_2d	proj2;

	fdf = *afdf;
	proj = define_point_2d(fdf->zero.x + (point.x
	* fdf->x_vector.xv * fdf->scale)
	+ (point.y * fdf->y_vector.xv * fdf->scale)
	+ (fdf->map->coord[(int)point.y][(int)point.x].z
	* fdf->z_vector.xv * fdf->scale),
	fdf->zero.y + (point.x * fdf->x_vector.yv * fdf->scale)
	+ (point.y * fdf->y_vector.yv
	* fdf->scale) + (fdf->map->coord[(int)point.y][(int)point.x].z
	* (fdf->z_vector.yv * fdf->scale) * fdf->scale_z));
	proj.color = set_color(&fdf, fdf->map->coord[(int)point.y][(int)point.x].z);
	if (point.x + 1 < fdf->map->size.x)
	{
		proj2 = ft_proj_x(&fdf, point);
		draw_line(fdf, proj, proj2);
	}
	if (point.y + 1 < fdf->map->size.y)
	{
		proj2 = ft_proj_y(&fdf, point);
		draw_line(fdf, proj, proj2);
	}
}
