/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyg <pyg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:49:14 by pyg               #+#    #+#             */
/*   Updated: 2021/08/05 13:25:08 by pyg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_b(t_ps *ps, int i, int bool)
{
	if (bool == 0)
	{
		while (i != 0)
		{
			print_manip(ps, "rb");
			i--;
		}
		print_manip(ps, "pa");
	}
	else
	{
		while (i < ps->len_b)
		{
			print_manip(ps, "rrb");
			i++;
		}
		print_manip(ps, "pa");
	}
}

int	ismax(t_ps *ps)
{
	int	max_nb;
	int	i;

	max_nb = 0;
	i = 1;
	while (i < ps->len_b)
	{
		if (ps->stack_b[max_nb] < ps->stack_b[i])
			max_nb = i;
		i++;
	}
	return (max_nb);
}

int	sort_stack_b(t_ps *ps)
{
	int	max_nb;
	int	i;

	max_nb = 0;
	i = ps->len_b;
	while (i >= 0)
	{
		max_nb = ismax(ps);
		if (max_nb < (ps->len_b / 2))
			push_b(ps, max_nb, 0);
		else
			push_b(ps, max_nb, 1);
		i--;
	}
	return (0);
}
