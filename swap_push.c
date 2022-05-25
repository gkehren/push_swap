/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:56:20 by gkehren           #+#    #+#             */
/*   Updated: 2022/05/25 14:48:07 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(int *a)
{
	int	tmp;

	if (!a[0] || !a[1])
		return (-1);
	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
	return (0);
}

int	swap_b(int *b)
{
	int	tmp;

	if (!b[0] || !b[1])
		return (-1);
	tmp = b[0];
	b[0] = b[1];
	b[1] = tmp;
	return (0);
}

int	push_a(int *a, int *b, int len)
{
	int	i;

	if (!b[0])
		return (-1);
	i = len;
	while (i >= 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = b[0];
	i = 0;
	while (i <= len)
	{
		b[i] = b[i + 1];
		i++;
	}
	return (0);
}

int	push_b(int *a, int *b, int len)
{
	int	i;

	if (!a[0])
		return (-1);
	i = len;
	while (i >= 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	i = 0;
	b[0] = a[0];
	while (i <= len)
	{
		a[i] = a[i + 1];
		i++;
	}
	return (0);
}
