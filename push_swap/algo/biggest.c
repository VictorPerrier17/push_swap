/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperrier <vperrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:13:06 by vperrier          #+#    #+#             */
/*   Updated: 2024/04/30 17:14:18 by vperrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../push_swap.h"
#include <limits.h>

long	the_real_biggest(t_list *list)
{
	t_element	*actuel;
	long		sau;

	actuel = list->first;
	sau = -2147483648;
	while (actuel != NULL)
	{
		if (actuel->number > sau)
			sau = actuel->number;
		actuel = actuel->next;
	}
	if (sau == -2147483648)
		return (-2147483648);
	return (sau);
}

long	biggest_list(t_list *list, long current)
{
	t_element	*actuel;
	long		sau;

	actuel = list->first;
	sau = -2147483648;
	while (actuel != NULL)
	{
		if (actuel->number > sau && actuel->number < current)
			sau = actuel->number;
		actuel = actuel->next;
	}
	if (sau == -2147483648)
		return (-2147483648);
	return (sau);
}

int	where_bigest(t_list *list_a, t_list *list_b, long current)
{
	long	max_a;
	long	max_b;

	max_a = biggest_list(list_a, current);
	max_b = biggest_list(list_b, current);
	if (max_a == -2147483648)
		return (2);
	else if (max_b == -2147483648)
		return (1);
	if (max_a > max_b)
		return (1);
	else if (max_a < max_b)
		return (2);
	else
		return (0);
}

long	the_smallest(t_list *liste, int nombre)
{
	long		smallest;
	t_element	*actuel;

	if (liste == NULL || liste->first == NULL)
		return (-2147483648);
	smallest = 2147483647;
	actuel = liste->first;
	while (actuel != NULL)
	{
		if (actuel->number < smallest && actuel->number > nombre)
			smallest = actuel->number;
		actuel = actuel->next;
	}
	return (smallest);
}
