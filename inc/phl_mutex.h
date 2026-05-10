/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phl_mutex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 00:21:31 by dprikhod          #+#    #+#             */
/*   Updated: 2026/05/11 00:22:19 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHL_MUTEX_H
# define PHL_MUTEX_H

# include "philo.h"

int	phl_mutex_unlock(t_phl_mutex mutex);
int	phl_mutex_lock(t_phl_mutex mutex);

#endif
