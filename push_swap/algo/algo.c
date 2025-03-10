/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperrier <vperrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:12:59 by vperrier          #+#    #+#             */
/*   Updated: 2024/04/30 17:13:01 by vperrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../push_swap.h"
#include <limits.h>

void	the_stacks(t_list *list_a, t_list *stack_limits, t_stacks *stack_param)
{
	int	co;
	int	co2;
	int	last_smallest;

	last_smallest = -2147483648;
	insertion(stack_limits, the_smallest(list_a, -2147483648));
	co = 0;
	co2 = 0;
	while (co < stack_param->nb_stacks)
	{
		co2 = 0;
		while (co2 < stack_param->nb_in_stacks)
		{
			last_smallest = the_smallest(list_a, last_smallest);
			co2++;
		}
		insertion(stack_limits, last_smallest);
		co++;
	}
}

void	stacks_nb(t_list *list_a, t_stacks *stack_param)
{
	stack_param->nb_in_stacks = 0.541089
		* power(list_a->size, 0.672022) - 0.0147653;
	while ((stack_param->nb_stacks * stack_param->nb_in_stacks)
		< list_a->size - stack_param->nb_in_stacks)
	{
		stack_param->nb_stacks++;
	}
}

void	all_in_b(t_list *list_a, t_list *list_b,
	t_list *stack_limits, t_stacks *stack_param)
{
	int	co;
	int	co2;

	co = 1;
	co2 = stack_param->nb_stacks;
	suppression_first(stack_limits);
	while (co < co2)
	{
		a_in_b(list_a, list_b, stack_limits);
		co++;
		co++;
		suppression_first(stack_limits);
		suppression_first(stack_limits);
	}
}

void	sort_a(t_list *list_a, t_list *list_b)
{
	int	co;
	int	number_in_a;

	number_in_a = list_a->size;
	co = 0;
	while (co < number_in_a + 1)
	{
		if (list_a->first->number < list_a->last->number)
		{
			pb(list_a, list_b);
			ft_putstr("pb\n");
		}
		else if (list_a->first->number > list_a->last->number)
		{
			ra(list_a);
			ft_putstr("ra\n");
		}
		co++;
	}
}

void	algo(t_list *list_a, t_list *list_b,
	t_list *stack_limits, t_stacks *stack_param)
{
	stacks_nb(list_a, stack_param);
	the_stacks(list_a, stack_limits, stack_param);
	all_in_b(list_a, list_b, stack_limits, stack_param);
	sort_a(list_a, list_b);
	push_biggest(list_a, list_b, the_real_biggest(list_a));
}
