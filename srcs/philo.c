/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:07:10 by dprikhod          #+#    #+#             */
/*   Updated: 2026/05/01 10:23:46 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include "philo.h"
#include "init.h"

void	*thinker_routine(void *arg)
{
	char *str = "hello from thread of thinker number";

	printf("%s: %d\n", str, ((t_thinker *)arg)->phil_id);
	return NULL;
}

/*
number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
*/
int main(int argc, char **argv)
{
	t_args	*ph;
	t_thinker	*people;
	int			ret;

	if (argc > 6 || argc < 5)
		return (1);
	(void) argv;
	ph = init_args(argc, argv);
	if (!ph) 
		return (1);
	people = malloc(sizeof(t_thinker) * ph->number);
	if (!people)
		return (free(ph), 1);
	people[0].phil_id = (void *)&people[0] - (void *)people;
	ret = pthread_create(&people[0].tid, NULL, thinker_routine, (void *)&people[0]);
	if (ret)
		return (ret);
	pthread_join(people[0].tid, NULL);
	free(ph);
	free(people);
	return (0);
}
