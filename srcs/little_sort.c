/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:28:47 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/16 12:46:29 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort_3(int *a, int len)
{
	if (a[0] > a[1] && a[0] < a[2] && a[1] < a[2])
		swap_a(a);
	else if (a[0] > a[1] && a[0] > a[2] && a[1] < a[2])
		rotate_a(a, len);
	else if (a[0] < a[1] && a[0] > a[2] && a[1] > a[2])
		rrotate_a(a, len);
	else if (a[0] > a[1] && a[0] > a[2] && a[1] > a[2])
	{
		swap_a(a);
		rrotate_a(a, len);
	}
	else if (a[0] < a[1] && a[0] < a[2] && a[1] > a[2])
	{
		swap_a(a);
		rotate_a(a, len);
	}
	return (0);
}

int	push_max_b(int *a, int *b, int len)
{
	int	i;

	i = 0;
	while (a[i] != find_max(a, len + 1))
		i++;
	while (a[0] != find_max(a, len + 1))
	{
		if (i < len / 2)
			rotate_a(a, len + 1);
		else
			rrotate_a(a, len + 1);
	}
	push_b(a, b, len);
	return (0);
}

int	push_min_b(int *a, int *b, int len)
{
	int	i;

	i = 0;
	while (a[i] != find_min(a, len + 1))
		i++;
	while (a[0] != find_min(a, len + 1))
	{
		if (i < len / 2)
			rotate_a(a, len + 1);
		else
			rrotate_a(a, len + 1);
	}
	push_b(a, b, len);
	return (0);
}

int	sort_5(int *a, int *b, int len)
{
	int	len_a;
	int	len_b;

	if (len == 4)
	{
		push_min_b(a, b, len);
		push_max_b(a, b, len - 1);
		len_a = 3;
		len_b = 2;
		sort_3(a, len_a);
		len_a += push_a(a, b, len_b);
		rotate_a(a, len_a);
		len_a += push_a(a, b, len_a);
	}
	else
	{
		push_min_b(a, b, len);
		len_a = 2;
		len_b = 1;
		sort_3(a, len_a);
		len_a += push_a(a, b, len_b + 1);
	}
	return (0);
}
