/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 17:40:28 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 17:06:21 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "FdF.h"
#include "../libft/libft.h"

t_vector    define_vector(float x, float y)
{
    t_vector    vector;

    vector.xV = x;
    vector.yV = y;
    return (vector);
}

t_map       *define_map(void)
{
    t_map   *map;

    if (!(map = (t_map *)malloc(sizeof(t_map))))
		  return (NULL);
    map->coord = NULL;
    return (map);
}

t_fdf       *define_fdf(void)
{
    t_fdf  *fdf;

    if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		  return (NULL);
    fdf->pixel = define_pixel();
    fdf->map = define_map();
    fdf->mlx_ptr = NULL;
    fdf->win_ptr = NULL;
    fdf->x_vector = define_vector(1, 0);
    fdf->y_vector = define_vector(0, 1);
    fdf->z_vector = define_vector(0.5, -0.5);
    fdf->scale = 1;
    return (fdf);
}

t_pixel     *define_pixel(void)
{
    t_pixel     *pixel;

    if (!(pixel = malloc(sizeof(t_pixel))))
		return (0);
    pixel->xP = 0;
    pixel->yP = 0;
    return (pixel);
}
