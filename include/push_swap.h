/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:42:23 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/19 22:17:49 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

/*******STRUCT*******/

struct s_stack
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
};

/*******PARSING*******/

int		check_input(char *s);
int		parse_str(char *s, int **c);
int		parse_argv(int argc, char **argv, int *a);
void	memfree(char **s);
long	ft_atoi(char *s);
char	**ft_split(char const *s, char c);

/*******MOVE*******/

int		push_a(int *a, int *b, int len_a, int len_b);
int		push_b(int *a, int *b, int len_a, int len_b);
int		swap_a(int *a);
int		swap_b(int *b);
int		rotate_a(int *a, int len);
int		rotate_b(int *b, int len);
int		rrotate_a(int *a, int len);
int		rrotate_b(int *b, int len);

/*******UTILS*******/

int		is_in(int *a, int b, int len);
int		is_valid(int *a, int len);
int		is_sort_asc(int *a, int len);
int		find_max(int *a, int len);
int		find_min(int *a, int len);
int		how_many_moves(int *a, int len, int move);
void	need_top_a(int *a, int len, int move);
void	need_top_b(int *b, int len, int move);
int		find_mediane(int *a, int len);
int		push_b_mediane(struct s_stack *stack);
void	sort_a_mediane(struct s_stack *stack);
void	push_a_mediane(struct s_stack *stack);
int		push_mediane(struct s_stack *stack);
int		push_mediane_little(struct s_stack *stack, int x);
int		push_b_mediane_little(struct s_stack *stack);
int		*abs_stack(int *a, int len);

/*******SORT*******/

int		sort_stack(int *a, int *b, int len);
int		sort_3(int *a, int len);
int		sort_5(int *a, int *b, int len);
void	sort_100(int *a, int *b, int len);
void	sort_any(int *a, int *b, int len);

#endif
