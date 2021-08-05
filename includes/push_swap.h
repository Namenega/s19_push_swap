/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyg <pyg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:43:07 by pyg               #+#    #+#             */
/*   Updated: 2021/08/05 13:55:42 by pyg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_ps
{
	int		*stack_a;
	int		*stack_b;
	int		i;
	int		len_a;
	int		len_b;
	int		debug;
	int		chunk;
	int		*chunk_val;
	int		max_nb;
	int		size;
	char	*instruct;
	char	**tab_cmd;
}				t_ps;

/*
** PUSH_SWAP_C
*/

int		main(int ac, char **av);
int		get_nbr_chunk(int i);
void	bring_above(t_ps *ps);

/*
** PARSING_C
*/

int		parsing(t_ps *ps, int ac, char **av, int a);
int		parsing_check(t_ps *ps, int ac, char **av);
int		parse_string(t_ps *ps, int ac, char **av, int i);
int		malloc_stack(t_ps *ps, int ac, char **av, int i);

/*
** FIRST_SORT_C
*/

int		first_sort(t_ps *ps, int j);
int		*sort_tab(t_ps *ps, int *tab, int a, int b);
int		save_chunk_value(t_ps *ps, int *tab, int a);

/*
** SMALL_ALGO_C
*/

int		small_algo(t_ps *ps);
int		algo_2(t_ps *ps);
int		algo_3(t_ps *ps);
int		algo_4(t_ps *ps);
int		algo_5(t_ps *ps);

/*
** BIG_ALGO_C
*/

int		big_algo(t_ps *ps);
int		issorted(t_ps *ps);
void	dispatch_chunk(t_ps *ps, int j, int i);
void	send_to_chunk(t_ps *ps, int i, int bool);

/*
** SORT_B_C
*/

int		sort_stack_b(t_ps *ps);
int		ismax(t_ps *ps);
void	push_b(t_ps *ps, int i, int bool);

/*
** PRINT_MANIP_C
*/

void	print_manip(t_ps *ps, char *s);
void	print_manip_next(t_ps *ps, char *s);

/*
** UTILS_0_C
*/

void	free_tab(char **tab);
void	free_ps(t_ps *ps);
int		error_msg(t_ps *ps, char *s);
void	init_struct(t_ps *ps);
int		atoi_ps(const char *s, t_ps *ps);

/*
** UTILS_1_C
*/

int		isnum(int ac, char **av, int i);
void	print_stack(t_ps *ps, char *s);

/*
** TAB_MANIP/PA_PB_C
*/

int		pa(t_ps *ps);
int		pb(t_ps *ps);

/*
** TAB_MANIP/SA_SB_C
*/

int		sa(t_ps *ps);
int		sb(t_ps *ps);

/*
** TAB_MANIP/RA_RB_RRA_RRB_C
*/

int		ra(t_ps *ps);
int		rb(t_ps *ps);
int		rra(t_ps *ps);
int		rrb(t_ps *ps);

#endif