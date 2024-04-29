/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_calls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:11:44 by malena-b          #+#    #+#             */
/*   Updated: 2024/03/05 13:04:20 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_call_push(t_info	*info, char c)
{
	int	valid_call;

	valid_call = 0;
	if (c == 'a')
		valid_call = ft_push(&(info->stack_a), &(info->stack_b));
	if (c == 'b')
		valid_call = ft_push(&(info->stack_b), &(info->stack_a));
	if (valid_call == 1)
		ft_printf("p%c\n", c);
	return (valid_call);
}

int	ft_call_swap(t_info	*info, char c)
{
	int	valid_call;

	valid_call = 0;
	if (c == 'a')
		valid_call = ft_swap(&(info->stack_a));
	if (c == 'b')
		valid_call = ft_swap(&(info->stack_b));
	if (c == 's')
	{
		valid_call = ft_swap(&(info->stack_a));
		valid_call = ft_swap(&(info->stack_b));
	}
	if (valid_call == 1)
		ft_printf("s%c\n", c);
	return (valid_call);
}

int	ft_call_rotate(t_info *info, char c)
{
	int	valid_call;

	valid_call = 0;
	if (c == 'a')
		valid_call = ft_rotate(&(info->stack_a));
	if (c == 'b')
		valid_call = ft_rotate(&(info->stack_b));
	if (c == 'r')
	{
		valid_call = ft_rotate(&(info->stack_a));
		valid_call = ft_rotate(&(info->stack_b));
	}
	if (valid_call == 1)
		ft_printf("r%c\n", c);
	return (valid_call);
}

int	ft_call_rev_rot(t_info *info, char c)
{
	int	valid_call;

	valid_call = 0;
	if (c == 'a')
		valid_call = ft_reverse_rotate(&(info->stack_a));
	if (c == 'b')
		valid_call = ft_reverse_rotate(&(info->stack_b));
	if (c == 'r')
	{
		valid_call = ft_reverse_rotate(&(info->stack_a));
		valid_call = ft_reverse_rotate(&(info->stack_b));
	}
	if (valid_call == 1)
		ft_printf("rr%c\n", c);
	return (valid_call);
}
