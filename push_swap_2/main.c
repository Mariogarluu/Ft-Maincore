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