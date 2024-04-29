/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:31:27 by malena-b          #+#    #+#             */
/*   Updated: 2024/04/29 14:40:43 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_mat_len(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
}

void	ft_arr_to_stack(t_info *info)
{
	int	i;
	int	size;

	size = info->size;
	info->stack_a = NULL;
	info->stack_a = ft_newstacknode(info->numbers[0]);
	if (!(info->stack_a))
		free_and_report("Error, problem initiating stack_a", info);
	i = 1;
	while (i < size)
		ft_nodeadd_back(&(info->stack_a), ft_newstacknode(info->numbers[i++]));
	info->size = ft_stacksize(&(info->stack_a));
}

t_info	*ft_init_info(void)
{
	t_info	*info;

	info = malloc (sizeof(t_info));
	if (!info)
		return (NULL);
	info->size = 0;
	info->numbers = NULL;
	info->stack_a = NULL;
	info->stack_b = NULL;
	info->mat = NULL;
	return (info);
}

void	ft_check_errors(int error_check, t_info *info)
{
	if (error_check == 0)
		free_and_report("Error", info);
}
