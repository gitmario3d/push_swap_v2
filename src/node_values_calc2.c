/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_values_calc2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:27:31 by malena-b          #+#    #+#             */
/*   Updated: 2024/04/25 11:27:31 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_total_cost_calc(t_stack *node)
{
	while (node)
	{
		if (node->cost_a < 0 && node->cost_b < 0)
		{
			if (node->cost_a < node->cost_b)
				node->cost_t = node->cost_a * -1;
			else
				node->cost_t = node->cost_b * -1;
		}
		else if (node->cost_a >= 0 && node->cost_b >= 0)
		{
			if (node->cost_a > node->cost_b)
				node->cost_t = (node->cost_a);
			else
				node->cost_t = (node->cost_b);
		}
		else
		{
			if (node->cost_a < 0)
				node->cost_t = ((node->cost_a * -1) + node->cost_b);
			else
				node->cost_t = (node->cost_a + (node->cost_b * -1));
		}
		node = node->next;
	}
}

int	ft_cheapest_node(t_stack *stack_b)
{
	t_stack	*aux;
	int		cheapest_pos;
	int		temp_value;

	aux = stack_b;
	ft_total_cost_calc(aux);
	aux = stack_b;
	cheapest_pos = aux->pos;
	temp_value = aux->cost_t;
	aux = aux->next;
	if (aux)
	{
		while (aux)
		{
			if (aux->cost_t < temp_value)
			{
				temp_value = aux->cost_t;
				cheapest_pos = aux->pos;
			}
			aux = aux->next;
		}
	}
	return (cheapest_pos);
}

void	ft_check_sign_and_op(t_stack *node, t_info *info, int sign, char c)
{
	int	cost;

	cost = 0;
	if (c == 'a')
		cost = node->cost_a;
	else if (c == 'b')
		cost = node->cost_b;
	while (cost != 0)
	{
		if (sign == -1)
			ft_call_rev_rot(info, c);
		else if (sign == 1)
			ft_call_rotate(info, c);
		cost += (sign * -1);
	}
}

void	ft_same_sign(t_info *info, t_stack *cheap_node, int sign)
{
	while (cheap_node->cost_a != 0 && cheap_node->cost_b != 0)
	{
		if (sign == -1)
			ft_call_rev_rot(info, 'r');
		else if (sign == 1)
			ft_call_rotate(info, 'r');
		cheap_node->cost_a += (sign * -1);
		cheap_node->cost_b += (sign * -1);
	}
	ft_check_sign_and_op(cheap_node, info, sign, 'a');
	ft_check_sign_and_op(cheap_node, info, sign, 'b');
}

void	ft_send_to_tpos(t_info *info, t_stack *node)
{
	int	sign;

	sign = 0;
	if (node->cost_a < 0 && node->cost_b < 0)
		ft_same_sign(info, node, -1);
	else if (node->cost_a > 0 && node->cost_b > 0)
		ft_same_sign(info, node, 1);
	else
	{
		if (node->cost_a < 0)
			sign = -1;
		else if (node->cost_a > 0)
			sign = 1;
		if (sign != 0)
			ft_check_sign_and_op(node, info, sign, 'a');
		sign = 0;
		if (node->cost_b < 0)
			sign = -1;
		else if (node->cost_b > 0)
			sign = 1;
		if (sign != 0)
			ft_check_sign_and_op(node, info, sign, 'b');
	}
	ft_call_push(info, 'a');
}
