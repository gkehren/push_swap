/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:03:40 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/17 10:50:29 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

/*******STRUCT*******/

struct s_stack
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
	int	trigger;
};

/*******PARSING*******/

int		is_in(int *a, int b, int len);
int		is_valid(int *a, int len);
int		check_input(char *s);
int		parse_str(char *s, int **c);
int		parse_argv(int argc, char **argv, int *a);
void	memfree(char **s);
long	ft_atoi(char *s);
char	**ft_split(char const *s, char c);

/*******UTILS*******/

char	*get_prompt(void);
int		is_equal(char *s1, char *s2);
int		check_stack(struct s_stack *stack);
int		valid_sort(struct s_stack *stack, char **inst);

/*******MOVE*******/

int		push_a(int *a, int *b, int len_a, int len_b);
int		push_b(int *a, int *b, int len_a, int len_b);
int		swap_a(int *a);
int		swap_b(int *b);
int		rotate_a(int *a, int len);
int		rotate_b(int *b, int len);
int		rrotate_a(int *a, int len);
int		rrotate_b(int *b, int len);

#endif
