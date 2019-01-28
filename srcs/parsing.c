/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 15:24:38 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 17:07:12 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"
#include <fcntl.h>

void	ft_parse(t_fdf **afdf, int index, int len, char **tmp)
{
	t_fdf *fdf;

	fdf = *afdf;
	fdf->map->coord[index][len].x = len;
	fdf->map->coord[index][len].y = index;
	fdf->map->coord[index][len].z = (int)ft_atoi(tmp[len]);
	if (fdf->min_value > fdf->map->coord[index][len].z)
		fdf->min_value = fdf->map->coord[index][len].z;
	if (fdf->max_value < fdf->map->coord[index][len].z)
		fdf->max_value = fdf->map->coord[index][len].z;
}

int		ft_len_2dtab(char **tmp)
{
	int i;

	i = 0;
	while (tmp[i])
		i++;
	return (i);
}

int		malloc_t_point(int len, t_fdf **afdf, int index)
{
	t_fdf *fdf;

	fdf = *afdf;
	if (!(fdf->map->coord[index] = (t_point_3d *)
		malloc(sizeof(t_point_3d) * (len))))
		return (-1);
	return (0);
}
