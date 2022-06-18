/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:40:13 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/18 16:31:24 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_mediane(int *tmp, int len)
{
	int	min;
	int	temp;
	int	i;
	int	j;
	int	o;

	j = 0;
	o = 0;
	while (o < len + 1)
	{
		i = 0;
		min = find_min(tmp + j, len - j);
		temp = tmp[j];
		while (tmp[i] != min)
			i++;
		tmp[j] = min;
		tmp[i] = temp;
		o++;
		j++;
	}
}

int	find_mediane(int *a, int len)
{
	int	*tmp;
	int	mediane;
	int	i;

	i = 0;
	tmp = (int *)malloc(sizeof(int) * (len + 1));
	while (i < len + 1)
	{
		tmp[i] = a[i];
		i++;
	}
	sort_mediane(tmp, len);
	if ((len + 1) % 2 == 1)
		mediane = tmp[(len + 1) / 2];
	else
		mediane = (tmp[len / 2] + tmp[len / 2 + 1]) / 2;
	return (free(tmp), mediane);
}

int	push_b_mediane(struct s_stack *stack)
{
	int	i;
	int	mediane;

	i = 0;
	mediane = find_mediane(stack->b, stack->len_b);
	while (i < stack->len_b + 1)
	{
		if (stack->b[i] > mediane)
		{
			need_top_b(stack->b, stack->len_b, stack->b[i]);
			push_a(stack->a, stack->b, stack->len_a, stack->len_b);
			stack->len_b--;
			stack->len_a++;
			i = 0;
		}
		else
			i++;
	}
	return (0);
}

void	sort_a_mediane(struct s_stack *stack)
{
	int	c;
	int	min;

	c = 0;
	while (is_sort_asc(stack->a, stack->len_a) == 0)
	{
		min = find_min(stack->a, stack->len_a);
		if (stack->a[0] != min)
			need_top_a(stack->a, stack->len_a, min);
		if (stack->a[0] == min)
		{
			push_b(stack->a, stack->b, stack->len_a, stack->len_b);
			stack->len_b++;
			stack->len_a--;
			c++;
		}
	}
	while (c > 0)
	{
		push_a(stack->a, stack->b, stack->len_a, stack->len_b);
		stack->len_a++;
		stack->len_b--;
		c--;
	}
}

void	push_a_mediane(struct s_stack *stack)
{
	while (stack->len_b != -1)
	{
		need_top_b(stack->b, stack->len_b, find_max(stack->b, stack->len_b));
		push_a(stack->a, stack->b, stack->len_a, stack->len_b);
		stack->len_a++;
		stack->len_b--;
	}
}
