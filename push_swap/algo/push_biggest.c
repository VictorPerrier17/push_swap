/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_biggest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperrier <vperrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:13:13 by vperrier          #+#    #+#             */
/*   Updated: 2024/04/30 17:14:57 by vperrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../push_swap.h"
#include <limits.h>

//dit ou se trouve le nombre dans la liste
int	what_rank(t_list *list, long the_number)
{
	t_element	*actuel;
	int			co;

	co = 0;
	actuel = list->first;
	while (actuel != NULL)
	{
		if (actuel->number == the_number)
			return (co);
		actuel = actuel->next;
		co++;
	}
	return (co);
}

void	push_down_a(t_list *list_a, t_list *list_b, int *elsef, long biggest)
{
	if (*elsef != 1 && (list_a->last->number
			== biggest_list(list_a, biggest + 1)
			&& list_b->first != NULL))
	{
		pa(list_a, list_b);
		ft_putstr("pa\n");
		ra(list_a);
		ft_putstr("ra\n");
		*elsef = 1;
	}
	if (*elsef != 1 && (list_a->last->number
			!= biggest_list(list_a, biggest + 1)
			&& list_a->last->number < list_b->first->number
			&& list_b->first != NULL))
	{
		pa(list_a, list_b);
		ft_putstr("pa\n");
		ra(list_a);
		ft_putstr("ra\n");
		*elsef = 1;
	}
}

void	look_for_b(t_list *list_b, int too_look, int *elsef)
{
	if (*elsef != 1 && (what_rank(list_b, too_look) - (list_b->size / 2) < 0))
	{
		rb(list_b);
		ft_putstr("rb\n");
		*elsef = 1;
	}
	if (*elsef != 1 && (what_rank(list_b, too_look) - (list_b->size / 2) >= 0))
	{
		rrb(list_b);
		ft_putstr("rrb\n");
		*elsef = 1;
	}
}

void	push_biggest_in_a(t_list *list_a,
	t_list *list_b, int too_look, int *elsef)
{
	if (*elsef != 1 && (what_rank(list_b, too_look) == 0
			&& list_b->first != NULL))
	{
		pa(list_a, list_b);
		ft_putstr("pa\n");
		*elsef = 1;
	}
}

void	push_biggest(t_list *list_a, t_list *list_b, long biggest)
{
	long	lastbiggest;
	long	too_look;
	int		elsef;

	lastbiggest = the_real_biggest(list_a)+1;
	while ((list_a->last->number
			!= biggest_list(list_a, biggest + 1) || list_b->first != NULL )
		&& check_sort(list_a, list_a->size + list_b->size) == 1)
	{
		if (where_bigest(list_a, list_b, lastbiggest) == 1)
		{
			rra(list_a);
			ft_putstr("rra\n");
			lastbiggest = list_a->first->number;
		}
		else if (where_bigest(list_a, list_b, lastbiggest) == 2)
		{
			elsef = 0;
			too_look = biggest_list(list_b, lastbiggest);
			push_biggest_in_a(list_a, list_b, too_look, &elsef);
			push_down_a(list_a, list_b, &elsef, biggest);
			look_for_b(list_b, too_look, &elsef);
			lastbiggest = list_a->first->number;
		}
	}
}
