/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:11:35 by marioga2          #+#    #+#             */
/*   Updated: 2025/03/14 12:44:05 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./import/libft.h"
# include "./import/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

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

t_node	*create_node(int value);
void	init_stacks(t_stacks *stacks, int argc, char **argv);
void	free_stacks(t_stacks *stacks);
int		is_sorted(t_node *stack);

#endif

