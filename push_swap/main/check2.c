/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperrier <vperrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:54:27 by vperrier          #+#    #+#             */
/*   Updated: 2024/05/07 12:54:28 by vperrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include "../push_swap.h"

int	check_space(char *list)
{
	size_t	co;

	co = 0;
	if (ft_strlen(list) == 0)
	{
		printf("Error\n");
		exit(0);
		return (1);
	}
	while (list[co] != '\0')
	{
		if (list[co] >= '0' && list[co] <= '9')
			return (0);
		co++;
	}
	if (co == ft_strlen(list))
	{
		printf("Error\n");
		exit(0);
	}
	return (1);
}

void	check_space_multichar(int argc, char **list)
{
	int	co;

	co = 1;
	while (argc > co)
	{
		check_space(list[co]);
		co++;
	}
}
