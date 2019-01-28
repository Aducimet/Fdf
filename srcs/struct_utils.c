/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 17:40:28 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 15:43:08 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"

t_point_3d	define_point_3d(int x, int y, int z)
{
	t_point_3d	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_point_2d	define_point_2d(float x, float y)
{
	t_point_2d	point;

	point.x = x;
	point.y = y;
	return (point);
}

t_vector	define_vector(float x, float y)
{
	t_vector	vector;

	vector.xv = x;
	vector.yv = y;
	return (vector);
}

t_map		*define_map(void)
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->coord = NULL;
	return (map);
}

t_img		*define_img(void *mlx_ptr, int win_size_x, int win_size_y)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	img->ptr_img = mlx_new_image(mlx_ptr, win_size_x, win_size_y);
	img->tab = (int*)mlx_get_data_addr(img->ptr_img, &(img->bpp),
			&(img->s_l), &(img->endian));
	return (img);
}
