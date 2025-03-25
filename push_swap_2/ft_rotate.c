/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:55:54 by marioga2          #+#    #+#             */
/*   Updated: 2025/03/25 11:55:54 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack_node **stack)
{
    if (!stack || !*stack || !(*stack)->next)
        return;
    t_stack_node *first = *stack;
    t_stack_node *last = first;
    while (last->next)
        last = last->next;
    *stack = first->next;
    (*stack)->prev = NULL;
    last->next = first;
    first->prev = last;
    first->next = NULL;
}

void reverse_rotate(t_stack_node **stack)
{
    if (!stack || !*stack || !(*stack)->next)
        return;
    t_stack_node *last = *stack;
    while (last->next)
        last = last->next;
    last->prev->next = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    last->prev = NULL;
    *stack = last;
}