/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:15:41 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/18 17:00:46 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	sort_100(int *a, int *b, int len)
{
	struct s_stack	stack;

	stack.a = a;
	stack.b = b;
	stack.len_a = len;
	stack.len_b = -1;
	push_b_mediane(&stack);
	sort_a_mediane(&stack);
	push_a_mediane(&stack);
}

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

void	sort_any(int *a, int *b, int len)
{
	struct s_stack	stack;

	stack.a = a;
	stack.b = b;
	stack.len_a = len;
	stack.len_b = -1;
	push_mediane(&stack);
	push_b_mediane_little(&stack);
	push_b_mediane_little(&stack);
	push_b_mediane_little(&stack);
	push_b_mediane(&stack);
	push_b_mediane(&stack);
	push_mediane(&stack);
	push_mediane_little(&stack, 5);
	push_mediane_little(&stack, 10);
	push_mediane_little(&stack, 20);
	push_mediane(&stack);
	push_mediane(&stack);
	sort_a_mediane(&stack);
	push_a_mediane(&stack);
}

int	sort_stack(int *a, int *b, int len)
{
	if (is_sort_asc(a, len) == 1)
		return (0);
	else if (len == 1)
		swap_a(a);
	else if (len < 3)
		sort_3(a, len);
	else if (len < 5)
		sort_5(a, b, len);
	else if (len < 80)
		sort_100(a, b, len);
	else
		sort_any(a, b, len);
	return (0);
}
