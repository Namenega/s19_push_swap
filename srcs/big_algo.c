/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyg <pyg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:23:31 by pyg               #+#    #+#             */
/*   Updated: 2021/08/05 11:48:25 by pyg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	send_to_chunk(t_ps *ps, int i, int bool)
{
	if (bool == 0)
	{
		while (i != 0)
		{
			print_manip(ps, "ra");
			i--;
		}
		print_manip(ps, "pb");
	}
	else
	{
		while (i < ps->len_a)
		{
			print_manip(ps, "rra");
			i++;
		}
		print_manip(ps, "pb");
	}
}

void	dispatch_chunk(t_ps *ps, int j, int i)
{
	while (i <= ps->len_a)
	{
		if (j < ps->chunk && ps->stack_a[i] <= ps->chunk_val[j]
			&& ps->stack_a[i] < ps->chunk_val[ps->chunk - 1])
		{
			if (i <= ps->len_a / 2)
				send_to_chunk(ps, i, 0);
			else
				send_to_chunk(ps, i, 1);
			i = -1;
		}
		else if (j + 1 < ps->chunk && ps->stack_a[i] < ps->chunk_val[j + 1]
			&& ps->stack_a[i] < ps->chunk_val[ps->chunk - 1])
		{
			if (i <= ps->len_a / 2)
				send_to_chunk(ps, i, 0);
			else
				send_to_chunk(ps, i, 1);
			print_manip(ps, "rb");
			i = -1;		
		}
		i++;
	}
}

int	issorted(t_ps *ps)
{
	int	i;

	i = 0;
	while (i + 1 < ps->len_a)
	{
		if (ps->stack_a[i] > ps->stack_a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	big_algo(t_ps *ps)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!issorted(ps))
		return (0);
	while (j < ps->chunk)
	{
		dispatch_chunk(ps, j, 0);
		j += 2;
	}
	sort_stack_b(ps);
	return (0);
}
