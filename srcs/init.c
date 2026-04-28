/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:20:16 by dprikhod          #+#    #+#             */
/*   Updated: 2026/04/28 18:39:26 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "philo.h"

t_philo	init_args(int argc, char **argv)
{
	t_philo		*parsed_args;

	parsed_args = malloc(sizeof(t_philo));
	if (!parsed_args)
		return (NULL);
	memset(parsed_args, '0', sizeof(t_philo));
	return parsed_args;
}
