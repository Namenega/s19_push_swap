/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyg <pyg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:59:36 by pyg               #+#    #+#             */
/*   Updated: 2021/08/05 12:09:02 by pyg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ss(t_ps *ps)
{
	sa(ps);
	sb(ps);
	return (0);
}

int	sa(t_ps *ps)
{
	int	tmp;

	if (ps->len_a < 2)
		return (0);
	tmp = ps->stack_a[0];
	ps->stack_a[0] = ps->stack_a[1];
	ps->stack_a[1] = tmp;
	if (ps->debug == 1)
		print_stack(ps, "sa debugging\n");
	return (0);

}

int	sb(t_ps *ps)
{
	int	tmp;

	if (ps->len_b < 2)
		return (0);
	tmp = ps->stack_b[0];
	ps->stack_b[0] = ps->stack_b[1];
	ps->stack_b[1] = tmp;
	if (ps->debug == 1)
		print_stack(ps, "sb debugging\n");
	return (0);
}
