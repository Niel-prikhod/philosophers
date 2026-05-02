/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:04:46 by dprikhod          #+#    #+#             */
/*   Updated: 2026/05/02 17:43:56 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define SUCCESS 0
# define FAILURE 1

# include "mmu.h"
# include <pthread.h>
# include "phl_utils.h"

typedef struct s_args
{
	unsigned int	number;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	eat_count;
}					t_args;

typedef struct s_thinker
{
	unsigned int	phil_id;
	pthread_t		tid;
	t_phl_time		time_last_eat;
}					t_thinker;

typedef struct s_philo
{
	t_args			args;
	t_thinker		*people;
	t_mmu			*mmu;
	t_phl_time		start_time;
}					t_philo;

#endif
