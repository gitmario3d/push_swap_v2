/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:13:33 by malena-b          #+#    #+#             */
/*   Updated: 2024/04/22 11:59:46 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

t_stack	*ft_newstacknode(int number)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->number = number;
	new_node->index = 0;
	new_node->pos = 0;
	new_node->target_pos = -1;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->cost_t = -1;
	new_node->max_index = -1;
	new_node->min_index = -1;
	new_node->min_index_pos = -1;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*ft_stacklastnode(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	if (!stack)
		return (NULL);
	while (aux->next)
		aux = aux->next;
	return (aux);
}

void	ft_nodeadd_back(t_stack **stack, t_stack *new_node)
{
	if ((*stack) != NULL)
		(ft_stacklastnode(*stack))->next = new_node;
	else
		*stack = new_node;
}

int	ft_stacksize(t_stack **stack)
{
	int		i;
	t_stack	*aux;

	if (!(*stack))
		return (0);
	i = 1;
	aux = *stack;
	while (aux->next)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}
