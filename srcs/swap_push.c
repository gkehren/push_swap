/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:56:20 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/17 14:18:52 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	swap_a(int *a)
{
	int	tmp;

	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
	write(1, "sa\n", 3);
	return (0);
}

int	swap_b(int *b)
{
	int	tmp;

	tmp = b[0];
	b[0] = b[1];
	b[1] = tmp;
	write(1, "sb\n", 3);
	return (0);
}

int	push_a(int *a, int *b, int len)
{
	int	i;

	i = len + 1;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = b[0];
	i = 0;
	while (i < len + 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	write(1, "pa\n", 3);
	return (1);
}

int	push_b(int *a, int *b, int len)
{
	int	i;

	i = len;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	i = 0;
	b[0] = a[0];
	while (i < len + 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	write(1, "pb\n", 3);
	return (1);
}

int	push_a_test(int *a, int *b, int len_a, int len_b)
{
	int	i;

	if (len_b == -1)
		return (0);
	len_a++;
	while (len_a > 0)
	{
		a[len_a] = a[len_a - 1];
		len_a--;
	}
	i = 0;
	a[0] = b[0];
	while (i < len_b + 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	write(1, "pa\n", 3);
	return (1);
}

int	push_b_test(int *a, int *b, int len_a, int len_b)
{
	int	i;

	if (len_a == -1)
		return (0);
	len_b++;
	while (len_b > 0)
	{
		b[len_b] = b[len_b - 1];
		len_b--;
	}
	i = 0;
	b[0] = a[0];
	while (i < len_a + 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	write(1, "pb\n", 3);
	return (1);
}
