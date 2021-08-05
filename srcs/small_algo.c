/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyg <pyg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:30:40 by pyg               #+#    #+#             */
/*   Updated: 2021/08/05 12:42:28 by pyg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	algo_2(t_ps *ps)
{
	if (ps->stack_a[0] > ps->stack_a[1])
	{
		sa(ps);
		write(1, "sa\n", 3);
	}
	return (1);
}

int	algo_3(t_ps *ps)
{
	int	a;
	int	b;

	a = ps->stack_a[0];
	b = ps->stack_a[1];
	if (a < b && b < ps->stack_a[2])
		return (1);
	else if (a > b && b < ps->stack_a[2] && ps->stack_a[2] > a)
		print_manip(ps, "sa");
	else if (a > b && b > ps->stack_a[2] && ps->stack_a[2] < a)
	{
		print_manip(ps, "sa");
		print_manip(ps, "rra");
	}
	else if (a > b && b < ps->stack_a[2] && ps->stack_a[2] < a)
		print_manip(ps, "ra");
	else if (a < b && b > ps->stack_a[2] && ps->stack_a[2] > a)
	{
		print_manip(ps, "sa");
		print_manip(ps, "ra");
	}
	else if (a < b && b > ps->stack_a[2] && ps->stack_a[2] < a)
		print_manip(ps, "rra");
	return (1);
}

int	algo_4(t_ps *ps)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = ps->stack_a[0];
	b = ps->stack_a[1];
	c = ps->stack_a[2];
	d = ps->stack_a[3];
	if (a < b && b < c && c < d)
		return (1);
	print_manip(ps, "pb");
	algo_3(ps);
	print_manip(ps, "pa");
	if (a < b)
	{
		print_manip(ps, "sa");
		print_manip(ps, "pb");
		algo_3(ps);
		print_manip(ps, "pa");
	}
	return (1);
}

int	algo_5(t_ps *ps)
{
	int	a;
	int	b;
	int	c;

	a = ps->stack_a[0];
	b = ps->stack_a[1];
	c = ps->stack_a[2];
	if (a < b && b < c && c < ps->stack_a[3] && ps->stack_a[3] < ps->stack_a[4])
		return (1);
	bring_above(ps);
	bring_above(ps);
	algo_3(ps);
	print_manip(ps, "pa");
	if (a > b)
	{
		print_manip(ps, "sa");
		print_manip(ps, "pb");
		algo_3(ps);
		print_manip(ps, "pa");
	}
	print_manip(ps, "pa");
	if (a > b)
		algo_4(ps);
	return (1);
}

int	small_algo(t_ps *ps)
{
	int	i;

	i = 0;
	if (ps->i == 2)
		algo_2(ps);
	else if (ps->i == 3)
		algo_3(ps);
	else if (ps->i == 4)
		algo_4(ps);
	else if (ps->i == 5)
		algo_5(ps);
	return (0);
}
