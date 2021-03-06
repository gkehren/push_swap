/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:42:06 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/17 12:22:17 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	memfree(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

int	main(int argc, char *argv[])
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
			return (write(STDERR_FILENO, "Error\n", 6), 0);
		b = (int *)malloc(sizeof(int) * i);
		sort_stack(a, b, i - 1);
	}
	else
	{
		a = (int *)malloc(sizeof(int) * argc - 1);
		b = (int *)malloc(sizeof(int) * argc - 1);
		i = parse_argv(argc, argv, a);
		if (i == -1 || is_valid(a, i - 2) == -1)
			return (free(a), free(b), write(STDERR_FILENO, "Error\n", 6), 0);
		sort_stack(a, b, i - 2);
	}
	return (free(a), free(b), 0);
}
