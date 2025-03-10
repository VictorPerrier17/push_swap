/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperrier <vperrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:19:22 by vperrier          #+#    #+#             */
/*   Updated: 2024/04/30 17:19:24 by vperrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"

t_list	*initialization(void)
{
	t_list	*list;

	list = malloc(sizeof(*list));
	if (list == NULL)
		exit(EXIT_FAILURE);
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	return (list);
}

t_stacks	*init_stacks(void)
{
	t_stacks	*new_stacks;

	new_stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (new_stacks == NULL)
		return (NULL);
	new_stacks->nb_stacks = 0;
	new_stacks->nb_in_stacks = 0;
	return (new_stacks);
}

void	insertion(t_list *list, int new_number)
{
	t_element	*new;

	new = malloc(sizeof(*new));
	if (list == NULL || new == NULL)
		exit(EXIT_FAILURE);
	new->number = new_number;
	new->next = NULL;
	if (list->first == NULL)
	{
		new->previous = NULL;
		list->first = new;
		list->last = new;
		list->size = list->size + 1;
	}
	else
	{
		new->previous = list->last;
		list->last->next = new;
		list->last = new;
		list->size = list->size + 1;
	}
}

void	suppression(t_list *list)
{
	t_element	*to_destroy;

	if (list == NULL)
		exit(EXIT_FAILURE);
	if (list->first != NULL)
	{
		to_destroy = list->last;
		if (list->first == list->last)
		{
			list->first = NULL;
			list->last = NULL;
			list->size = list->size - 1;
		}
		else
		{
			list->last = list->last->previous;
			list->last->next = NULL;
			list->size = list->size - 1;
		}
		free(to_destroy);
	}
}
