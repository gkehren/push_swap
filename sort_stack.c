/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:15:41 by gkehren           #+#    #+#             */
/*   Updated: 2022/05/24 18:37:22 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int	swap_a(int *a)
{
	int tmp;

	if (!a[0] || !a[1])
		return (-1);
	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
	return (0);
}

int	swap_b(int *b)
{
	int tmp;

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

	if (!a[0])
		return (-1);
	i = 0;
	while (b[i])
		i++;
	b[i] = a[0];
	i = 0;
	while (i <= len)
	{
		a[i] = a[i + 1];
		i++;
	}
	return (0);
}

int	push_b(int *a, int *b, int len)
{
	int	i;

	if (!b[0])
		return (-1);
	i = 0;
	while (a[i])
		i++;
	a[i] = b[0];
	i = 0;
	while (i <= len)
	{
		b[i] = b[i + 1];
		i++;
	}
	return (0);
}

int	rotate_a(int *a, int len)
{
	if (!a[0])
		return (-1);

}

int	sort_stack(int *a, int *b, int len)
{
	int	i;

	i = 0;
	while (i < len + 1)
	{
		push_b(a, b, len);
		i++;
	}
	i = 0;
	//swap_b(b, len);
	while (i <= len)
	{
		printf("%d | %d\n", a[i], b[i]);
		i++;
	}
	return (0);
}
