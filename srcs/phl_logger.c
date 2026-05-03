/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phl_logger.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 20:39:02 by dprikhod          #+#    #+#             */
/*   Updated: 2026/05/03 20:43:58 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int	phl_logger(t_phl_time begin, t_phl_mutex logger, size_t phil_id, char *event)
{
	while (1)
	{
		pthread_mutex_lock(&logger.mutex);
		printf("%ld %ld %s\n", begin, phil_id + 1, event);
		pthread_mutex_unlock(&logger.mutex);
		usleep(200);
	}
}
