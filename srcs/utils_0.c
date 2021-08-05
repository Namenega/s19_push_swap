/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyg <pyg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:05:46 by pyg               #+#    #+#             */
/*   Updated: 2021/08/05 15:40:53 by pyg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_ps(t_ps *ps)
{
	free(ps->stack_a);
	free(ps->stack_b);
	free(ps->chunk_val);
	ps->chunk_val = NULL;
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	free_tab(ps->tab_cmd);
}

int	error_msg(t_ps *ps, char *s)
{
	ft_putstr_fd(s, 1);
	free_ps(ps);
	return (-1);
}

void	init_struct(t_ps *ps)
{
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	ps->i = 0;
	ps->len_a = 0;
	ps->len_b = 0;
	ps->debug = 0;
	ps->chunk = 0;
	ps->max_nb = 0;
	ps->size = 0;
	ps->chunk_val = NULL;
	ps->instruct = NULL;
	ps->tab_cmd = NULL;
}

int	atoi_ps(const char *s, t_ps *ps)
{
	int					i;
	int					sign;
	unsigned long int	value;

	i = 0;
	sign = 1;
	value = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (value < 2147483660 && s[i] >= '0' && s[i] <= '9')
	{
		value = ((value * 10) + (s[i] - '0'));
		i++;
	}
	if ((value > 2147483647 && sign == 1) || (value > 2147483648 && sign == -1))
		ps->size++;
	return (value * sign);
}
