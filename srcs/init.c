/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:20:16 by dprikhod          #+#    #+#             */
/*   Updated: 2026/05/03 20:35:33 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "phl_thread_routine.h"
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

static void	phl_init_mutex(t_philo *phl, t_phl_mutex *forks, size_t number)
{
	size_t	i;

	i = 0;
	while (i < number)
	{
		pthread_mutex_init(&forks[i].mutex, NULL);
		forks[i].flag = 1;
		i++;
	}
	pthread_mutex_init(&phl->simulation.mutex, NULL);
	phl->simulation.flag = 1;
	pthread_mutex_init(&phl->logger.mutex, NULL);
	phl->logger.flag = 1;
}

int	phl_init(int argc, char **argv, t_philo *phl)
{
	struct timeval	tv;

	phl->args = init_args(argc, argv);
	if (!phl->args.number)
		return (FAILURE);
	phl->mmu = NULL;
	phl->people = mmu_alloc(sizeof(t_thinker), phl->args.number, &phl->mmu);
	if (!phl->people)
		return (FAILURE);
	gettimeofday(&tv, NULL);
	phl->forks = mmu_alloc(sizeof(pthread_mutex_t), phl->args.number,
			&phl->mmu);
	phl_init_mutex(phl, phl->forks, phl->args.number);
	if (!phl->forks)
		return (FAILURE);
	phl->start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (SUCCESS);
}

int	phl_init_threads(t_philo *phl)
{
	size_t		i;
	int			err_code;
	t_thinker	*thinker;

	i = 0;
	while (i < phl->args.number)
	{
		thinker = &phl->people[i];
		thinker->phil_id = i;
		thinker->left_fork = phl->forks[i - 1];
		if (i == 0)
			thinker->right_fork = phl->forks[phl->args.number - 1];
		else
			thinker->right_fork = phl->forks[i];
		thinker->args = &phl->args;
		thinker->logger = phl->logger;
		thinker->sim = phl->simulation;
		pthread_mutex_init(&thinker->time_last_eat.mutex, NULL);
		thinker->time_last_eat.time = phl->start_time;
		err_code = pthread_create(&phl->people[i].tid, NULL, thinker_routine,
				&phl->people[i]);
		if (err_code)
			return (err_code);
		pthread_detach(phl->people[i].tid);
		i++;
	}
	return (SUCCESS);
}
