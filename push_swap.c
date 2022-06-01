/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:42:06 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/01 12:55:39 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_in(int *a, int b)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (a[i])
	{
		if (a[i] == b)
			c++;
		i++;
	}
	return (c);
}

int	is_valid(int *a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		if (is_in(a, a[i]) > 1)
			return (-1);
		else
			i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	*a;
	int	*b;
	int	i;

	i = 1;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		i = parse_str(argv[1], &a);
		if (i == -1 || is_valid(a) == -1)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		b = (int *)malloc(sizeof(int) * i);
		sort_stack(a, b, i - 1);
	}
	else
	{
		a = (int *)malloc(sizeof(int) * argc - 1);
		b = (int *)malloc(sizeof(int) * argc - 1);
		i = parse_argv(argc, argv, a);
		if (i == -1 || is_valid(a) == -1)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		sort_stack(a, b, i - 2);
	}
	free(a);
	free(b);
	return (0);
}
