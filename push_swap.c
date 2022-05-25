/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:42:06 by gkehren           #+#    #+#             */
/*   Updated: 2022/05/25 15:12:48 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *s)
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

int	free_int(int *a, int *b)
{
	free(a);
	free(b);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	*a;
	int	*b;
	int	i;

	i = 1;
	a = (int *)malloc(sizeof(int) * argc);
	b = (int *)malloc(sizeof(int) * argc);
	while (i != argc)
	{
		if (check_input(argv[i]) == -1)
		{
			write(1, "Error\n", 6);

			return (0);
		}
		a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	sort_stack(a, b, i - 2);
	free_int(a, b);
	return (0);
}
