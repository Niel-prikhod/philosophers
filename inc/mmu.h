/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmu.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:44:59 by dprikhod          #+#    #+#             */
/*   Updated: 2026/05/02 09:27:18 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MMU_H
# define MMU_H

# include <stdlib.h>

typedef struct s_mmu
{
	struct s_mmu	*next;
	void			*content;
}	t_mmu;

t_mmu	*mmu_init(void);
void	*mmu_alloc(size_t size, size_t count, t_mmu **head);
int		mmu_free(t_mmu **head);

#endif
