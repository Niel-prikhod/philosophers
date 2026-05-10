/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 13:36:19 by dprikhod          #+#    #+#             */
/*   Updated: 2026/05/11 00:26:58 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include "phl_utils.h"

t_phl_time phl_get_timestamp(t_phl_time begin)
{
	struct timeval	tv;
	t_phl_time		current;

	gettimeofday(&tv, NULL);
	current = tv.tv_sec * 1000 + tv.tv_usec / 1000 - begin;
	return	(current);
}
