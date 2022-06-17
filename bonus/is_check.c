/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:04:03 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/17 10:53:46 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	is_swap(int *a, int *b, char *inst)
{
	if (is_equal(inst, "sa") == 1)
		swap_a(a);
	else if (is_equal(inst, "sb") == 1)
		swap_b(b);
	else if (is_equal(inst, "ss") == 1)
	{
		swap_a(a);
		swap_b(b);
	}
}

void	is_rotate(struct s_stack *stack, char *inst)
{
	if (is_equal(inst, "ra") == 1)
		rotate_a(stack->a, stack->len_a);
	else if (is_equal(inst, "rb") == 1)
		rotate_b(stack->b, stack->len_b);
	else if (is_equal(inst, "rr") == 1)
	{
		rotate_a(stack->a, stack->len_a);
		rotate_b(stack->b, stack->len_b);
	}
	else if (is_equal(inst, "rra") == 1)
		rrotate_a(stack->a, stack->len_a);
	else if (is_equal(inst, "rrb") == 1)
		rrotate_b(stack->b, stack->len_b);
	else if (is_equal(inst, "rrr") == 1)
	{
		rrotate_a(stack->a, stack->len_a);
		rrotate_b(stack->b, stack->len_b);
	}
}

void	is_push(struct s_stack *stack, char *inst)
{
	if (stack->len_a == -1)
		stack->trigger = 1;
	if (is_equal(inst, "pa") == 1)
	{
		push_a(stack->a, stack->b, stack->len_a + 1, stack->len_b);
		stack->len_a++;
		stack->len_b--;
	}
	else if (is_equal(inst, "pb") == 1)
	{
		push_b(stack->a, stack->b, stack->len_a, stack->len_b + 1);
		stack->len_b++;
		stack->len_a--;
	}
}

int	valid_sort(struct s_stack *stack, char **inst)
{
	int	i;

	i = 0;
	while (inst[i])
	{
		is_swap(stack->a, stack->b, inst[i]);
		is_push(stack, inst[i]);
		is_rotate(stack, inst[i]);
		i++;
	}
	if (check_stack(stack) == 1)
		return (1);
	else
		return (0);
}
