/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:40:13 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/05 14:43:21 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_mediane(int *tmp, int len)
{
	int	min;
	int	temp;
	int	i;
	int	j;
	int	o;

	j = 0;
	o = 0;
	while (o < len + 1)
	{
		i = 0;
		min = find_min(tmp + j, len - j + 1);
		temp = tmp[j];
		while (tmp[i] != min)
			i++;
		tmp[j] = min;
		tmp[i] = temp;
		o++;
		j++;
	}
}

int	find_mediane(int *a, int len)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = (int *)malloc(sizeof(int) * len);
	while (i < len + 1)
	{
		tmp[i] = a[i];
		i++;
	}
	sort_mediane(tmp, len);
	if ((len + 1) % 2 == 1)
		return (tmp[(len + 1) / 2]);
	else
		return ((tmp[len / 2] + tmp[len / 2 + 1]) / 2);
}

int	push_b_mediane(int *a, int *b, int len, int mediane)
{
	int	i;

	i = 0;
	while (i < len + 1)
	{
		if (a[i] < mediane)
		{
			need_top_a(a, len + 1, a[i]);
			len -= push_b(a, b, len);
			i = 0;
		}
		else
			i++;
	}
	return (len + 1);
}

void	sort_a_mediane(int *a, int *b, int len, int len_push)
{
	int	len_a;
	int	len_b;

	len_a = len;
	len_b = 0;
	while (is_sort_asc(a, len_a) == 0)
	{
		if (a[0] != find_min(a, len_a))
			need_top_a(a, len_a, find_min(a, len_a));
		if (a[0] == find_min(a, len_a))
		{
			len_b += push_b(a, b, len_push);
			len_a--;
		}
	}
	while (len_b > 0)
	{
		len_a += push_a(a, b, len_push);
		len_b--;
	}
}

void	sort_b_mediane(int *a, int *b, int len, int len_push)
{
	while (len != 0)
	{
		need_top_b(b, len, find_max(b, len));
		len -= push_a(a, b, len_push - len);
	}
}
