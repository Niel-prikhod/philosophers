/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phl_mutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 00:23:50 by dprikhod          #+#    #+#             */
/*   Updated: 2026/05/11 00:24:15 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

int	phl_mutex_lock(t_phl_mutex mutex)
{
	while (1)
	{
		pthread_mutex_lock(mutex.mutex);
		if (mutex.flag == PHL_MUTEX_FREE)
		{
			mutex.flag = PHL_MUTEX_BUSY;
			pthread_mutex_unlock(mutex.mutex);
			break ;
		}
		else
			pthread_mutex_unlock(mutex.mutex);
		usleep(200);
	}
	return (SUCCESS);
}

int	phl_mutex_unlock(t_phl_mutex mutex)
{
	pthread_mutex_lock(mutex.mutex);
	mutex.flag = PHL_MUTEX_FREE;
	pthread_mutex_unlock(mutex.mutex);
	return (SUCCESS);
}
