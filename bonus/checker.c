/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:54:38 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/16 13:47:40 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	checker(int *a, int *b, int len)
{
	struct s_stack	stack;
	char			**instructions;
	char			*tmp;
	int				i;

	i = 0;
	tmp = get_prompt();
	instructions = ft_split(tmp, '\n');
	stack.a = a;
	stack.b = b;
	stack.len_a = len;
	stack.len_b = -1;
	if (valid_sort(&stack, instructions) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	while (instructions[i])
		free(instructions[i++]);
	return (free(tmp), free(instructions), 0);
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	i;

	i = 1;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		i = parse_str(argv[1], &a);
		if (i == -1 || is_valid(a, i - 1) == -1)
			return (free(a), write(STDERR_FILENO, "Error\n", 6), 0);
		b = (int *)malloc(sizeof(int) * i);
		checker(a, b, i - 1);
	}
	else
	{
		a = (int *)malloc(sizeof(int) * argc - 1);
		b = (int *)malloc(sizeof(int) * argc - 1);
		i = parse_argv(argc, argv, a);
		if (i == -1 || is_valid(a, i - 2) == -1)
			return (free(a), free(b), write(STDERR_FILENO, "Error\n", 6), 0);
		checker(a, b, i - 2);
	}
	return (free(a), free(b), 0);
}
