/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperrier <vperrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:16:28 by vperrier          #+#    #+#             */
/*   Updated: 2024/04/30 17:16:31 by vperrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../push_swap.h"

void	pa(t_list *list_a, t_list *list_b)
{
	t_element	*first_b;

	if (list_a == NULL || list_b == NULL || list_b->first == NULL)
		return ;
	first_b = list_b->first;
	list_b->first = first_b->next;
	if (list_b->first != NULL)
		list_b->first->previous = NULL;
	else
		list_b->last = NULL;
	first_b->next = list_a->first;
	if (list_a->first != NULL)
		list_a->first->previous = first_b;
	list_a->first = first_b;
	if (list_a->last == NULL)
		list_a->last = first_b;
	list_a->size++;
	list_b->size--;
}

void	pb(t_list *list_a, t_list *list_b)
{
	t_element	*first_a;

	if (list_a == NULL || list_b == NULL || list_a->first == NULL)
		return ;
	first_a = list_a->first;
	list_a->first = first_a->next;
	if (list_a->first != NULL)
		list_a->first->previous = NULL;
	else
		list_a->last = NULL;
	first_a->next = list_b->first;
	if (list_b->first != NULL)
		list_b->first->previous = first_a;
	list_b->first = first_a;
	if (list_b->last == NULL)
		list_b->last = first_a;
	list_a->size--;
	list_b->size++;
}
