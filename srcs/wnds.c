/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wnds.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/04 18:17:39 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 19:17:18 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "FdF.h"
#define BLUE 0x0000FF

int 	ft_convert(t_fdf **afdf)
{	
	t_fdf *fdf;
	fdf = *afdf;
	int x;
	int y;
	int dx;
	int dy;
	int npixels;
	int i;
	int index;

	x = 0;
	y = 0;
	dx = 0;
	dy = 0;
	npixels = 0;
	i = 0;
	index = 0;
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 100, 100, "Fdf");
	while (y < (fdf->map->size.y))
	{
		x = 0;
		while (x < (fdf->map->size.x))
		{
			//printf("[%d][%d][%f]\n", x, y, fdf->map->coord[y][x].z);
			fdf->pixel->xP = (x * fdf->x_vector.xV * fdf->scale) + (y * fdf->y_vector.xV * fdf->scale) + (fdf->map->coord[y][x].z * fdf->z_vector.xV * fdf->scale);
			fdf->pixel->yP = (x * fdf->x_vector.yV * fdf->scale) + (y * fdf->y_vector.yV * fdf->scale) + (fdf->map->coord[y][x].z * fdf->z_vector.yV * fdf->scale);
			fdf->pixel->xP1 = ((x + 1) * fdf->x_vector.xV * fdf->scale) + (y * fdf->y_vector.xV * fdf->scale) + (fdf->map->coord[y][x + 1].z * fdf->z_vector.xV * fdf->scale);
			fdf->pixel->yP1 = (x * fdf->x_vector.yV * fdf->scale) + ((y + 1) * fdf->y_vector.yV * fdf->scale) + (fdf->map->coord[y + 1][x].z * fdf->z_vector.yV * fdf->scale);
			dx = fdf->pixel->xP1 - fdf->pixel->xP;
			dy = fdf->pixel->yP1 - fdf->pixel->yP;
			//printf("dx = %d\n", dx);
			//printf("dy = %d\n", dy);
			if (dx < 0)
				dx = dx * -1;
			if (dy < 0)
				dy = dy * -1;
			if (dx < dy)
			{	
				npixels = dy;
				dx = dx / dy;
				dy = dy / dy;
			}
			else
			{	
				npixels = dx;
				dy = dy / dx;
				dx = dx / dx;
			}
			i = 0;
			index = 0;
			if (y == (fdf->map->size.y))
				printf("ca rentre\n");
				index = npixels;
			while (i <= npixels)
			{	
				mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, dx * i + fdf->pixel->xP, dy * i + fdf->pixel->yP, 0x1B23B0); //bleu
				i++;
			}
			while (index < npixels)
			{	
				mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, dx * index + fdf->pixel->xP, dy * index + fdf->pixel->yP, 0xF005000); //vert
				index++;
			}
			//printf("x = %f  ", fdf->pixel->xP);
			//printf("y = %f\n", fdf->pixel->yP);
			x++;
		}
	    printf("Y = %d\n", y);
		y++;
	}
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
/*int ft_place_pixel(t_fdf **afdf)
{	
	int dx;
	int dy;
	t_fdf *fdf;
	int npixels;
	int i;
	int index;

	fdf = *afdf;
	dx = fdf->pixel->(xP + 1) - fdf->pixel->xP;
	dy = fdf->pixel->(yP + 1) - fdf->pixel->yP;
	if (dx < dy)
	{	
		npixels = dy;
		dx = dx / dy;
		dy = dy / dy;
	}
	else
	{	
		npixels = dx;
		dy = dy / dx;
		dx = dx / dx;
	}
	while (i <= npixels)
	{	
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, dx * i + fdf->pixel->xP, dy * i + fdf->pixel->yP, 0x1B23B0); //bleu
			i++;
	}
	while (index < npixels)
	{	
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, dx * index + fdf->pixel->xP+y, dy * index + fdf->pixel->yP, 0xF005000); //vert
			index++;
	}
	return (0);
}*/
/*int main (void)
{
	void 	*mlx_ptr;
	void	*win_ptr;
	//t_point	a;
	//t_point	b;
	float 	ax;
	float 	ay;
	float 	bx;
	float 	by;
	float 	cx;
	float 	cy;
	float 	ex;
	float 	ey;
	float 	dx;
	float 	dy;
	int		i;
	int		npixels;
	int 	index;

	ax = 100;
	ay = 100;
	bx = 400;
	by = 200;
	cx = 100;
	cy = 500;
	ex = 400;
	ey = 500;
	i = 0;
	index = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Fdf");
	dx = bx - ax;
	dy = by - ay;
	if (dx < dy)
	{	
		npixels = dy;
		dx = dx / dy;
		dy = dy / dy;
	}
	else
	{	
		npixels = dx;
		dy = dy / dx;
		dx = dx / dx;
	}
	while (i <= npixels)
	{	
		mlx_pixel_put(mlx_ptr, win_ptr, dx * i + ax, dy * i + ay, 0x1B23B0); //bleu
			i++;
	}
	while (index < npixels)
	{	
		mlx_pixel_put(mlx_ptr, win_ptr, dx * index + cx, dy * index + cy, 0xF005000); //vert
			index++;
	}
	i = 0;
	index = 0;
	dx = cx - ax;
	dy = cy - ay;
	if (dx < dy)
	{	
		npixels = dy;
		dx = dx / dy;
		dy = dy / dy;
	}
	else
	{	
		npixels = dx;
		dy = dy / dx;
		dx = dx / dx;
	}
	while (i <= npixels)
	{	
		mlx_pixel_put(mlx_ptr, win_ptr, dx * i + ax, dy * i + ay, 0xD31411); //rouge
			i++;
	}	
	while (index < npixels)
	{	
		mlx_pixel_put(mlx_ptr, win_ptr, dx * index + bx, dy * index + by, 0xE714E7); //rose
			index++;
	}
	mlx_loop(mlx_ptr);
}*/