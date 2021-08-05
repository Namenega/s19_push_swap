/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyg <pyg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:13:36 by pyg               #+#    #+#             */
/*   Updated: 2021/08/05 15:52:30 by pyg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	malloc_stack(t_ps *ps, int ac, char **av, int i)
{
	ps->stack_a = malloc(sizeof(int) * ps->i);
	ps->stack_b = malloc(sizeof(int) * ps->i);
	if (ps->stack_a == NULL || ps->stack_b == NULL)
		return (-1);
	if (isnum(ac, av, i) < 0)
		return (-1);
	ft_bzero(ps->stack_b, ps->i);
	return (0);
}

int	parse_string(t_ps *ps, int ac, char **av, int i)
{
	char	**tab;

	tab = ft_split(av[i], ' ');
	while (tab[ps->i])
		ps->i++;
	if (malloc_stack(ps, ac, tab, 0) < 0)
	{
		free_tab(tab);
		return (-1);
	}
	i = 0;
	while (i < ps->i)
	{
		ps->stack_a[i] = atoi_ps(tab[i], ps);
		i++;
		ps->len_a++;
	}
	if (ps->size != 0)
		return (-1);
	free_tab(tab);
	return (0);
}

int	parsing(t_ps *ps, int ac, char **av, int a)
{
	int	i;

	i = 1;
	if (i == -1)
		return (-1);
	while (av[i][a])
	{
		if (av[i][a] == ' ')
			return (parse_string(ps, ac, av, i));
		a++;
	}
	ps->i = ac - 1;
	if (malloc_stack(ps, ac, av, i) < 0)
		return (-1);
	a = -1;
	while (++a < ps->i)
	{
		ps->stack_a[a] = atoi_ps(av[i], ps);
		i++;
		ps->len_a++;
	}
	if (ps->size != 0)
		return (-1);
	return (0);
}
