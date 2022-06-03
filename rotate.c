/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:57:13 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/03 15:58:46 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(int *a, int len)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = a[0];
	while (i < len + 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i - 2] = tmp;
	write(1, "ra\n", 3);
	return (0);
}

int	rotate_b(int *b, int len)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = b[0];
	while (i < len + 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i - 2] = tmp;
	write(1, "rb\n", 3);
	return (0);
}

int	rrotate_a(int *a, int len)
{
	int	tmp;

	tmp = a[len - 1];
	a[len - 1] = 0;
	len--;
	while (len > 0)
	{
		a[len] = a[len - 1];
		len--;
	}
	a[0] = tmp;
	write(1, "rra\n", 4);
	return (0);
}

int	rrotate_b(int *b, int len)
{
	int	tmp;

	tmp = b[len - 1];
	b[len - 1] = 0;
	len--;
	while (len > 0)
	{
		b[len] = b[len - 1];
		len--;
	}
	b[0] = tmp;
	write(1, "rrb\n", 4);
	return (0);
}
