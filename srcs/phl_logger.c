/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phl_logger.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 20:39:02 by dprikhod          #+#    #+#             */
/*   Updated: 2026/05/05 16:02:45 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int	phl_logger(t_phl_time begin, t_phl_mutex logger, size_t phil_id,
		char *event)
{
	t_phl_time	timestamp;

	while (1)
	{
		pthread_mutex_lock(&logger.mutex);
		if (logger.flag == PHL_MUTEX_FREE)
		{
			logger.flag = PHL_MUTEX_BUSY;
			pthread_mutex_unlock(&logger.mutex);
			timestamp = phl_get_timestamp(begin);
			printf("%ld %ld %s\n", timestamp - begin, phil_id + 1, event);
			pthread_mutex_lock(&logger.mutex);
			logger.flag = PHL_MUTEX_FREE;
			pthread_mutex_unlock(&logger.mutex);
			break ;
		}
		else
			pthread_mutex_unlock(&logger.mutex);
		usleep(200);
	}
	return (SUCCESS);
}
