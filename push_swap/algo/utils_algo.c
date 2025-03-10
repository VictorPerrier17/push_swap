/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperrier <vperrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:13:20 by vperrier          #+#    #+#             */
/*   Updated: 2024/04/30 17:13:43 by vperrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../push_swap.h"
#include <limits.h>

//suprime le premier element d une liste
void	suppression_first(t_list *list)
{
	t_element	*to_destroy;

	if (list == NULL)
		exit(EXIT_FAILURE);
	if (list->first != NULL)
	{
		to_destroy = list->first;
		if (list->first == list->last)
		{
			list->first = NULL;
			list->last = NULL;
		}
		else
		{
			list->first = list->first->next;
			list->first->previous = NULL;
		}
		list->size--;
		free(to_destroy);
	}
}

int	check_sort(t_list *list, int size)
{
	t_element	*actuel;
	int			co;

	co = 0;
	actuel = list->first;
	while (actuel->next != NULL)
	{
		if (actuel->next->number < actuel->number)
			return (1);
		actuel = actuel->next;
		co++;
	}
	if (co == size)
		return (0);
	return (1);
}
