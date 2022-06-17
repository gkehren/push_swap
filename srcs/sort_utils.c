/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 22:56:30 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/17 16:32:00 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_max(int *a, int len)
{
	int	i;
	int	max;

	i = 0;
	max = a[0];
	while (i < len + 1)
	{
		if (a[i] > max)
				max = a[i];
		i++;
	}
	return (max);
}

int	find_min(int *a, int len)
{
	int	i;
	int	min;

	i = 0;
	min = a[0];
	while (i < len + 1)
	{
		if (a[i] < min)
				min = a[i];
		i++;
	}
	return (min);
}

int	how_many_moves(int *a, int len, int move)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < len + 1 && a[i] != move)
		i++;
	if (i < (len + 1) / 2 )
	{
		while (i != 0)
		{
			i--;
			count++;
		}
	}
	else
	{
		while (i < len + 1)
		{
			i++;
			count++;
		}
	}
	return (count);
}

void	need_top_a(int *a, int len, int move)
{
	int	i;
	int	count;

	count = 0;
	while (a[count] != move)
		count++;
	i = how_many_moves(a, len, move);
	if (count < (len + 1) / 2)
	{
		while (i > 0)
		{
			rotate_a(a, len);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			rrotate_a(a, len);
			i--;
		}
	}
}

void	need_top_b(int *b, int len, int move)
{
	int	i;
	int	count;

	count = 0;
	while (b[count] != move)
		count++;
	i = how_many_moves(b, len, move);
	if (count < (len + 1) / 2)
	{
		while (i > 0)
		{
			rotate_b(b, len);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			rrotate_b(b, len);
			i--;
		}
	}
}
