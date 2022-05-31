/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:15:41 by gkehren           #+#    #+#             */
/*   Updated: 2022/05/31 17:23:24 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int	print_stack(int *a, int *b, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		printf("%d | %d\n", a[i], b[i]);
		i++;
	}
	printf("\n");
	return (0);
}

int	is_sort_asc(int *a, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (a[i] < a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_sort_dsc(int *a, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (a[i] > a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	find_little(int *a, int len)
{
	int	i;
	int	little;

	i = 0;
	little = a[0];
	while (i < len)
	{
		if (a[i] < little)
				little = a[i];
		i++;
	}
	return (little);
}

void	sorting(int *a, int *b, int len)
{
	int	len_a;
	int	len_b;

	len_a = len + 1;
	len_b = 0;
	while (len_a > 0)
	{
		if (a[0] != find_little(a, len_a))
		{
			rotate_a(a, len_a);
			write(1, "ra\n", 3);
		}
		if (a[0] == find_little(a, len_a))
		{
			len_b += push_b(a, b, len);
			len_a--;
			write(1, "pb\n", 3);
		}
	}
	while (len_b > 0)
	{
		len_a += push_a(a, b, len);
		len_b--;
		write(1, "pa\n", 3);
	}
}

int	sort_stack(int *a, int *b, int len)
{
	if (is_sort_asc(a, len) == 1)
		return (0);
	sorting(a, b, len);
	return (0);
}
