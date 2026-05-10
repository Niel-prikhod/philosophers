/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phl_thread_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 11:17:52 by dprikhod          #+#    #+#             */
/*   Updated: 2026/05/11 00:24:58 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "phl_logger.h"
#include "phl_utils.h"
#include "phl_mutex.h"
#include <stdio.h>
#include <unistd.h>

static t_phl_time	take_forks(t_phl_mutex left, t_phl_mutex right,
		t_phl_logger logger, size_t phil_id)
{
	phl_mutex_lock(left);
	phl_logger(logger, phil_id, LOG_FORK);
	phl_mutex_lock(right);
	phl_logger(logger, phil_id, LOG_FORK);
	return (phl_get_timestamp(logger.start_time));
}

static void	phl_update_time_last_eat(t_phl_time timestamp,
		t_time_mutex time_last_eat)
{
	phl_mutex_lock(time_last_eat.phl_mutex);
	time_last_eat.time = timestamp;
	phl_mutex_unlock(time_last_eat.phl_mutex);
}

/*
 */
void	*thinker_routine(void *arg)
{
	t_thinker	phil;
	size_t		phil_id;
	t_phl_time	last_eat;

	phil = *(t_thinker *)arg;
	phil_id = phil.phil_id;
	while (1)
	{
		last_eat = take_forks(phil.left_fork, phil.right_fork, phil.logger,
				phil_id);
		phl_update_time_last_eat(last_eat, phil.time_last_eat);
		usleep(phil.args->time_to_eat);
		last_eat = phl_get_timestamp(phil.logger.start_time);
		phl_update_time_last_eat(last_eat, phil.time_last_eat);
		phl_mutex_unlock(phil.left_fork);
		phl_mutex_unlock(phil.right_fork);
		phl_logger(phil.logger, phil.phil_id, LOG_SLEEP);
		usleep(phil.args->time_to_sleep);
		phl_logger(phil.logger, phil.phil_id, LOG_THINK);
	}
	return (NULL);
}

/*
void	*checker_routine(void *arg)
{
	size_t	i;
	t_philo	*phl;

	phl = (t_philo *)arg;
	i = 0;
	while (1)
	{
		if ((phl_get_timestamp(phl->start_time)
				- phl->people[i].time_last_eat >= phl->args.time_to_die)
			return (phl_die_seq(phl));
		i++;
		if (i == phl->args.number)
			i = 0;
	}
}
*/
