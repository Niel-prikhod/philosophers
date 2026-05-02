/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:55:12 by dprikhod          #+#    #+#             */
/*   Updated: 2026/05/02 11:09:45 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "philo.h"

t_args	init_args(int argc, char **argv);
int		phl_init(int argc, char **argv, t_philo *phl);

#endif
