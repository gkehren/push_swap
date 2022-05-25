/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:15:41 by gkehren           #+#    #+#             */
/*   Updated: 2022/05/25 15:57:03 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int	print_stack(int *a, int *b, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		printf("%d | %d\n", a[i], b[i]);
		i++;
	}
	return (0);
}

int	is_sort(int *a, int *b)
{
	int	i;

	i = 0;
	while (b[i])
		i++;
	if (i > 0)
		return (0);
	i = 0;
	while (a[i - 1])
	{
		if (a[i] < a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	sort_stack(int *a, int *b, int len)
{
	swap_a(a);
	push_b(a, b, len);
	push_b(a, b, len);
	push_b(a, b, len);
	rotate_a(a);
	rotate_b(b);
	rrotate_a(a);
	rrotate_b(b);
	swap_a(a);
	push_a(a, b, len);
	push_a(a, b, len);
	push_a(a, b, len);

	if (is_sort(a, b) == 1)
		print_stack(a, b, len);
	else
		printf("no");
	return (0);
}
