/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:42:06 by gkehren           #+#    #+#             */
/*   Updated: 2022/05/25 13:11:53 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *s)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (-1);
		n *= 10;
		n += s[i] - '0';
		i++;
	}
	return (n);
}

int	main(int argc, char *argv[])
{
	int	*a;
	int	*b;
	int	i;
	int	j;

	i = 1;
	j = 0;
	a = (int *)malloc(sizeof(int) * argc);
	b = (int *)malloc(sizeof(int) * argc);
	while (i != argc)
	{
		a[j] = ft_atoi(argv[i]);
		if (a[j] == -1)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
		j++;
	}
	i = sort_stack(a, b, j - 1);
	if (i == -1)
		write(1, "Error\n", 6);
	free(a);
	free(b);
	return (0);
}
