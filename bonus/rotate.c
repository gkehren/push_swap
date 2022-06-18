/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:57:13 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/18 02:05:38 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	rotate_a(int *a, int len)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = a[0];
	while (i < len)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[len] = tmp;
	return (0);
}

int	rotate_b(int *b, int len)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = b[0];
	while (i < len)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[len] = tmp;
	return (0);
}

int	rrotate_a(int *a, int len)
{
	int	tmp;

	tmp = a[len];
	a[len] = 0;
	while (len > 0)
	{
		a[len] = a[len - 1];
		len--;
	}
	a[0] = tmp;
	return (0);
}

int	rrotate_b(int *b, int len)
{
	int	tmp;

	tmp = b[len];
	b[len] = 0;
	while (len > 0)
	{
		b[len] = b[len - 1];
		len--;
	}
	b[0] = tmp;
	return (0);
}
