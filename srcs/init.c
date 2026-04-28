/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:20:16 by dprikhod          #+#    #+#             */
/*   Updated: 2026/04/28 20:04:18 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*
* # DESCRIPTION
*
* Turn string to unsigned integer, accept only true strings, on invalid 
* charecters returns '0'
*/
int	ft_atou(char *str)
{
	long	res;

	if (!str)
		return (0);
	res = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		res = 10 * res + (*str - '0') % 10;
		if (res > INT_MAX)
			return (0);
		str++;
	}
	return (res);
}

t_philo	*init_args(int argc, char **argv)
{
	t_philo	*parsed_args;

	parsed_args = malloc(sizeof(t_philo));
	if (!parsed_args)
		return (NULL);
	memset(parsed_args, '0', sizeof(t_philo));
	parsed_args->number = ft_atou(argv[1]);
	parsed_args->time_to_die = ft_atou(argv[2]);
	parsed_args->time_to_eat = ft_atou(argv[3]);
	parsed_args->time_to_sleep = ft_atou(argv[4]);
	if (argc == 6)
		parsed_args->eat_count = ft_atou(argv[5]);
	return (parsed_args);
}
