/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyg <pyg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:51:37 by pyg               #+#    #+#             */
/*   Updated: 2021/08/05 13:55:27 by pyg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bring_above(t_ps *ps)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (i < ps->len_a)
	{
		if (ps->stack_a[i] < ps->stack_a[index])
			index = i;
		i++;
	}
	while (index > 0)
	{
		print_manip(ps, "ra");
		index--;
	}
	print_manip(ps, "pb");
}

int	get_nbr_chunk(int i)
{
	if (i < 5)
		return (1);
	else if (i < 12)
		return (3);
	else if (i < 99)
		return (5);
	else if (i < 495)
		return (9);
	else
		return (16);
}

int	main(int ac, char **av)
{
	t_ps	ps;
	int		i;

	i = 0;
	init_struct(&ps);
	if (ac < 2)
		return (0);
	if (parsing(&ps, ac, av, 0) < 0)
		return (error_msg(&ps, "ERROR: Parsing failed."));
	ps.chunk = get_nbr_chunk(ps.i);
	if (first_sort(&ps, 1) < 0)
		return (error_msg(&ps, "ERROR: first_sort failed."));
	if (ps.i <= 5)
		small_algo(&ps);
	else
		big_algo(&ps);
	free_ps(&ps);
	return (0);
}
