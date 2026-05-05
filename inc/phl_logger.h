/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phl_logger.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:56:00 by dprikhod          #+#    #+#             */
/*   Updated: 2026/05/05 15:58:09 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHL_LOGGER_H
# define PHL_LOGGER_H

# include "philo.h"

# define LOG_EAT "is eating"
# define LOG_SLEEP "is sleeping"
# define LOG_FORK "has taken a fork"
# define LOG_DIE "died"

int	phl_logger(t_phl_time begin, t_phl_mutex logger, size_t phil_id, char *event);

#endif
