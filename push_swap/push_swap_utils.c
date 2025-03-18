/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:11:43 by marioga2          #+#    #+#             */
/*   Updated: 2025/03/14 12:42:49 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Create a new node with the given value
t_node	*create_node(int value)
{
    t_node	*node;
    
    node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->value = value;
    node->next = NULL;
    return (node);
}

void	init_stacks(t_stacks *stacks, int argc, char **argv)
{
    int		i;
    t_node	*new_node;
    t_node	*last;

    stacks->stack_a = NULL;
    stacks->stack_b = NULL;
    i = 1;
    while (i < argc)
    {
        new_node = create_node(ft_atoi(argv[i]));
        if (!new_node)
        {
            free_stacks(stacks);
            exit(1);
        }
        if (!stacks->stack_a)
            stacks->stack_a = new_node;
        else
        {
            last = stacks->stack_a;
            while (last->next)
                last = last->next;
            last->next = new_node;
        }
        i++;
    }
}

void	free_stacks(t_stacks *stacks)
{
    t_node	*current;
    t_node	*next;
    current = stacks->stack_a;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    current = stacks->stack_b;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    
    stacks->stack_a = NULL;
    stacks->stack_b = NULL;
}
int	is_sorted(t_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

