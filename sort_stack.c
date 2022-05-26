/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:15:41 by gkehren           #+#    #+#             */
/*   Updated: 2022/05/26 19:57:01 by gkehren          ###   ########.fr       */
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

int	is_empty(int *a, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (a[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_sort(int *a, int *b, int len)
{
	int	i;

	if (is_empty(b, len) == 0)
		return (0);
	i = 1;
	while (a[i])
	{
		if (a[i] > a[i - 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_sort_asc(int *a, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
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
	while (i < len - 1)
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
	while (i < len - 1 && a[i])
	{
		if (a[i] < little)
				little = a[i];
		i++;
	}
	return (little);
}

void	sorting(int *a, int *b, int len)
{
	int	pb;
	int	i;

	pb = 0;
	i = 0;
	while (is_sort_dsc(b, len) == 0 && is_empty(a, len) == 0)
	{
		if (a[0] != find_little(a, len))
		{
			rotate_a(a);
			write(1, "ra\n", 3);
		}
		if (a[0] == find_little(a, len))
		{
			pb += push_b(a, b, len);
			write(1, "pb\n", 3);
		}
	}
	while (i <= pb)
	{
		push_a(a, b, len);
		write(1, "pa\n", 3);
		i++;
	}
}

int	sort_stack(int *a, int *b, int len)
{
	sorting(a, b, len + 1);
	//if (check_sort(a, b, len) == 1)
	//	print_stack(a, b, len);
	//else
	//	printf("no");
	return (0);
}
