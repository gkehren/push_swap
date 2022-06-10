/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:15:41 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/10 13:40:25 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_sort_dsc(int *a, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (a[i] > a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void	sort_100(int *a, int *b, int len)
{
	int	len_b;

	len_b = len - push_b_mediane(a, b, len, find_mediane(a, len));
	sort_a_mediane(a, b, len - len_b, len);
	push_a_mediane(a, b, len_b + 1, len);
}
#include <stdio.h>
void	sort_any(int *a, int *b, int len)
{
	int	len_b;
	int	len_a;

	len_b = push_aled(a, b, len, 0) - 1;
	len_a = len - len_b - 1;
	len_b -= push_aled_b(a, b, len_a, len_b);
	len_a = len - len_b - 1;
	len_b -= push_aled_b(a, b, len_a, len_b);
	len_a = len - len_b - 1;
	len_b += push_aled(a, b, len_a, len_b);
	len_a = len - len_b - 1;
	len_b += push_aled(a, b, len_a, len_b);
	len_a = len - len_b - 1;
	len_b += push_aled(a, b, len_a, len_b);
	len_a = len - len_b - 1;
	sort_a_mediane_any(a, b, len_a + 1, len_a + len_b + 1);
	aled(a, b, len_a, len_b + 1);
	//print_stack(a, b, len);
	//printf("len_a = %d | len_b = %d | len = %d\n", len_a, len_b, len);
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
