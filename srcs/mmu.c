/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:43:26 by dprikhod          #+#    #+#             */
/*   Updated: 2026/05/02 17:15:11 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmu.h"
#include "philo.h"

void	*mmu_alloc(size_t size, size_t count, t_mmu **head)
{
	t_mmu	*node;
	t_mmu	*tmp;
	void	*content;

	tmp = *head;
	node = malloc(sizeof(t_mmu));
	if (!node)
		return (NULL);
	content = malloc(size * count);
	if (!content)
		return (free(node), NULL);
	*head = node;
	node->content = content;
	node->next = tmp;
	return (node->content);
}

int	mmu_clear(t_mmu **head)
{
	t_mmu	*tmp;
	t_mmu	*cur;

	cur = *head;
	while (cur->next)
	{
		tmp = cur->next;
		free(cur->content);
		free(cur);
		cur = tmp;
	}
	free(head);
	return (SUCCESS);
}
