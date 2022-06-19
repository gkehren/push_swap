/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:48:29 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/19 22:14:23 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	indice_min(int *a, int len, int min)
{
	int	i;

	i = 0;
	while (i < len + 1)
	{
		if (a[i] == min)
			return (i);
		i++;
	}
	return (-1);
}

int	destroy_min(int *a, int len, int d)
{
	int	i;

	i = 0;
	while (a[i] != d)
		i++;
	while (i < len)
	{
		a[i] = a[i + 1];
		i++;
	}
	return (len - 1);
}

int	*abs_stack(int *a, int len)
{
	int	*t;
	int	*o;
	int	t_len;
	int	i;
	int	j;

	i = 0;
	j = 1;
	t_len = len;
	t = (int *)malloc(sizeof(int) * len + 1);
	o = (int *)malloc(sizeof(int) * len + 1);
	while (i < len + 1)
	{
		o[i] = a[i];
		i++;
	}
	i = 0;
	while (i < t_len + 1)
	{
		t[indice_min(o, t_len, find_min(a, len))] = j;
		len = destroy_min(a, len, find_min(a, len));
		j++;
		i++;
	}
	return (t);
}
