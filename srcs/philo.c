/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:07:10 by dprikhod          #+#    #+#             */
/*   Updated: 2026/05/05 14:07:34 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "philo.h"
#include <pthread.h>


/*
args:
number_of_philosophers
time_to_die
time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/
int	main(int argc, char **argv)
{
	t_philo		data;

	if (argc > 6 || argc < 5)
		return (FAILURE);
	if (phl_init(argc, argv, &data))
		return (FAILURE);
	return (SUCCESS);
}
