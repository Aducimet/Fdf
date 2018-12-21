/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   count_nbrs.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 17:15:37 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 19:59:32 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int     count_nbrs(char *str)
{
    int index;
    int nb;

    nb = 0;
    index = 0;
    while (ft_isdigit(str))
    {
        if (ft_isspace(str) && (ft_isgit))
    }
    return (nb);
}

int main ()
{
    char *str;
    int nb;

    str = "123 456             789";
    nb = count_nbrs(str);
    printf("nb = %d\n", nb);
    return (0);
}