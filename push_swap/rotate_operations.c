/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:35:55 by marioga2          #+#    #+#             */
/*   Updated: 2025/03/14 12:49:15 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ra(t_stacks *stacks)
{
    t_node	*first;
    t_node	*last;

    if (!stacks->stack_a || !stacks->stack_a->next)
        return ;
    first = stacks->stack_a;
    stacks->stack_a = first->next;
    last = stacks->stack_a;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
    
    ft_printf("ra\n");
}

void	rb(t_stacks *stacks)
{
    t_node	*first;
    t_node	*last;

    if (!stacks->stack_b || !stacks->stack_b->next)
        return ;
    first = stacks->stack_b;
    stacks->stack_b = first->next;
    last = stacks->stack_b;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
    
    ft_printf("rb\n");
}

void	rr(t_stacks *stacks)
{
    t_node	*first;
    t_node	*last;

    if (stacks->stack_a && stacks->stack_a->next)
    {
        first = stacks->stack_a;
        stacks->stack_a = first->next;
        last = stacks->stack_a;
        while (last->next)
            last = last->next;
        last->next = first;
        first->next = NULL;
    }
    if (stacks->stack_b && stacks->stack_b->next)
    {
        first = stacks->stack_b;
        stacks->stack_b = first->next;
        last = stacks->stack_b;
        while (last->next)
            last = last->next;
        last->next = first;
        first->next = NULL;
    }
    ft_printf("rr\n");
}

// Reverse rotate stack a (último elemento al principio)
void	rra(t_stacks *stacks)
{
    t_node	*last;
    t_node	*prev;

    if (!stacks->stack_a || !stacks->stack_a->next)
        return ;
    
    // Encontrar el penúltimo y último elemento
    prev = NULL;
    last = stacks->stack_a;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    
    // Mover el último al principio
    prev->next = NULL;
    last->next = stacks->stack_a;
    stacks->stack_a = last;
    
    ft_printf("rra\n");
}

// Reverse rotate stack b (último elemento al principio)
void	rrb(t_stacks *stacks)
{
    t_node	*last;
    t_node	*prev;

    if (!stacks->stack_b || !stacks->stack_b->next)
        return ;
    
    // Encontrar el penúltimo y último elemento
    prev = NULL;
    last = stacks->stack_b;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    
    // Mover el último al principio
    prev->next = NULL;
    last->next = stacks->stack_b;
    stacks->stack_b = last;
    
    ft_printf("rrb\n");
}

// Reverse rotate ambas pilas
void	rrr(t_stacks *stacks)
{
    t_node	*last;
    t_node	*prev;

    // Reverse rotate stack_a
    if (stacks->stack_a && stacks->stack_a->next)
    {
        prev = NULL;
        last = stacks->stack_a;
        while (last->next)
        {
            prev = last;
            last = last->next;
        }
        prev->next = NULL;
        last->next = stacks->stack_a;
        stacks->stack_a = last;
    }
    
    // Reverse rotate stack_b
    if (stacks->stack_b && stacks->stack_b->next)
    {
        prev = NULL;
        last = stacks->stack_b;
        while (last->next)
        {
            prev = last;
            last = last->next;
        }
        prev->next = NULL;
        last->next = stacks->stack_b;
        stacks->stack_b = last;
    }
    
    ft_printf("rrr\n");
}

