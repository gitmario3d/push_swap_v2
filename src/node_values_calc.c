/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_values_calc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:26:52 by malena-b          #+#    #+#             */
/*   Updated: 2024/04/25 11:27:08 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pos_in_stack(t_stack **stack)
{
	int		i;
	t_stack	*aux;

	i = 0;
	aux = *stack;
	while (aux)
	{
		aux->pos = i++;
		aux = aux->next;
	}
}

void	ft_max_index_tpos(t_info *info)
{
	t_stack	*aux_a;
	t_stack	*stack_a;

	aux_a = info->stack_a;
	stack_a = info->stack_a;
	while (aux_a)
	{
		if (stack_a->min_index == -1)
		{
			stack_a->min_index = aux_a->index;
			stack_a->max_index = aux_a->index;
			stack_a->min_index_pos = aux_a->pos;
		}
		else if (aux_a->index > stack_a->max_index)
			stack_a->max_index = aux_a->index;
		else if (aux_a->index < stack_a->min_index)
		{
			stack_a->min_index = aux_a->index;
			stack_a->min_index_pos = aux_a->pos;
		}
		aux_a = aux_a->next;
	}
}

void	ft_tpos_aux(t_info *info, t_stack *aux_a, t_stack *aux_b, int t_index)
{
	int		t_pos;

	while (aux_a)
	{
		if (aux_b->index < aux_a->index && t_index == 0)
		{
			t_index = aux_a->index;
			t_pos = aux_a->pos;
		}
		else if (aux_a->index > aux_b->index && aux_a->index < t_index)
		{
			t_index = aux_a->index;
			t_pos = aux_a->pos;
		}
		aux_a = aux_a->next;
	}
	aux_b->target_pos = t_pos;
	aux_a = info->stack_a;
}

void	ft_target_pos(t_info *info)
{
	t_stack	*aux_a;
	t_stack	*aux_b;
	int		t_index;

	t_index = 0;
	aux_a = info->stack_a;
	aux_b = info->stack_b;
	ft_max_index_tpos(info);
	while (aux_b)
	{
		if (aux_b->index > info->stack_a->max_index)
			aux_b->target_pos = info->stack_a->min_index_pos;
		else
			ft_tpos_aux(info, aux_a, aux_b, t_index);
		aux_b = aux_b->next;
		t_index = 0;
	}
}

int	ft_cost_calc(t_info *info)
{
	int		size_a;
	int		size_b;
	t_stack	*stack_b;
	t_stack	*stack_a;

	size_a = ft_stacksize(&info->stack_a);
	size_b = ft_stacksize(&info->stack_b);
	stack_b = info->stack_b;
	stack_a = info->stack_a;
	while (stack_b)
	{
		if (stack_b->pos <= size_b / 2)
			stack_b->cost_b = stack_b->pos;
		else
			stack_b->cost_b = -1 * (size_b - stack_b->pos);
		while (stack_a->pos != stack_b->target_pos)
			stack_a = stack_a->next;
		if (stack_a->pos <= size_a / 2)
			stack_b->cost_a = stack_a->pos;
		else
			stack_b->cost_a = -1 * (size_a - stack_a->pos);
		stack_b = stack_b->next;
		stack_a = info->stack_a;
	}
	return (ft_cheapest_node(info->stack_b));
}
