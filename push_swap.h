/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:42:23 by gkehren           #+#    #+#             */
/*   Updated: 2022/05/25 13:01:19 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

int	sort_stack(int *a, int *b, int len);
int	rotate_a(int *a);
int	rotate_b(int *b);
int	rrotate_a(int *a);
int	rrotate_b(int *b);
int	swap_a(int *a);
int	swap_b(int *b);
int	push_a(int *a, int *b, int len);
int	push_b(int *a, int *b, int len);

#endif
