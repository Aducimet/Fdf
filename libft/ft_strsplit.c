/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 14:11:20 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 18:48:22 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		len_max(char const *s, char c)
{
	int nb;
	int i;

	nb = 0;
	i = 0;
	if (s)
	{
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			if (s[i] && s[i] != c)
				nb++;
			while (s[i] && s[i] != c)
				i++;
			i++;
		}
	}
	return (nb);
}

static int		decoupe(char const *s, char c, int i)
{
	int nb;

	nb = 0;
	if (s)
	{
		while (s[i] && s[i] != c)
		{
			nb++;
			i++;
		}
	}
	return (nb);
}

static int		check(char const *s, char c, int i)
{
	if (s)
	{
		while (s[i] && s[i] == c)
			i++;
	}
	return (i);
}

static char		**test(char const *s, char **str, char c, int i)
{
	int y;
	int x;

	y = 0;
	while (s[i])
	{
		x = 0;
		i = check(s, c, i);
		if (!(str[y] = (char*)malloc(sizeof(char) * decoupe(s, c, i) + 1)))
			return (NULL);
		while (s[i] != c && s[i])
			str[y][x++] = s[i++];
		i = check(s, c, i);
		str[y][x] = '\0';
		y++;
	}
	str[y] = 0;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;

	i = 0;
	i = check(s, c, i);
	if (!(str = (char**)malloc(sizeof(char*) * len_max(s, c) + 1)))
		return (NULL);
	if (s)
		str = test(s, str, c, i);
	return (str);
}