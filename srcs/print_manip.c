/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_manip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyg <pyg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:51:03 by pyg               #+#    #+#             */
/*   Updated: 2021/08/04 14:59:51 by pyg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_manip_next(t_ps *ps, char *s)
{
	if (!ft_strcmp(s, "sa"))
	{
		ft_putstr_fd("sa\n", 1);
		sa(ps);
	}
	if (!ft_strcmp(s, "sb"))
	{
		ft_putstr_fd("sb\n", 1);
		sb(ps);
	}
	if (!ft_strcmp(s, "rra"))
	{
		ft_putstr_fd("rra\n", 1);
		rra(ps);
	}
	if (!ft_strcmp(s, "rrb"))
	{
		ft_putstr_fd("rrb\n", 1);
		rrb(ps);
	}

}

void	print_manip(t_ps *ps, char *s)
{
	if (!ft_strcmp(s, "pa"))
	{
		ft_putstr_fd("pa\n", 1);
		pa(ps);
	}
	if (!ft_strcmp(s, "pb"))
	{
		ft_putstr_fd("pb\n", 1);
		pb(ps);
	}
	if (!ft_strcmp(s, "ra"))
	{
		ft_putstr_fd("ra\n", 1);
		ra(ps);
	}
	if (!ft_strcmp(s, "rb"))
	{
		ft_putstr_fd("rb\n", 1);
		rb(ps);
	}
	print_manip_next(ps, s);
}
