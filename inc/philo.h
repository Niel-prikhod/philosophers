/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:04:46 by dprikhod          #+#    #+#             */
/*   Updated: 2026/05/03 20:32:05 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define SUCCESS 0
# define FAILURE 1

# include "mmu.h"
# include "phl_utils.h"
# include <pthread.h>
# include <stdbool.h>

typedef struct s_args
{
	unsigned int	number;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	eat_count;
}					t_args;

typedef struct s_mutex
{
	pthread_mutex_t	mutex;
	bool			flag;
}					t_phl_mutex;

typedef struct s_time_mutex
{
	pthread_mutex_t	mutex;
	t_phl_time		time;
}					t_time_mutex;

typedef struct s_thinker
{
	size_t			phil_id;
	pthread_t		tid;
	t_time_mutex	time_last_eat;
	t_args			*args;
	t_phl_mutex		left_fork;
	t_phl_mutex		right_fork;
	t_phl_mutex		logger;
	t_phl_mutex		sim;
}					t_thinker;

typedef struct s_philo
{
	t_mmu			*mmu;
	t_thinker		*people;
	t_phl_mutex		*forks;
	t_args			args;
	t_phl_mutex		logger;
	t_phl_time		start_time;
	t_phl_mutex		simulation;
}					t_philo;

#endif
