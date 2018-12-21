/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_coord.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 16:16:19 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 16:31:06 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "FdF.h"
#include "../libft/libft.h"
#include <stdio.h>

int     coord_to_coord (char **tab, int fd)
{
    char    *line;
    int     ret;
    int     index;

    line = NULL;
    ret = 0;
    index = 0;
    if ((*tab = (char **)malloc(sizeof(char *) * (4 + 2))) == NULL)
        return (-1);
    while (index <= 2 && (ret = get_next_line(fd, &line)) > 0)
    {
        (*tab[index] = ft_strdup(line));
        ft_strdel(&line);
        index++;
    }
}