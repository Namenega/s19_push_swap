/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyg <pyg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:09:13 by pyg               #+#    #+#             */
/*   Updated: 2021/08/05 12:15:24 by pyg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	pa(t_ps *ps)
{
	int	i;

	i = ps->len_a;
	if (ps->len_b < 1)
		return (0);
	while (i > 0)
	{
		ps->stack_a[i] = ps->stack_a[i - 1];
		i--;
	}
	ps->stack_a[0] = ps->stack_b[0];
	ps->len_a++;
	ps->len_b--;
	i = 0;
	while (i < ps->len_b)
	{
		ps->stack_b[i] = ps->stack_b[i + 1];
		i++;
	}
	if (ps->debug == 1)
		print_stack(ps, "pa debugging\n");
	return (0);
}

int	pb(t_ps *ps)
{
	int	i;

	i = ps->len_b;
	if (ps->len_a < 1)
		return (0);
	while (i > 0)
	{
		ps->stack_b[i] = ps->stack_b[i - 1];
		i--;
	}
	ps->stack_b[0] = ps->stack_a[0];
	ps->len_b++;
	ps->len_a--;
	i = 0;
	while (i < ps->len_a)
	{
		ps->stack_a[i] = ps->stack_a[i + 1];
		i++;
	}
	if (ps->debug == 1)
		print_stack(ps, "pb debugging\n");
	return (0);
}
