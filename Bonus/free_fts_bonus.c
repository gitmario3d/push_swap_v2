/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fts_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:18:48 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/02 11:56:17 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

void	ft_free_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		free(mat[i++]);
	free (mat);
}

void	ft_free_stack(t_stack *stack)
{
	t_stack	*aux;

	while (stack->next)
	{
		aux = stack->next;
		free (stack);
		stack = NULL;
		stack = aux;
	}
	free (stack);
}

void	free_and_report(char *str, t_info *info)
{
	if (info)
	{
		if (info->mat)
			ft_free_mat(info->mat);
		info->mat = NULL;
		if (info->numbers)
			free (info->numbers);
		if (info->stack_a)
		{
			ft_free_stack(info->stack_a);
			info->stack_a = NULL;
		}
		if (info->stack_b)
		{
			ft_free_stack(info->stack_b);
			info->stack_b = NULL;
		}
		free (info);
		info = NULL;
	}
	if (ft_strlen(str) > 0)
		ft_printf("%s\n", str);
	exit (0);
}
