/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:32:19 by marioga2          #+#    #+#             */
/*   Updated: 2025/03/21 12:32:19 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack_node **stack)
{
    if (!stack || !*stack || !(*stack)->next)
        return;
    t_stack_node *first = *stack;
    t_stack_node *second = first->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    *stack = second;
}

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

void sort_stack(t_stack_node **stack)
{
    if (!stack || !*stack)
        return;
    bool sorted;
    do
    {
        sorted = true;
        t_stack_node *current = *stack;
        while (current->next)
        {
            if (current->value > current->next->value)
            {
                int temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
                sorted = false;
            }
            current = current->next;
        }
    } while (!sorted);
}
