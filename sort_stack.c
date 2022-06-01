/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:15:41 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/01 16:28:20 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int	print_stack(int *a, int *b, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		printf("%d | %d\n", a[i], b[i]);
		i++;
	}
	printf("\n");
	return (0);
}

int	is_sort_asc(int *a, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (a[i] < a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_sort_dsc(int *a, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (a[i] > a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	find_little(int *a, int len)
{
	int	i;
	int	little;

	i = 0;
	little = a[0];
	while (i < len)
	{
		if (a[i] < little)
				little = a[i];
		i++;
	}
	return (little);
}

int	ra_or_rra(int *a, int len)
{
	int	i;
	int	little;

	i = 0;
	little = find_little(a, len);
	while (a[i] != little)
		i++;
	if (i < len / 2)
		return (1);
	else
		return (0);
}

void	sorting(int *a, int *b, int len)
{
	int	len_a;
	int	len_b;

	len_a = len + 1;
	len_b = 0;
	while (is_sort_asc(a, len_a) == 0)
	{
		if (a[0] != find_little(a, len_a))
		{
			if (ra_or_rra(a, len_a) == 1)
			{
				rotate_a(a, len_a);
				write(1, "ra\n", 3);
			}
			else
			{
				rrotate_a(a, len_a);
				write(1, "rra\n", 4);
			}
		}
		if (is_sort_asc(a, len_a) == 1)
			break;
		if (a[0] == find_little(a, len_a))
		{
			len_b += push_b(a, b, len);
			len_a--;
			write(1, "pb\n", 3);
		}
	}
	//print_stack(a, b, len);
	while (len_b > 0)
	{
		len_a += push_a(a, b, len);
		len_b--;
		write(1, "pa\n", 3);
		//print_stack(a, b, len);
	}
}

int	sort_stack(int *a, int *b, int len)
{
	//print_stack(a, b, len);
	if (is_sort_asc(a, len) == 1)
		return (0);
	if (len < 11)
		little_sort(a, b, len);
	sorting(a, b, len);
	return (0);
}
