/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_last_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperrier <vperrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:16:54 by vperrier          #+#    #+#             */
/*   Updated: 2024/04/30 17:17:17 by vperrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../push_swap.h"

void	swap_last_first(t_list *list)
{
	t_element	*last;
	t_element	*previous_to_last;

	if (list == NULL || list->first == NULL || list->first->next == NULL)
		return ;
	last = list->last;
	previous_to_last = last->previous;
	previous_to_last->next = NULL;
	last->previous = NULL;
	last->next = list->first;
	list->first->previous = last;
	list->first = last;
	list->last = previous_to_last;
}

void	rra(t_list *list)
{
	swap_last_first(list);
}

void	rrb(t_list *list)
{
	swap_last_first(list);
}

void	rrr(t_list *list_a, t_list *list_b)
{
	rra(list_a);
	rrb(list_b);
}
