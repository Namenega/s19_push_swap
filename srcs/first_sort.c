/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyg <pyg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:10:45 by pyg               #+#    #+#             */
/*   Updated: 2021/08/05 14:53:58 by pyg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	save_chunk_value(t_ps *ps, int *tab, int a)
{
	int	i;
	int	j;
	int	k;

	if (!tab)
		return (-1);
	if (a == 0)
		return (0);
	j = ps->len_a / ps->chunk;
	if (ps->len_a % ps->chunk)
		j++;
	i = 0;
	k = 1;
	ps->chunk_val = malloc(sizeof(int) * ps->chunk);
	if (ps->chunk_val == NULL)
		return (-1);
	while (i < ps->chunk - 1 && j != 0)
	{
		ps->chunk_val[i] = tab[(k * j) - 1];
		i++;
		k++;
	}
	ps->chunk_val[i] = tab[ps->len_a - 1];
	return (1);
}

int	*sort_tab(t_ps *ps, int *tab, int a, int b)
{
	int		i;

	while (b < ps->len_a)
	{
		i = b + 1;
		while (i < ps->len_a)
		{
			if (tab[b] == tab[i])
			{
				free(tab);
				return (NULL);
			}
			if (tab[b] > tab[i])
			{
				a = tab[b];
				tab[b] = tab[i];
				tab[i] = a;
			}
			i++;
		}
		b++;
	}
	return (tab);
}

int	first_sort(t_ps *ps, int j)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * ps->len_a);
	if (!tab)
		return (-1);
	while (i < ps->len_a)
	{
		tab[i] = ps->stack_a[i];
		i++;
	}
	i = 0;
	tab = sort_tab(ps, tab, 0, 0);
	if (save_chunk_value(ps, tab, j) < 0)
	{
		free(tab);
		return (-1);
	}
	free(tab);
	return (0);
}
