/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deuxetcinq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperrier <vperrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:19:43 by vperrier          #+#    #+#             */
/*   Updated: 2024/04/30 17:19:45 by vperrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "push_swap.h"
#include <limits.h>

long	the_real_smallest(t_list *list)
{
	long		smallest;
	t_element	*actuel;

	if (list == NULL || list->first == NULL)
		return (0);
	actuel = list->first;
	smallest = actuel->number;
	while (actuel != NULL)
	{
		if (actuel->number < smallest)
			smallest = actuel->number;
		actuel = actuel->next;
	}
	return (smallest);
}

void	a_or_b(t_list *list_a, t_list *list_b, long small, long small2)
{
	if ((list_a->first->number == small)
		|| (list_a->first->number == small2))
	{
		pb(list_a, list_b);
		ft_putstr("pb\n");
	}
	else
	{
		ra(list_a);
		ft_putstr("ra\n");
	}
}

void	five(t_list *list_a, t_list *list_b)
{
	long	small;
	long	small2;
	long	co;
	long	sizee;

	small = the_real_smallest(list_a);
	small2 = the_smallest(list_a, the_real_smallest(list_a));
	co = 0;
	sizee = list_a->size;
	while (co < sizee)
	{
		a_or_b(list_a, list_b, small, small2);
		co++;
	}
	three(list_a);
	if (list_b->first->number < list_b->last->number)
	{
		rb(list_b);
		ft_putstr("rb\n");
	}
	pa(list_a, list_b);
	ft_putstr("pa\n");
	pa(list_a, list_b);
	ft_putstr("pa\n");
}

void	two_or_five(t_list *list_a, t_list *list_b)
{
	if (list_a->size == 2)
	{
		if (list_a->first->number > list_a->last->number)
		{
			ra(list_a);
			ft_putstr("ra\n");
		}
		return ;
	}
	if (list_a->size == 5)
		five(list_a, list_b);
}
