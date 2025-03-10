/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperrier <vperrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:11:07 by vperrier          #+#    #+#             */
/*   Updated: 2024/04/30 17:11:10 by vperrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include "../push_swap.h"

int	nblist(const char *str, char c)
{
	int	co;
	int	co2;

	co2 = 0;
	co = 0;
	while (str[co] != '\0')
	{
		if ((str[co] != c)
			&& ((str[co + 1] == c) || (str[co + 1] == '\0')))
			co2++;
		co++;
	}
	return (co2);
}

char	*minl(const char *str, char c, int co2)
{
	char	*newl;
	int		co;

	co = 0;
	while (str[co + co2] != c && str[co + co2] != '\0')
		co++;
	co++;
	newl = (char *)malloc((co) * sizeof(char));
	if (newl == NULL)
		return (NULL);
	co = 0;
	while (str[co + co2] != c && str[co + co2] != '\0')
	{
		newl[co] = str[co + co2];
		co++;
	}
	newl[co] = '\0';
	return (newl);
}

char	**ft_split(const char *str, char c)
{
	char	**nell;
	int		co;
	int		co2;
	int		size;

	size = nblist(str, c);
	nell = (char **)malloc((size + 1) * sizeof(char *));
	if (nell == NULL)
		return (NULL);
	co2 = 0;
	co = 0;
	while (str[co] != '\0')
	{
		if ((co == 0 || (str[co - 1] == c))
			&& (str[co] != c))
		{
			nell[co2] = minl(str, c, co);
			co2++;
		}
		co++;
	}
	nell[co2] = 0;
	return (nell);
}
