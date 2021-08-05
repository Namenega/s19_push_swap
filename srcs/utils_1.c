/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyg <pyg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:00:04 by pyg               #+#    #+#             */
/*   Updated: 2021/08/05 14:31:49 by pyg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	isnum(int ac, char **av, int i)
{
	int	j;

	ac = 0;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if (j == 0 && av[i][j] == '-')
				j++;
			if (!ft_isdigit(av[i][j]))
			{
				printf("7\n");
				return (-1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	print_stack(t_ps *ps, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = ' ';
	ft_putstr_fd(s, 2);
	ft_putstr_fd("stack a = ", 2);
	while (i < ps->len_a)
	{
		ft_putnbr_fd(ps->stack_a[i], 2);
		ft_putchar_fd(j, 2);
		i++;
	}
	write(2, "\n", 1);
	i = 0;
	ft_putstr_fd("stack b = ", 2);
	while (i < ps->len_b)
	{
		ft_putnbr_fd(ps->stack_b[i], 2);
		ft_putchar_fd(j, 2);
		i++;
	}
	write(2, "\n", 1);
}
