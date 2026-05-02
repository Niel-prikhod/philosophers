/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phl_thread_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 11:17:52 by dprikhod          #+#    #+#             */
/*   Updated: 2026/05/02 17:43:04 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philo.h"
#include "phl_utils.h"

void	*thinker_routine(void *arg)
{
	char	*str;
	t_philo	*phl;

	phl = (t_philo *)arg;
	while (1)
	{
		take_forks();
		usleep(phl->args.time_to_eat);
		phl_log_str("sleeping");
		usleep(phl->args.time_to_sleep);
		phl_log_str("thinking");
	}
	return (NULL);
}

void	*checker_routine(void *arg)
{
	size_t	i;
	t_philo	*phl;

	phl = (t_philo *)arg;
	i = 0;
	while (1)
	{
		if ((phl_get_timestamp(phl->start_time) - phl->people[i].time_last_eat >= phl->args.time_to_die)
			return (phl_die_seq(phl));
		i++;
		if (i == phl->args.number)
			i = 0;
	}
}
