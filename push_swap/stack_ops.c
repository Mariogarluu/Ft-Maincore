/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:14:21 by marioga2          #+#    #+#             */
/*   Updated: 2025/03/10 13:15:42 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stacks *stacks, int argc, char **argv)
{
    int i;

    stacks->stack_a = NULL;
    stacks->stack_b = NULL;
    i = 1;
    while (i < argc)
    {
        t_list *new_node = ft_lstnew(ft_itoa(ft_atoi(argv[i])));
        ft_lstadd_back(&stacks->stack_a, new_node);
        i++;
    }
}

