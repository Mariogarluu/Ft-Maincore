/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:11:41 by marioga2          #+#    #+#             */
/*   Updated: 2025/03/14 13:11:39 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stacks *stacks)
{
    int		first;
    int		second;
    int		third;
    t_node	*stack;

    stack = stacks->stack_a;
    if (!stack || !stack->next || !stack->next->next)
        return ;
    first = stack->value;
    second = stack->next->value;
    third = stack->next->next->value;

    if (first > second && second < third && first < third)
        sa(stacks);
    else if (first > second && second > third)
    {
        sa(stacks);
        rra(stacks);
    }
    else if (first > second && second < third && first > third)
        ra(stacks);
    else if (first < second && second > third && first < third)
    {
        sa(stacks);
        ra(stacks);
    }
    else if (first < second && second > third && first > third)
        rra(stacks);
}

static int	find_min_position(t_node *stack)
{
    int		min;
    int		pos;
    int		min_pos;
    t_node	*current;

    if (!stack)
        return (-1);
    min = stack->value;
    min_pos = 0;
    pos = 0;
    current = stack;
    while (current)
    {
        if (current->value < min)
        {
            min = current->value;
            min_pos = pos;
        }
        pos++;
        current = current->next;
    }
    return (min_pos);
}

static void	sort_four_or_five(t_stacks *stacks, int size)
{
    int	pos;
    int	i;

    // Push the smallest elements to stack B
    i = 0;
    while (i < size - 3 && i < 2)
    {
        pos = find_min_position(stacks->stack_a);
        // Rotate until the smallest element is on top
        if (pos <= size / 2)
        {
            while (pos-- > 0)
                ra(stacks);
        }
        else
        {
            while (pos++ < size)
                rra(stacks);
        }
        // Push it to stack B
        pb(stacks);
        size--;
        i++;
    }
    
    // Sort the remaining three elements
    sort_three(stacks);
    
    // Push the elements back from stack B
    while (i-- > 0)
        pa(stacks);
}

static void	sort_small(t_stacks *stacks, int size)
{
    if (size <= 1)
        return ;
    else if (size == 2)
    {
        if (stacks->stack_a->value > stacks->stack_a->next->value)
            sa(stacks);
    }
    else if (size == 3)
        sort_three(stacks);
    else if (size <= 5)
        sort_four_or_five(stacks, size);
}

static void	quicksort(t_stacks *stacks, int size)
{
    if (size <= 5)
    {
        sort_small(stacks, size);
        return;
    }

    int pivot = stacks->stack_a->value;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (stacks->stack_a->value < pivot)
        {
            pb(stacks);
            count++;
        }
        else
            ra(stacks);
    }

    quicksort(stacks, size - count);
    while (count--)
        pa(stacks);
}

int	main(int argc, char **argv)
{
    t_stacks	stacks;
    int         stack_size;
    t_node      *temp;

    if (argc < 2)
        return (0);
    init_stacks(&stacks, argc, argv);
    if (is_sorted(stacks.stack_a))
    {
        free_stacks(&stacks);
        return (0);
    }
    
    stack_size = 0;
    temp = stacks.stack_a;
    while (temp)
    {
        stack_size++;
        temp = temp->next;
    }
    
    quicksort(&stacks, stack_size);
    
    free_stacks(&stacks);
    return (0);
}
