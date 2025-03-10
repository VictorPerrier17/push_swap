/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperrier <vperrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:19:16 by vperrier          #+#    #+#             */
/*   Updated: 2024/04/30 17:19:18 by vperrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "push_swap.h"

void	other_cases(t_list *list)
{
	if ((list->first->number > list->first->next->number)
		&& (list->first->number > list->last->number))
	{
		ra(list);
		ft_putstr("ra\n");
	}
	if ((list->first->number < list->last->number)
		&& (list->last->number < list->first->next->number))
	{
		sa(list);
		ra(list);
		ft_putstr("sa\n");
		ft_putstr("ra\n");
	}
	if ((list->first->number > list->last->number)
		&& (list->first->number < list->first->next->number))
	{
		rra(list);
		ft_putstr("rra\n");
	}
}

void	three(t_list *list)
{
	if ((list->first->number > list->first->next->number)
		&& (list->first->number) < list->last->number)
	{
		sa(list);
		ft_putstr("sa\n");
	}
	if ((list->first->next->number < list->first->number)
		&& (list->first->next->number > list->last->number))
	{
		sa(list);
		rra(list);
		ft_putstr("sa\n");
		ft_putstr("rra\n");
	}
	other_cases(list);
}
