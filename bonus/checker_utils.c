/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:48:12 by gkehren           #+#    #+#             */
/*   Updated: 2022/06/17 10:50:17 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

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

char	*get_prompt(void)
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

int	check_stack(struct s_stack *stack)
{
	int	i;

	i = 0;
	if (stack->len_b > -1)
		return (0);
	while (i < stack->len_a - stack->trigger)
	{
		if (stack->a[i] < stack->a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
