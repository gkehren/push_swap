/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_any.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:30:35 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/08 13:25:27 by gkehren          ###   ########.fr       */
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

int	push_aled(int *a, int *b, int len_a, int len_b)
{
	int	i;
	int	count;
	int	len_a_t;
	int	mediane;

	i = 0;
	len_a_t = len_a;
	count = 0;
	mediane = find_mediane(a, len_a);
	while (i < len_a + 1)
	{
		if (a[i] < mediane)
		{
			need_top_a(a, len_a + 1, a[i]);
			len_a -= push_b(a, b, len_a_t + len_b);
			i = 0;
			count++;
		}
		else
			i++;
	}
	return (count);
}

void	aled(int *a, int *b, int len_a, int len_b)
{
	int	len;
	int	len_push;

	len = len_a + len_b;
	len_push = len_b;
	while (len_push >= 0)
	{
		need_top_b(b, len_b, find_max(b, len_b));
		len_a += push_a(a, b, len);
		len_b--;
		len_push--;
	}
}

void	sort_b(int *a, int *b, int len_a, int len_b)
{
	int	c;
	int	len_a_t;
	int	len_b_t;

	c = 0;
	len_a_t = len_a;
	len_b_t = len_b;
	while (len_b > 0)
	{
		if (b[0] != find_max(b, len_b + 1))
			need_top_b(b, len_b, find_max(b, len_b));
		len_a += push_a(a, b, len_a + len_b);
		len_b--;
		c++;
	}
	while (c > 0)
	{
		len_b += push_b(a, b, len_b_t + len_a_t);
		len_a--;
		c--;
	}
}
