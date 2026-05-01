/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:04:46 by dprikhod          #+#    #+#             */
/*   Updated: 2026/05/01 09:55:26 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define SUCCESS 0
# define FAILURE 1

# include <pthread.h>

typedef struct
{
	unsigned int	number;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	eat_count;
}	t_args;

typedef struct
{
	unsigned int	phil_id;
	pthread_t	tid;
	// void	*(*init_thinker)(void *arg);
}	t_thinker;

#endif
