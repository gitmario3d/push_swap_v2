/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_calls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:11:44 by malena-b          #+#    #+#             */
/*   Updated: 2024/04/29 14:34:19 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

int	ft_call_push(t_info	*info, char c)
{
	int	valid_call;

	valid_call = 0;
	if (c == 'a')
	{
		if (ft_stacksize(&(info->stack_b)) < 1)
			free_and_report("KO", info);
		valid_call = ft_push(&(info->stack_a), &(info->stack_b));
	}
	if (c == 'b')
	{
		if (ft_stacksize(&(info->stack_a)) < 1)
			free_and_report("KO", info);
		valid_call = ft_push(&(info->stack_b), &(info->stack_a));
	}
	return (valid_call);
}

int	ft_call_swap(t_info	*info, char c)
{
	int	valid_call;

	valid_call = 0;
	if (c == 'a')
	{
		if (ft_stacksize(&(info->stack_a)) < 2)
			free_and_report("KO", info);
		valid_call = ft_swap(&(info->stack_a));
	}
	if (c == 'b')
	{
		if (ft_stacksize(&(info->stack_b)) < 2)
			free_and_report("KO", info);
		valid_call = ft_swap(&(info->stack_b));
	}
	if (c == 's')
	{
		if (ft_stacksize(&(info->stack_b)) < 2
			|| ft_stacksize(&(info->stack_a)) < 2)
			free_and_report("KO", info);
		valid_call = ft_swap(&(info->stack_a));
		valid_call = ft_swap(&(info->stack_b));
	}
	return (valid_call);
}

int	ft_call_rotate(t_info *info, char c)
{
	int	valid_call;

	valid_call = 0;
	if (c == 'a')
	{
		if (ft_stacksize(&(info->stack_a)) < 2)
			free_and_report("KO", info);
		valid_call = ft_rotate(&(info->stack_a));
	}
	if (c == 'b')
	{
		if (ft_stacksize(&(info->stack_b)) < 2)
			free_and_report("KO", info);
		valid_call = ft_rotate(&(info->stack_b));
	}
	if (c == 'r')
	{
		if (ft_stacksize(&(info->stack_b)) < 2
			|| ft_stacksize(&(info->stack_a)) < 2)
			free_and_report("KO", info);
		valid_call = ft_rotate(&(info->stack_a));
		valid_call = ft_rotate(&(info->stack_b));
	}
	return (valid_call);
}

int	ft_call_rev_rot(t_info *info, char c)
{
	int	valid_call;

	valid_call = 0;
	if (c == 'a')
	{
		if (ft_stacksize(&(info->stack_a)) < 2)
			free_and_report("KO", info);
		valid_call = ft_reverse_rotate(&(info->stack_a));
	}
	if (c == 'b')
	{
		if (ft_stacksize(&(info->stack_b)) < 2)
			free_and_report("KO", info);
		valid_call = ft_reverse_rotate(&(info->stack_b));
	}
	if (c == 'r')
	{
		if (ft_stacksize(&(info->stack_b)) < 2
			|| ft_stacksize(&(info->stack_a)) < 2)
			free_and_report("KO", info);
		valid_call = ft_reverse_rotate(&(info->stack_a));
		valid_call = ft_reverse_rotate(&(info->stack_b));
	}
	return (valid_call);
}
