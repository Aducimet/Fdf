#include "libft.h"
#include <stdio.h>

struct	t_point
{
	int y;
	int x;
};


t_point		*create_point(int x, int y)
{
	t_point		*point_test;

	point_test = malloc(sizeof(t_point));
	point_test->x = x;
	point_test->y = y;
	return (point_test);
}

int		main()
{
	int		x;

	x = create_point(4, 5)->x;
	printf("Mon x : %d\n", x);
	char *str = "a string";

	printf("Mon char : %c\n", *ft_strchr(str , *ft_strchr(str, 't') - 1) );

}
