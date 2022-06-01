/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:28:47 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/01 16:34:22 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_bigger(int *a, int len)
{
	int	i;
	int	bigger;

	i = 0;
	bigger = a[0];
	while (i < len)
	{
		if (a[i] > bigger)
				bigger = a[i];
		i++;
	}
	return (bigger);
}

int	ra_or_rra(int *a, int len)
{
	int	i;
	int	bigger;

	i = 0;
	bigger = find_bigger(a, len);
	while (a[i] != bigger)
		i++;
	if (i < len / 2)
		return (1);
	else
		return (0);
}

int	little_sort(int *a, int *b, int len)
{
	while (is_sort_asc(a, len) == 0)
	{

	}
}
