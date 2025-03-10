/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_first_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperrier <vperrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:16:46 by vperrier          #+#    #+#             */
/*   Updated: 2024/04/30 17:16:49 by vperrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../push_swap.h"

void	swap_first_two(t_list *list)
{
	int	temp;

	if (list == NULL || list->first == NULL || list->first->next == NULL)
		return ;
	temp = list->first->number;
	list->first->number = list->first->next->number;
	list->first->next->number = temp;
}

void	sa(t_list *list)
{
	swap_first_two(list);
}

void	sb(t_list *list)
{
	swap_first_two(list);
}

void	ss(t_list *list_a, t_list *list_b)
{
	sa(list_a);
	sb(list_b);
}
