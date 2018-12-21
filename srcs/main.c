/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 16:26:15 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 16:56:32 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "FdF.h"
#include "../libft/libft.h"
#include <fcntl.h>

int count_line(int fd1)
{
    int ret;
    int count;
    char *line;

    count = 0;
    while ((ret = get_next_line(fd1, &line)) > 0)
    {   
        free(line);
        count++;
    }
    return (count);
}

int     coord_to_coord (t_fdf *fdf, int fd, int fd1)
{
    char    *line;
    int     ret;
    int     index;
    int     count;
	int 	len;
	char 	**tmp;
	int 	x;

    line = NULL;
	tmp = NULL;
    ret = 0;
    index = 0;
	count = count_line(fd1);
    if (!(fdf->map->coord = (t_point **)malloc(sizeof(t_point *) * (count))))
        return (-1);
    while ((ret = get_next_line(fd, &line)) > 0)
    {   
			tmp = ft_strsplit(line, ' ');
			x = 0;
			while (tmp[x])	
				x++;
			if (!(fdf->map->coord[index] = (t_point *)malloc(sizeof(t_point) * (x))))
				return (-1);
			len = 0;
			while (tmp[len])
			{	
                fdf->map->coord[index][len].x = len;
                fdf->map->coord[index][len].y = index;
				fdf->map->coord[index][len].z = (int)ft_atoi(tmp[len]);
                //printf("x = %f y = %f z = %f\n", fdf->map->coord[index][len].x, fdf->map->coord[index][len].y,fdf->map->coord[index][len].z);
				len++;
			}
			index++;
    }
    fdf->map->size.x = len;
    fdf->map->size.y = index;
    if (ret == 0)
        return (0);
    return (1);
}

int main(int argc, char **argv)
{
    int     fd;
    int     ret;
    int     fd1;
    t_fdf   *fdf;

    ret = 0;
    if (argc == 2)
    {   
        if ((fd = open(argv[1], O_RDONLY)) < 0 || (fd1 = open(argv[1], O_RDONLY)) < 0)
            return (-1);
        if ((fdf = define_fdf()) == NULL)
            return(-1);
        while ((ret = coord_to_coord(fdf, fd, fd1)) > 0)
			;
        ft_convert(&fdf);
    }
    else if (argc != 2)
    {
        ft_putendl("Usage ./FdF need one argument.");
    }
    return (0);
}