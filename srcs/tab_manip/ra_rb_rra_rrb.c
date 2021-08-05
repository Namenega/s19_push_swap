/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rra_rrb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyg <pyg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:16:40 by pyg               #+#    #+#             */
/*   Updated: 2021/08/05 12:32:44 by pyg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rr_rrr(t_ps *ps, int bool)
{
	if (bool == 0)
	{
		ra(ps);
		rb(ps);
		return (0);
	}
	else if (bool == 1)
	{
		rra(ps);
		rrb(ps);
		return (0);
	}
	return (0);
}

int	ra(t_ps *ps)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = ps->stack_a[i];
	if (ps->len_a < 2)
		return (0);
	while (i + 1 < ps->len_a)
	{
		ps->stack_a[i] = ps->stack_a[i + 1];
		i++;
	}
	ps->stack_a[i] = tmp;
	if (ps->debug == 1)
		print_stack(ps, "ra debugging\n");
	return (0);
}

int	rb(t_ps *ps)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = ps->stack_b[i];
	if (ps->len_b < 2)
		return (0);
	while (i + 1 < ps->len_b)
	{
		ps->stack_b[i] = ps->stack_b[i + 1];
		i++;
	}
	ps->stack_b[i] = tmp;
	if (ps->debug == 1)
		print_stack(ps, "rb debugging\n");
	return (0);
}

int	rra(t_ps *ps)
{
	int	i;
	int	tmp;

	if (ps->len_a < 2)
		return (0);
	i = ps->len_a - 1;
	tmp = ps->stack_a[i];
	while (i > 0)
	{
		ps->stack_a[i] = ps->stack_a[i - 1];
		i--;
	}
	ps->stack_a[0] = tmp;
	if (ps->debug == 1)
		print_stack(ps, "rra debugging\n");
	return (0);
}

int	rrb(t_ps *ps)
{
	int	i;
	int	tmp;

	if (ps->len_b < 2)
		return (0);
	i = ps->len_b - 1;
	tmp = ps->stack_b[i];
	while (i > 0)
	{
		ps->stack_b[i] = ps->stack_b[i - 1];
		i--;
	}
	ps->stack_b[0] = tmp;
	if (ps->debug == 1)
		print_stack(ps, "rrb debugging\n");
	return (0);
}
