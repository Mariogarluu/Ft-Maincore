/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:14:21 by marioga2          #+#    #+#             */
/*   Updated: 2025/03/14 12:52:25 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
    t_node	*first;
    t_node	*second;

    if (!stacks->stack_a || !stacks->stack_a->next)
        return ;
    first = stacks->stack_a;
    second = stacks->stack_a->next;
    first->next = second->next;
    second->next = first;
    stacks->stack_a = second;
    write(1, "sa\n", 3);
}

void	sb(t_stacks *stacks)
{
    t_node	*first;
    t_node	*second;

    if (!stacks->stack_b || !stacks->stack_b->next)
        return ;
    first = stacks->stack_b;
    second = stacks->stack_b->next;
    first->next = second->next;
    second->next = first;
    stacks->stack_b = second;
    write(1, "sb\n", 3);
}

void	ss(t_stacks *stacks)
{
    t_node	*first;
    t_node	*second;

    if (stacks->stack_a && stacks->stack_a->next)
    {
        first = stacks->stack_a;
        second = stacks->stack_a->next;
        first->next = second->next;
        second->next = first;
        stacks->stack_a = second;
    }
    if (stacks->stack_b && stacks->stack_b->next)
    {
        first = stacks->stack_b;
        second = stacks->stack_b->next;
        first->next = second->next;
        second->next = first;
        stacks->stack_b = second;
    }
    write(1, "ss\n", 3);
}

void	pa(t_stacks *stacks)
{
    t_node	*tmp;

    if (!stacks->stack_b)
        return ;
    tmp = stacks->stack_b;
    stacks->stack_b = stacks->stack_b->next;
    tmp->next = stacks->stack_a;
    stacks->stack_a = tmp;
    write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks)
{
    t_node	*tmp;

    if (!stacks->stack_a)
        return ;
    tmp = stacks->stack_a;
    stacks->stack_a = stacks->stack_a->next;
    tmp->next = stacks->stack_b;
    stacks->stack_b = tmp;
    write(1, "pb\n", 3);
}

