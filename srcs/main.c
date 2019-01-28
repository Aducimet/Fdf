/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 16:26:15 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 17:05:50 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"
#include <fcntl.h>

int	count_line(int fd1)
{
	int		ret;
	int		count;
	char	*line;

	count = 0;
	while ((ret = get_next_line(fd1, &line)) > 0)
	{
		free(line);
		count++;
	}
	return (count);
}

int	coord_to_coord(t_fdf *fdf, int fd, int fd1)
{
	char	*line;
	int		len;
	char	**tmp;
	int		index;
	int		count;

	index = 0;
	count = count_line(fd1);
	if (!(fdf->map->coord = (t_point_3d **)malloc(sizeof(t_point_3d *) *
					(count))))
		return (-1);
	while ((get_next_line(fd, &line)) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		free(line);
		malloc_t_point(len, &fdf, index);
		len = 0;
		while (tmp[len])
			ft_parse(&fdf, index, len++, tmp);
		index++;
		ft_2dstrdel(&tmp);
	}
	fdf->map->size.x = len;
	fdf->map->size.y = count;
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		ret;
	int		fd1;
	t_fdf	*fdf;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0 ||
				(fd1 = open(argv[1], O_RDONLY)) < 0)
			return (-1);
		if ((fdf = define_fdf()) == NULL)
			return (-1);
		while ((ret = coord_to_coord(fdf, fd, fd1)) > 0)
			;
		ft_convert(&fdf);
		mlx_hook(fdf->win_ptr, 2, (1L << 0), ft_keypress, &fdf);
		mlx_mouse_hook(fdf->win_ptr, ft_mousepress, &fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	else
		ft_putendl("Usage ./FdF need one argument.");
	return (0);
}
