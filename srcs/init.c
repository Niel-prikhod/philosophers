/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:20:16 by dprikhod          #+#    #+#             */
/*   Updated: 2026/05/02 14:48:20 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>
#include <sys/time.h>

/*
 * # DESCRIPTION
 *
 * Turn string to unsigned integer, accept only true strings, on invalid
 * charecters returns '0'
 */
static int	ft_atou(char *str)
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

static int	check_args(t_args args)
{
	if (args.number == 0)
		return (1);
	if (args.time_to_die == 0)
		return (1);
	if (args.time_to_eat == 0)
		return (1);
	if (args.time_to_sleep == 0)
		return (1);
	return (0);
}

t_args	init_args(int argc, char **argv)
{
	t_args	parsed_args;

	parsed_args.number = ft_atou(argv[1]);
	parsed_args.time_to_die = ft_atou(argv[2]);
	parsed_args.time_to_eat = ft_atou(argv[3]);
	parsed_args.time_to_sleep = ft_atou(argv[4]);
	if (check_args(parsed_args))
	{
		parsed_args.number = 0;
		return (parsed_args);
	}
	if (argc == 6)
		parsed_args.eat_count = ft_atou(argv[5]);
	return (parsed_args);
}

int	phl_init(int argc, char **argv, t_philo *phl)
{
	struct timeval	tv;

	phl->args = init_args(argc, argv);
	if (!phl->args.number)
		return (FAILURE);
	phl->mmu = NULL;
	// phl_init_thinkers();
	phl->people = mmu_alloc(sizeof(t_thinker), phl->args.number, &phl->mmu);
	if (!phl->people)
		return (FAILURE);
	gettimeofday(&tv, NULL);
	phl->start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (SUCCESS);
}
