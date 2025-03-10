/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperrier <vperrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:10:13 by vperrier          #+#    #+#             */
/*   Updated: 2024/04/30 17:11:11 by vperrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include "../push_swap.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		sig;
	long	result;

	i = 0;
	sig = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig *= -1;
		i++;
	}
	if ((str[i + 1] == '-') || (str[i] == '+'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (result * sig);
}

int	process_input_2argv(int argc, char **argv, t_list *list_a)
{
	int		co;
	char	**li;

	co = 0;
	if (argc == 2)
	{
		if (check_process(argc, argv, 1, NULL) == 1)
			return (1);
		li = ft_split(argv[1], ' ');
		if (check_process(argc, argv, 2, li))
			return (2);
		co = 0;
		while (li[co] != NULL)
		{
			if (ft_atoi(li[co]) > 2147483647
				|| ft_atoi(li[co]) < -2147483648)
				return (1);
			insertion(list_a, ft_atoi(li[co]));
			free(li[co]);
			co++;
		}
		free(li);
	}
	return (0);
}

int	process_input(int argc, char **argv, t_list *list_a)
{
	int		co;

	co = 0;
	if (process_input_2argv(argc, argv, list_a) == 1)
		return (1);
	if (argc > 2)
	{
		while (co < argc - 1)
		{
			if (check_error_imput2(argv[co + 1]) == 1)
			{
				return (1);
			}
			if (ft_atoi(argv[co + 1]) > 2147483647
				|| ft_atoi(argv[co + 1]) < -2147483648)
				return (1);
			insertion (list_a, ft_atoi(argv[co + 1]));
			co++;
		}
	}
	return (0);
}

void	which_algo(t_list *list_a, t_list *list_b,
		t_list *stack_limits, t_stacks *stack_param)
{
	if (list_a->size == 3)
		three(list_a);
	if (list_a->size == 5 || list_a->size == 2)
		two_or_five(list_a, list_b);
	if (list_a->size > 5 || list_a->size == 4)
		algo(list_a, list_b, stack_limits, stack_param);
}

int	main(int argc, char **argv)
{
	t_list		*list_a;
	t_list		*list_b;
	t_list		*stack_limits;
	t_stacks	*stack_param;

	if (check_first(argc, argv) == 1 || (argc == 2
			&& check_space(argv[1]) == 1))
		return (0);
	list_a = initialization();
	list_b = initialization();
	stack_limits = initialization();
	stack_param = init_stacks();
	if (stack_param == NULL || stack_limits == NULL
		|| list_b == NULL || list_a == NULL
		|| process_input(argc, argv, list_a) == 1)
	{
		printf("Error\n");
		free_all(list_a, list_b, stack_limits, stack_param);
		return (0);
	}
	if (check_doublons(list_a) == 0
		&& check_sort(list_a, list_a->size - 1) == 1)
		which_algo(list_a, list_b, stack_limits, stack_param);
	free_all(list_a, list_b, stack_limits, stack_param);
	return (0);
}
