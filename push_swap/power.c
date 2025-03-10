/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperrier <vperrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:19:00 by vperrier          #+#    #+#             */
/*   Updated: 2024/04/30 17:19:03 by vperrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "push_swap.h"
#include <limits.h>

double	my_exp(double x)
{
	double	result;
	double	term;
	int		i;

	result = 1.0;
	term = 1.0;
	i = 1;
	while (i <= 100)
	{
		term *= x / i;
		result += term;
		i++;
	}
	return (result);
}

double	my_log(double x)
{
	double	result;
	double	term;
	double	termsquared;
	double	numerator;
	int		i;

	if (x <= 0)
		return (-1);
	result = 0.0;
	term = (x - 1) / (x + 1);
	termsquared = term * term;
	numerator = term;
	i = 1;
	while (i <= 10000)
	{
		result += numerator / i;
		numerator *= termsquared;
		i += 2;
	}
	return (2 * result);
}

double	my_pow(double base, double exponent)
{
	return (my_exp(exponent * my_log(base)));
}

double	power(double base, double exponent)
{
	double	resultat;

	resultat = my_pow(base, exponent);
	return (resultat);
}
