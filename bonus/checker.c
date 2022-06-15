/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:54:38 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/15 15:39:39 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*get_prompt()
{
	char	*inst;
	char	*buf;
	int		bytes;

	bytes = 1;
	inst = (char *)malloc(sizeof(char) * 1);
	inst[0] = '\0';
	buf = (char *)malloc(sizeof(char) * 3);
	if (!buf)
		return (0);
	while (bytes != 0)
	{
		bytes = read(0, buf, 2);
		if (bytes == -1)
		{
			free(buf);
			return (0);
		}
		buf[bytes] = '\0';
		inst = ft_strjoin(inst, buf);
	}
	return (free(buf), inst);
}

int	is_equal(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_stack(int *a, int len_a, int len_b)
{
	int	i;

	i = 0;
	if (len_b > -1)
		return (0);
	while (i < len_a)
	{
		if (a[i] < a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
//#include <stdio.h>
//int	print_stack(int *a, int *b, int len)
//{
//	int	i;

//	i = 0;
//	while (i <= len)
//	{
//		printf("%d | %d\n", a[i], b[i]);
//		i++;
//	}
//	printf("\n");
//	return (0);
//}
int	valid_sort(int *a, int *b, int len, char **inst)
{
	int	len_a;
	int	len_b;
	int	i;

	i = 0;
	len_a = len;
	len_b = -1;
	while (inst[i])
	{
		if (is_equal(inst[i], "sa") == 1)
			swap_a(a);
		else if (is_equal(inst[i], "sb") == 1)
			swap_b(b);
		else if (is_equal(inst[i], "ss") == 1)
		{
			swap_a(a);
			swap_b(b);
		}
		else if (is_equal(inst[i], "pa") == 1)
		{
			len_a += push_a(a, b, len_a + 1, len_b);
			len_b--;
		}
		else if (is_equal(inst[i], "pb") == 1)
		{
			len_b += push_b(a, b, len_a, len_b + 1);
			len_a--;
		}
		else if (is_equal(inst[i], "ra") == 1)
			rotate_a(a, len_a);
		else if (is_equal(inst[i], "rb") == 1)
			rotate_b(b, len_b);
		else if (is_equal(inst[i], "rr") == 1)
		{
			rotate_a(a, len_a);
			rotate_b(b, len_b);
		}
		else if (is_equal(inst[i], "rra") == 1)
			rrotate_a(a, len_a);
		else if (is_equal(inst[i], "rrb") == 1)
			rrotate_b(b, len_b);
		else if (is_equal(inst[i], "rrr") == 1)
		{
			rrotate_a(a, len_a);
			rrotate_b(b, len_b);
		}
		i++;
	}
	if (check_stack(a, len_a, len_b) == 1)
		return (1);
	else
		return (0);
}

int	checker(int *a, int *b, int len)
{
	char	**instructions;
	char	*tmp;
	int	i;

	i = 0;
	tmp = get_prompt();
	instructions = ft_split(tmp, '\n');
	if (valid_sort(a, b, len, instructions) == 1)
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
