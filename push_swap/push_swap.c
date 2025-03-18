/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:11:41 by marioga2          #+#    #+#             */
/*   Updated: 2025/03/18 13:29:24 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stacks *stacks)
{
    int	a;
    int	b;
    int	c;

    if (!stacks->stack_a || !stacks->stack_a->next || !stacks->stack_a->next->next)
        return ;
    a = stacks->stack_a->value;
    b = stacks->stack_a->next->value;
    c = stacks->stack_a->next->next->value;
    if (a > b && b < c && a < c)
        sa(stacks);
    else if (a > b && b > c)
    {
        sa(stacks);
        rra(stacks);
    }
    else if (a > b && b < c && a > c)
        ra(stacks);
    else if (a < b && b > c && a < c)
    {
        sa(stacks);
        ra(stacks);
    }
    else if (a < b && b > c && a > c)
        rra(stacks);
}

int	stack_size(t_node *stack)
{
    int	size;

    size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}

int	get_max(t_node *stack)
{
    int	max;

    if (!stack)
        return (0);
    max = stack->value;
    while (stack)
    {
        if (stack->value > max)
            max = stack->value;
        stack = stack->next;
    }
    return (max);
}

int	get_min(t_node *stack)
{
    int	min;

    if (!stack)
        return (0);
    min = stack->value;
    while (stack)
    {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return (min);
}

int	get_position(t_node *stack, int value)
{
    int	pos;

    pos = 0;
    while (stack)
    {
        if (stack->value == value)
            return (pos);
        pos++;
        stack = stack->next;
    }
    return (-1);
}

int	find_target_pos(int value, t_node *stack)
{
    t_node	*current;
    int		target_pos;
    int		best_match;

    if (!stack)
        return (0);
    current = stack;
    target_pos = 0;
    best_match = INT_MAX;

    while (current)
    {
        if (current->value > value && current->value < best_match)
        {
            best_match = current->value;
            target_pos = get_position(stack, current->value);
        }
        current = current->next;
    }

    if (best_match == INT_MAX)
    {
        // Si no encontró un número mayor, usar posición después del mínimo
        int min = get_min(stack);
        target_pos = get_position(stack, min);
    }

    return (target_pos);
}

void	move_top_a(t_stacks *stacks, int pos, int size)
{
    if (pos <= size / 2)
    {
        while (pos > 0)
        {
            ra(stacks);
            pos--;
        }
    }
    else
    {
        while (pos < size)
        {
            rra(stacks);
            pos++;
        }
    }
}

void	move_top_b(t_stacks *stacks, int pos, int size)
{
    if (pos <= size / 2)
    {
        while (pos > 0)
        {
            rb(stacks);
            pos--;
        }
    }
    else
    {
        while (pos < size)
        {
            rrb(stacks);
            pos++;
        }
    }
}

typedef struct s_cost
{
    int	a;
    int	b;
    int	total;
}		t_cost;

t_cost	calculate_cost(t_stacks *stacks, int pos_a, int pos_b)
{
    t_cost	cost;
    int		size_a;
    int		size_b;

    size_a = stack_size(stacks->stack_a);
    size_b = stack_size(stacks->stack_b);
    if (pos_a > size_a / 2)
        cost.a = size_a - pos_a;
    else
        cost.a = pos_a;
    if (pos_b > size_b / 2)
        cost.b = size_b - pos_b;
    else
        cost.b = pos_b;
    cost.total = cost.a + cost.b;
    return (cost);
}

void	find_cheapest_and_move(t_stacks *stacks)
{
    t_node	*current_a;
    int		pos_a;
    int		pos_b;
    int		size_a;
    int		size_b;
    t_cost	best_cost;
    t_cost	current_cost;
    int		best_pos_a;
    int		best_pos_b;

    current_a = stacks->stack_a;
    pos_a = 0;
    best_cost.total = INT_MAX;
    size_a = stack_size(stacks->stack_a);
    size_b = stack_size(stacks->stack_b);

    while (current_a)
    {
        pos_b = find_target_pos(current_a->value, stacks->stack_b);
        current_cost = calculate_cost(stacks, pos_a, pos_b);
        
        if (current_cost.total < best_cost.total)
        {
            best_cost = current_cost;
            best_pos_a = pos_a;
            best_pos_b = pos_b;
        }
        current_a = current_a->next;
        pos_a++;
    }

    // Mover ambos stacks a la posición correcta
    move_top_a(stacks, best_pos_a, size_a);
    move_top_b(stacks, best_pos_b, size_b);
    
    // Push a B
    pb(stacks);
}

void	sort_small(t_stacks *stacks, int size)
{
    int	min_pos;
    int	i;

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
    {
        // Para 4-5 elementos, mover los más pequeños a B
        i = 0;
        while (i < size - 3 && i < 2)
        {
            min_pos = get_position(stacks->stack_a, get_min(stacks->stack_a));
            if (min_pos <= size / 2)
            {
                while (min_pos-- > 0)
                    ra(stacks);
            }
            else
            {
                while (min_pos++ < size)
                    rra(stacks);
            }
            pb(stacks);
            size--;
            i++;
        }
        
        // Ordenar los 3 que quedan en A
        sort_three(stacks);
        
        // Devolver los elementos de B a A
        while (i-- > 0)
            pa(stacks);
    }
}

void	sort_large(t_stacks *stacks)
{
    int	min_pos;

    
    // Conservar solo 2 elementos en A
    while (stack_size(stacks->stack_a) > 2)
        pb(stacks);
    
    // Ordenar los 2 restantes
    if (stacks->stack_a && stacks->stack_a->next && 
        stacks->stack_a->value > stacks->stack_a->next->value)
        sa(stacks);
    
    // Mientras B no esté vacío
    while (stacks->stack_b)
    {
        int b_val = stacks->stack_b->value;
        int target_pos = find_target_pos(b_val, stacks->stack_a);
        int size_a = stack_size(stacks->stack_a);
        
        // Mover A para insertar correctamente
        move_top_a(stacks, target_pos, size_a);
        
        // Insertar en A
        pa(stacks);
    }
    
    // Ajustar A para que el mínimo esté arriba
    min_pos = get_position(stacks->stack_a, get_min(stacks->stack_a));
    move_top_a(stacks, min_pos, stack_size(stacks->stack_a));
}

int	main(int argc, char **argv)
{
    t_stacks	stacks;
    int			size;

    if (argc < 2)
        return (0);
    init_stacks(&stacks, argc, argv);
    if (is_sorted(stacks.stack_a))
    {
        free_stacks(&stacks);
        return (0);
    }
    
    size = stack_size(stacks.stack_a);
    
    if (size <= 5)
        sort_small(&stacks, size);
    else
        sort_large(&stacks);
    
    free_stacks(&stacks);
    return (0);
}
