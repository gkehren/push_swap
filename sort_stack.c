/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:15:41 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/07 18:04:55 by gkehren          ###   ########.fr       */
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
	int	len_b;

	len_b = len - push_b_mediane(a, b, len, find_mediane(a, len));
	sort_a_mediane(a, b, len - len_b, len);
	push_a_mediane(a, b, len_b + 1, len);
}

int	push_aled(int *a, int *b, int len_a, int mediane)
{
	int	i;
	int	count;
	int	len_a_t;

	i = 0;
	len_a_t = len_a;
	count = 0;
	while (i < len_a + 1)
	{
		if (a[i] < mediane)
		{
			need_top_a(a, len_a + 1, a[i]);
			len_a -= push_b(a, b, len_a_t);
			i = 0;
			count++;
		}
		else
			i++;
	}
	return (count);
}

void	aled(int *a, int *b, int len_a, int len_b, int len_push)
{
	int	len;

	len = len_a + len_b;
	while (len_push > 0)
	{
		//printf("len_a = %d | len_b = %d | len_push = %d\n", len_a, len_b, len_push);
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
		if (b[0] != find_max(b, len_b))
			need_top_b(b, len_b, find_max(b, len_b));
		len_a += push_a(a, b, len_a);
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

void	sort_any(int *a, int *b, int len)
{
	int	len_b;
	int	len_a;

	len_b = push_aled(a, b, len, (find_mediane(a, len) / 2)) - 1;
	len_a = len - len_b - 1;
	sort_b(a, b, len_a, len_b + 1);
	//printf("len_a = %d | len_b = %d\n", len_a, len_b);
	len_b += push_aled(a, b, len_a, find_mediane(a, len_a));
	len_a = len - len_b - 1;
	//sort_b(a, b, len_a, len_b);
	sort_a_mediane(a, b, len_a + 1, len_a + len_b + 1);
	aled(a, b, len_a, len_b, len_b + 1);
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
	else if (len < 100)
		sort_100(a, b, len);
	else
		sort_any(a, b, len);
	return (0);
}
