/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperrier <vperrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:19:28 by vperrier          #+#    #+#             */
/*   Updated: 2024/04/30 17:20:24 by vperrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "push_swap.h"

void	ft_putchar(char car)
{
	write(1, &car, 1);
}

void	ft_putstr(char *li)
{
	int	co;

	co = 0;
	while (li[co] != '\0')
	{
		ft_putchar(li[co]);
		co++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

void	free_all(t_list *list_a, t_list *list_b,
	t_list *stack_limits, t_stacks *stack_param)
{
	while (list_a->first != NULL)
		suppression(list_a);
	free(list_a);
	while (list_b->first != NULL)
		suppression(list_b);
	free(list_b);
	while (stack_limits->first != NULL)
		suppression(stack_limits);
	free(stack_limits);
	free(stack_param);
}
