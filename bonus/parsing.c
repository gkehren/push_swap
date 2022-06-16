/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:29:15 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/16 12:45:00 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	is_in(int *a, int b, int len)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < len + 1)
	{
		if (a[i] == b)
			c++;
		i++;
	}
	return (c);
}

int	is_valid(int *a, int len)
{
	int	i;

	i = 0;
	while (i < len + 1)
	{
		if (is_in(a, a[i], len) > 1)
			return (-1);
		else
			i++;
	}
	return (0);
}

int	check_input(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	if (s[0] == '-')
		i++;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (-1);
		i++;
	}
	return (0);
}

int	parse_str(char *s, int **c)
{
	char	**str;
	int		*a;
	int		i;
	long	tmp;

	i = 0;
	str = ft_split(s, ' ');
	while (str[i])
		i++;
	a = (int *)malloc(sizeof(int) * (i));
	i = 0;
	while (str[i])
	{
		if (check_input(str[i]) == -1)
			return (-1);
		tmp = ft_atoi(str[i]);
		if (tmp < 2147483648 && tmp > -2147483649)
			a[i] = tmp;
		else
			return (-1);
		i++;
	}
	*c = a;
	free(str);
	return (i);
}

int	parse_argv(int argc, char **argv, int *a)
{
	int		i;
	long	tmp;

	i = 1;
	while (i != argc)
	{
		if (check_input(argv[i]) == -1)
			return (-1);
		tmp = ft_atoi(argv[i]);
		if (tmp < 2147483648 && tmp > -2147483649)
			a[i - 1] = tmp;
		else
			return (-1);
		i++;
	}
	return (i);
}
