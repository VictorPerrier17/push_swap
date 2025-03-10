/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_first_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperrier <vperrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:16:38 by vperrier          #+#    #+#             */
/*   Updated: 2024/04/30 17:16:41 by vperrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../push_swap.h"

void	swap_first_last(t_list *list)
{
	t_element	*first;
	t_element	*second;
	t_element	*last;

	if (list == NULL || list->first == NULL || list->first->next == NULL)
		return ;
	first = list->first;
	second = list->first->next;
	last = list->last;
	list->first = second;
	second->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	list->last = first;
}

void	ra(t_list *list)
{
	swap_first_last(list);
}

void	rb(t_list *list)
{
	swap_first_last(list);
}

void	rr(t_list *list_a, t_list *list_b)
{
	ra(list_a);
	rb(list_b);
}
