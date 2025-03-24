/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:15:20 by marioga2          #+#    #+#             */
/*   Updated: 2025/03/24 14:15:20 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_stacknew(int value)
{
    t_stack_node	*new_node;

    new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->current_position = 0;
    new_node->final_index = 0;
    new_node->push_price = 0;
    new_node->above_median = false;
    new_node->cheapest = false;
    new_node->target_node = NULL;
    new_node->next = NULL;
    new_node->prev = NULL;
    return (new_node);
}

void	ft_free_all(t_stack_node **stack_a, t_stack_node **stack_b)
{
    t_stack_node	*tmp;

    while (*stack_a)
    {
        tmp = (*stack_a)->next;
        free(*stack_a);
        *stack_a = tmp;
    }
    while (*stack_b)
    {
        tmp = (*stack_b)->next;
        free(*stack_b);
        *stack_b = tmp;
    }
}

int	be_sorted(t_stack_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void	ft_be_duplicated(t_stack_node *stack)
{
    t_stack_node	*current;
    t_stack_node	*checker;

    current = stack;
    while (current)
    {
        checker = current->next;
        while (checker)
        {
            if (current->value == checker->value)
            {
                write(2, "Error\n", 6);
                exit(EXIT_FAILURE);
            }
            checker = checker->next;
        }
        current = current->next;
    }
}

void	be_nbr(const char *str)
{
    int	i;

    i = 0;
    while (str[i])
    {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
        {
            write(2, "Error\n", 6);
            exit(EXIT_FAILURE);
        }
        i++;
    }
}

void	ft_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
    (void)stack_b; // Por ahora no usamos stack_b
    sort_stack(stack_a);
}

int	main(int argc, char *argv[])
{
    t_stack_node	*stack_a;
    t_stack_node	*stack_b;
    t_stack_node	*tmp;
    int				i;

    if (argc < 2)
        return (0);
    stack_a = NULL;
    stack_b = NULL;
    tmp = NULL;
    i = argc - 1;
    while (i > 0)
    {
        be_nbr(argv[i]);
        tmp = ft_stacknew(ft_atoi(argv[i]));
        tmp->next = stack_a;
        if (stack_a)
            stack_a->prev = tmp;
        stack_a = tmp;
        i--;
    }
    ft_be_duplicated(stack_a);
    if (be_sorted(stack_a))
        return (0);
    ft_sort(&stack_a, &stack_b);
    ft_free_all(&stack_a, &stack_b);
    return (0);
}