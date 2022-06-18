/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:28:47 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/18 02:02:30 by gkehren          ###   ########.fr       */
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
	while (a[i] != find_max(a, len))
		i++;
	while (a[0] != find_max(a, len))
	{
		if (i < len / 2)
			rotate_a(a, len);
		else
			rrotate_a(a, len);
	}
	push_b(a, b, len);
	return (1);
}

int	push_min_b(int *a, int *b, int len)
{
	int	i;

	i = 0;
	while (a[i] != find_min(a, len))
		i++;
	while (a[0] != find_min(a, len))
	{
		if (i < len / 2)
			rotate_a(a, len);
		else
			rrotate_a(a, len);
	}
	push_b(a, b, len);
	return (1);
}

int	sort_5(int *a, int *b, int len)
{
	struct s_stack	stack;

	stack.len_a = len;
	stack.len_b = -1;
	if (len == 4)
	{
		stack.len_b += push_min_b(a, b, stack.len_a);
		stack.len_a--;
		stack.len_b += push_max_b(a, b, stack.len_a);
		stack.len_a--;
		sort_3(a, stack.len_a);
		stack.len_a += push_a_test(a, b, stack.len_a, stack.len_b);
		stack.len_b--;
		rotate_a(a, stack.len_a);
		stack.len_a += push_a_test(a, b, stack.len_a, stack.len_b);
	}
	else
	{
		stack.len_b += push_min_b(a, b, stack.len_a);
		stack.len_a--;
		sort_3(a, stack.len_a);
		stack.len_a += push_a_test(a, b, stack.len_a, stack.len_b);
	}
	return (0);
}
