/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 22:15:50 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/19 22:18:09 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push_mediane(struct s_stack *stack)
{
	int	i;
	int	mediane;

	i = 0;
	mediane = find_mediane(stack->a, stack->len_a);
	while (i < stack->len_a + 1)
	{
		if (stack->a[i] < mediane)
		{
			need_top_a(stack->a, stack->len_a, stack->a[i]);
			push_b(stack->a, stack->b, stack->len_a, stack->len_b);
			stack->len_a--;
			stack->len_b++;
			i = 0;
		}
		else
			i++;
	}
	return (0);
}

int	push_mediane_little(struct s_stack *stack, int x)
{
	int	i;
	int	mediane;

	i = 0;
	mediane = find_mediane(stack->a, stack->len_a);
	mediane -= (mediane / x);
	while (i < stack->len_a + 1)
	{
		if (stack->a[i] < mediane)
		{
			need_top_a(stack->a, stack->len_a, stack->a[i]);
			push_b(stack->a, stack->b, stack->len_a, stack->len_b);
			stack->len_a--;
			stack->len_b++;
			i = 0;
		}
		else
			i++;
	}
	return (0);
}

int	push_b_mediane_little(struct s_stack *stack)
{
	int	i;
	int	mediane;

	i = 0;
	mediane = find_mediane(stack->b, stack->len_b);
	mediane += (mediane / 2);
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
