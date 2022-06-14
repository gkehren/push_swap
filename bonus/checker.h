/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:03:40 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/14 15:09:58 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

/*******PARSING*******/

int		is_in(int *a, int b, int len);
int		is_valid(int *a, int len);
int		check_input(char *s);
int		parse_str(char *s, int **c);
int		parse_argv(int argc, char **argv, int *a);
long	ft_atoi(char *s);
char	**ft_split(char const *s, char c);

/*******MOVE*******/

int		push_a(int *a, int *b, int len);
int		push_b(int *a, int *b, int len);
int		swap_a(int *a);
int		swap_b(int *b);
int		rotate_a(int *a, int len);
int		rotate_b(int *b, int len);
int		rrotate_a(int *a, int len);
int		rrotate_b(int *b, int len);

#endif
