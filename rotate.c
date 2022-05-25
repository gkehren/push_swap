/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:57:13 by gkehren           #+#    #+#             */
/*   Updated: 2022/05/25 14:47:51 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(int *a)
{
	int	tmp;
	int	len;

	if (!a[0])
		return (-1);
	len = 0;
	tmp = a[0];
	while (a[len])
	{
		a[len] = a[len + 1];
		len++;
	}
	a[len - 1] = tmp;
	return (0);
}

int	rotate_b(int *b)
{
	int	tmp;
	int	len;

	if (!b[0])
		return (-1);
	len = 0;
	tmp = b[0];
	while (b[len])
	{
		b[len] = b[len + 1];
		len++;
	}
	b[len - 1] = tmp;
	return (0);
}

int	rrotate_a(int *a)
{
	int	tmp;
	int	len;

	if (!a[0])
		return (-1);
	len = 0;
	while (a[len] != 0)
		len++;
	tmp = a[len - 1];
	a[len - 1] = 0;
	len--;
	while (len >= 0)
	{
		a[len] = a[len - 1];
		len--;
	}
	a[0] = tmp;
	return (0);
}

int	rrotate_b(int *b)
{
	int	tmp;
	int	len;

	if (!b[0])
		return (-1);
	len = 0;
	while (b[len])
		len++;
	tmp = b[len - 1];
	b[len - 1] = 0;
	len--;
	while (len >= 0)
	{
		b[len] = b[len - 1];
		len--;
	}
	b[0] = tmp;
	return (0);
}
