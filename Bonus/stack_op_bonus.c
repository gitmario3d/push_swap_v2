/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:18:00 by malena-b          #+#    #+#             */
/*   Updated: 2024/04/29 13:53:36 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

int	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (ft_stacksize(stack) < 2)
		return (0);
	first = *stack;
	second = first->next;
	third = second->next;
	second->next = first;
	first->next = third;
	*stack = second;
	return (1);
}

int	ft_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	if (!(*stack_b))
		return (0);
	aux = *stack_b;
	*stack_b = aux->next;
	aux->next = *stack_a;
	*stack_a = aux;
	return (1);
}

int	ft_rotate(t_stack **stack)
{
	t_stack	*aux;

	if (ft_stacksize(stack) < 2)
		return (0);
	aux = *stack;
	ft_stacklastnode(*stack)->next = *stack;
	*stack = (*stack)->next;
	aux->next = NULL;
	return (1);
}

int	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*aux;

	if (ft_stacksize(stack) < 2)
		return (0);
	aux = *stack;
	while ((aux->next)->next)
		aux = aux->next;
	(aux->next)->next = *stack;
	*stack = aux->next;
	aux->next = NULL;
	return (1);
}
