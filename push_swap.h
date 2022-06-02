/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:42:23 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/02 16:29:08 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

int		sort_stack(int *a, int *b, int len);
int		rotate_a(int *a, int len);
int		rotate_b(int *b, int len);
int		rrotate_a(int *a, int len);
int		rrotate_b(int *b, int len);
int		swap_a(int *a);
int		swap_b(int *b);
int		push_a(int *a, int *b, int len);
int		push_b(int *a, int *b, int len);
char	**ft_split(char const *s, char c);
int		print_stack(int *a, int *b, int len);
int		is_sort_dsc(int *a, int len);
int		is_sort_asc(int *a, int len);
int		ra_or_rra(int *a, int find, int len);
int		find_min(int *a, int len);
int		sort_3(int *a, int len);
int		sort_5(int *a, int *b, int len);

#endif
