/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:15:41 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/19 22:16:05 by gkehren          ###   ########.fr       */
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
	a = abs_stack(a, len);
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
