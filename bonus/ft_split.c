/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:36:04 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/16 12:45:26 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

long	ft_atoi(char *s)
{
	long	n;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	n = 0;
	if (!s)
		return (-1);
	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i])
	{
		n *= 10;
		n += s[i] - '0';
		i++;
	}
	return (n * sign);
}

static void	ft_split_word(char *dest, char const *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != c && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	ft_count_word(char const *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (0);
	while (i < (int)size)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	tab = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			tab[k] = ft_strnew(j);
			ft_split_word(tab[k], s + i, c);
			i += j;
			k++;
		}
	}
	tab[k] = 0;
	return (tab);
}
