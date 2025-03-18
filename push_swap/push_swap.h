/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:11:35 by marioga2          #+#    #+#             */
/*   Updated: 2025/03/18 13:19:14 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./import/libft.h"
# include "./import/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>  // Para INT_MIN

typedef struct s_node
{
    int				value;
    struct s_node	*next;
}	t_node;

typedef struct s_stacks
{
    t_node	*stack_a;
    t_node	*stack_b;
}	t_stacks;

// Operaciones de pila
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

// Funciones de utilidad
t_node	*create_node(int value);
void	init_stacks(t_stacks *stacks, int argc, char **argv);
void	free_stacks(t_stacks *stacks);
int		is_sorted(t_node *stack);
int		stack_size(t_node *stack);
int		get_min(t_node *stack);
int		get_max(t_node *stack);

// Algoritmo de costes
int		get_index(t_node *stack, int value);
int		get_target(t_stacks *stacks, int value_a);
int		get_cost(t_stacks *stacks, int value);
int		find_cheapest(t_stacks *stacks);
void	move_a_to_top(t_stacks *stacks, int value);
void	move_b_for_insert(t_stacks *stacks, int value);
void	sort_large(t_stacks *stacks);

#endif

