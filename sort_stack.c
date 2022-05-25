/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:15:41 by gkehren           #+#    #+#             */
/*   Updated: 2022/05/25 12:58:52 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_stack(int *a, int *b, int len)
{
	swap_a(a);
	push_b(a, b, len);
	push_b(a, b, len);
	push_b(a, b, len);
	rotate_a(a);
	rotate_b(b);
	rrotate_a(a);
	rrotate_b(b);
	swap_a(a);
	push_a(a, b, len);
	push_a(a, b, len);
	push_a(a, b, len);
	return (0);
}
