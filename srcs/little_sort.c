/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:28:47 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/18 16:16:25 by gkehren          ###   ########.fr       */
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

int	push_max_b(int *a, int *b, int len_a, int len_b)
{
	int	i;

	i = 0;
	while (a[i] != find_max(a, len_a))
		i++;
	while (a[0] != find_max(a, len_a))
	{
		if (i < len_a / 2)
			rotate_a(a, len_a);
		else
			rrotate_a(a, len_a);
	}
	push_b(a, b, len_a, len_b);
	return (1);
}

int	push_min_b(int *a, int *b, int len_a, int len_b)
{
	int	i;

	i = 0;
	while (a[i] != find_min(a, len_a))
		i++;
	while (a[0] != find_min(a, len_a))
	{
		if (i < len_a / 2)
			rotate_a(a, len_a);
		else
			rrotate_a(a, len_a);
	}
	push_b(a, b, len_a, len_b);
	return (1);
}

int	sort_5(int *a, int *b, int len)
{
	struct s_stack	stack;

	stack.len_a = len;
	stack.len_b = -1;
	if (len == 4)
	{
		stack.len_b += push_min_b(a, b, stack.len_a, stack.len_b);
		stack.len_a--;
		stack.len_b += push_max_b(a, b, stack.len_a, stack.len_b);
		stack.len_a--;
		sort_3(a, stack.len_a);
		stack.len_a += push_a(a, b, stack.len_a, stack.len_b);
		stack.len_b--;
		rotate_a(a, stack.len_a);
		stack.len_a += push_a(a, b, stack.len_a, stack.len_b);
	}
	else
	{
		stack.len_b += push_min_b(a, b, stack.len_a, stack.len_b);
		stack.len_a--;
		sort_3(a, stack.len_a);
		stack.len_a += push_a(a, b, stack.len_a, stack.len_b);
	}
	return (0);
}
