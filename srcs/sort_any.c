/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_any.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:30:35 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/18 03:14:17 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push_aled(struct s_stack *stack)
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
			push_b_test(stack->a, stack->b, stack->len_a, stack->len_b);
			stack->len_a--;
			stack->len_b++;
			i = 0;
		}
		else
			i++;
	}
	return (0);
}

int	push_aled_b(struct s_stack *stack)
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
			push_a_test(stack->a, stack->b, stack->len_a, stack->len_b);
			stack->len_b--;
			stack->len_a++;
			i = 0;
		}
		else
			i++;
	}
	return (0);
}
