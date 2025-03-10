/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_in_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperrier <vperrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:12:49 by vperrier          #+#    #+#             */
/*   Updated: 2024/04/30 17:12:52 by vperrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../push_swap.h"
#include <limits.h>

int	push_in_b(t_list *list_a, t_list *list_b, int sep1, int sep2)
{
	int	re;

	re = 0;
	if (list_a->first->number < sep2)
	{
		if (list_a->first->number < sep1)
		{
			pb(list_a, list_b);
			ft_putstr("pb\n");
			rb(list_b);
			ft_putstr("rb\n");
		}
		else
		{
			pb(list_a, list_b);
			ft_putstr("pb\n");
		}
		re = 1;
	}
	return (re);
}

void	a_in_b(t_list *list_a, t_list *list_b, t_list *stack_limits)
{
	int	sep1;
	int	sep2;
	int	sizeini;
	int	co;

	if (stack_limits->first == NULL || stack_limits->first->next == NULL)
		return ;
	sep1 = stack_limits->first->number;
	sep2 = stack_limits->first->next->number;
	sizeini = list_a->size;
	co = 0;
	while (co < sizeini)
	{
		if (push_in_b(list_a, list_b, sep1, sep2) == 0)
		{
			ra(list_a);
			ft_putstr("ra\n");
		}
		co++;
	}
}
