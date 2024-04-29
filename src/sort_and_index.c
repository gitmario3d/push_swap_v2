/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:11:55 by malena-b          #+#    #+#             */
/*   Updated: 2024/04/25 11:27:53 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_index_stack(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*max;
	int		size;

	size = ft_stacksize(stack);
	aux = *stack;
	max = NULL;
	while (size > 0)
	{
		while (aux)
		{
			if (aux->index == 0 && !max)
				max = aux;
			if (aux->index == 0 && aux->number > max->number)
				max = aux;
			aux = aux->next;
		}
		max->index = size;
		max = NULL;
		aux = *stack;
		size--;
	}
}

void	ft_sort_three(t_info *info)
{
	t_stack	*stack;

	stack = NULL;
	stack = info->stack_a;
	if (stack->index > stack->next->index
		&& stack->index > stack->next->next->index)
	{
		ft_call_rotate(info, 'a');
		stack = info->stack_a;
	}
	else if (stack->next->index > stack->next->next->index)
	{
		ft_call_rev_rot(info, 'a');
		stack = info->stack_a;
	}
	if (stack->index > stack->next->index)
		ft_call_swap(info, 'a');
}

void	ft_push_all_b(t_info *info)
{
	t_stack	*aux;

	aux = info->stack_a;
	while (((aux->next)->next)->next)
	{
		if (aux->index <= (info->size / 2))
			ft_call_push(info, 'b');
		else
		{
			ft_call_rotate(info, 'a');
			aux = info->stack_a;
			while (aux->index > info->size / 2 && aux->next)
				aux = aux->next;
			if (!(aux->next))
				break ;
		}
		aux = info->stack_a;
	}
	aux = info->stack_a;
	while (((aux->next)->next)->next)
	{
		ft_call_push(info, 'b');
		aux = info->stack_a;
	}
}

void	ft_final_sort(t_info *info)
{
	int	size;
	int	i;
	int	min_pos;

	size = ft_stacksize(&info->stack_a);
	ft_max_index_tpos(info);
	min_pos = info->stack_a->min_index_pos;
	i = 0;
	if (min_pos <= size / 2)
	{
		while (i < min_pos)
		{
			ft_call_rotate(info, 'a');
			i++;
		}
	}
	else
	{
		i = min_pos;
		while (i < size)
		{
			ft_call_rev_rot(info, 'a');
			i++;
		}
	}
}

void	ft_check_size_and_sort(t_info *info)
{
	int		cheapest_node_pos;
	t_stack	*aux;

	if (info->size == 2)
		ft_call_swap(info, 'a');
	else if (info->size == 3)
		ft_sort_three(info);
	else if (info->size > 3)
	{
		ft_push_all_b(info);
		ft_sort_three(info);
		while (ft_stacksize(&info->stack_b) > 0)
		{
			ft_pos_in_stack(&(info->stack_b));
			ft_pos_in_stack(&(info->stack_a));
			ft_target_pos(info);
			cheapest_node_pos = ft_cost_calc(info);
			aux = info->stack_b;
			while (aux->pos != cheapest_node_pos)
				aux = aux->next;
			ft_send_to_tpos(info, aux);
		}
	}
	ft_pos_in_stack(&(info->stack_a));
	ft_final_sort(info);
}
