/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_any.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 22:56:30 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/05 14:36:49 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(int *a, int len)
{
	int	i;
	int	max;

	i = 0;
	max = a[0];
	while (i < len)
	{
		if (a[i] > max)
				max = a[i];
		i++;
	}
	return (max);
}

int	how_many_moves(int *a, int len, int move)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < len && a[i] != move)
		i++;
	if (i < len / 2 + 1)
	{
		while (i != 0)
		{
			i--;
			count++;
		}
	}
	else
	{
		while (i < len)
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
	if (count < (len / 2) + 1)
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
