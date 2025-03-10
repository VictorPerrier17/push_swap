/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperrier <vperrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:09:50 by vperrier          #+#    #+#             */
/*   Updated: 2024/04/30 17:11:12 by vperrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include "../push_swap.h"

int	check_first(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	if (argc > 2)
		check_space_multichar(argc, argv);
	return (0);
}

int	check_process(int argc, char **argv, int d, char **li)
{
	if (d == 1)
	{
		if (check_error_imput(argc, argv) == 1)
			return (1);
	}
	if (d == 2)
	{
		if (li[1] == NULL)
		{
			free(li[0]);
			free(li);
			return (1);
		}
	}
	return (0);
}

int	check_doublons(t_list *list)
{
	t_element	*actuel;
	t_element	*suivant;

	if (list == NULL || list->first == NULL)
		return (1);
	actuel = list->first;
	while (actuel->next != NULL)
	{
		suivant = actuel->next;
		while (suivant != NULL)
		{
			if (actuel->number == suivant->number)
			{
				ft_putstr("Error\n");
				return (1);
			}
			suivant = suivant->next;
		}
		actuel = actuel->next;
	}
	return (0);
}

int	check_error_imput(int sizelist, char **list)
{
	int	co;

	if (sizelist != 2)
		return (1);
	co = 0;
	if (ft_strlen(list[1]) < 1)
		return (1);
	while (list[1][co] != '\0')
	{
		if ((list[1][co] < 48 || list[1][co] > 57)
			&& (list[1][co] != '-') && (list[1][co] != ' '))
			return (1);
		if (co != 0 && list[1][co] == '-' && list[1][co - 1] != ' ')
			return (1);
		co++;
	}
	co = 0;
	while (list[1][co + 1] != '\0')
	{
		if ((list[1][co] == '-' && list[1][co + 1] == '-')
			|| (list[1][co] == ' ' && list[1][co + 1] == ' '))
			return (1);
		co++;
	}
	return (0);
}

int	check_error_imput2(char *list)
{
	int	co;

	co = 0;
	while (list[co] != '\0')
	{
		if ((list[co] < 48 || list[co] > 57)
			&& (list[co] != '-'))
			return (1);
		if (co != 0 && list[co] == '-' && list[co - 1] != ' ')
			return (1);
		co++;
	}
	return (0);
}
