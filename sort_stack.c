/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:15:41 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/05 14:41:03 by gkehren          ###   ########.fr       */
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

void	sort_100(int *a, int *b, int len)
{
	int	mediane;
	int	len_b;

	mediane = find_mediane(a, len);
	len_b = len - push_b_mediane(a, b, len, mediane);
	sort_a_mediane(a, b, len - len_b, len);
	sort_b_mediane(a, b, len_b + 1, len);
}

int	sort_stack(int *a, int *b, int len)
{
	if (is_sort_asc(a, len) == 1)
		return (0);
	else if (len == 1)
		swap_a(a);
	else if (len < 3)
		sort_3(a, len);
	else if (len < 5)
		sort_5(a, b, len);
	else
		sort_100(a, b, len);
	return (0);
}
