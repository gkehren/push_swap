/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:15:41 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/06 16:35:51 by gkehren          ###   ########.fr       */
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
	printf("\n");
	return (0);
}

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
	int	mediane;
	int	len_b;

	mediane = find_mediane(a, len);
	len_b = len - push_b_mediane(a, b, len, mediane);
	sort_a_mediane(a, b, len - len_b, len);
	push_a_mediane(a, b, len_b + 1, len);
}

void	sort_b_mediane(int *a, int *b, int len, int len_push)
{
	int	len_b;
	int	i;

	i = 0;
	len_b = len;
	while (i < len + 1)
	{
		//printf("max = %d | len_b = %d\n", find_max(b, len_b), len_b);
		if (b[0] != find_max(b, len_b))
			need_top_b(b, len_b, find_max(b, len_b));
		//printf("b[0] = %d\n", b[0]);
		len_b -= push_a(a, b, len_push);
		i++;
	}
	while (i > 0)
		i -= push_b(a, b, len_push);
}

void	sort_any(int *a, int *b, int len)
{
	int	mediane;
	int	len_b;
	int	len_a;

	len_a = len;
	mediane = find_mediane(a, len);
	len_b = len - push_b_mediane(a, b, len - 1, mediane / 2);
	len_a -= len_b;
	(void)len_a;
	sort_b_mediane(a, b, len_b, len);
	print_stack(a, b, len);
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
	else if (len < 100)
		sort_100(a, b, len);
	else
		sort_any(a, b, len);
	return (0);
}
