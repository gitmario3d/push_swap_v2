/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:10:27 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/02 11:49:13 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_checkfor_invchars(char **mat, int i)
{
	int	j;

	j = 0;
	while (mat[i])
	{
		while (mat[i][j])
		{
			if (mat[i][j] == '-' || mat[i][j] == '+')
			{
				if (j != 0)
					return (0);
				if (mat[i][j + 1] < '0' && mat[i][j + 1] > '9')
					return (0);
			}
			else if (mat[i][j] < '0' || mat[i][j] > '9')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_save_numbers(t_info *info, char **mat, int i, int size)
{
	int		j;
	long	l;

	info->numbers = (int *)ft_calloc(size - i, sizeof(int));
	j = 0;
	info->size = size - i;
	while (i < size)
	{
		l = ft_atol(mat[i]);
		if (l > INT_MAX || l < INT_MIN)
			return (0);
		info->numbers[j] = l;
		i++;
		j++;
	}
	return (1);
}

int	ft_doub_and_order(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (info->numbers[++i])
	{
		j = i;
		while (info->numbers[++j])
		{
			if (info->numbers[j] == info->numbers[i])
				return (0);
		}
	}
	i = -1;
	while (info->numbers[++i])
	{
		j = i;
		while (info->numbers[++j])
		{
			if (info->numbers[j] <= info->numbers[i])
				return (1);
		}
	}
	return (2);
}

int	ft_check_arg(int argc, char **argv, t_info *info)
{
	if (argc == 2)
	{
		info->mat = ft_split(argv[1], ' ');
		if (ft_checkfor_invchars(info->mat, 0) == 0
			|| ft_save_numbers(info, info->mat, 0, ft_mat_len(info->mat)) == 0
			|| ft_mat_len(info->mat) == 0)
			return (0);
		return (ft_doub_and_order(info));
	}
	else if (argc > 2)
	{
		if (ft_checkfor_invchars(argv, 1) == 0)
			return (0);
		if (ft_save_numbers(info, argv, 1, argc) == 0)
			return (0);
		return (ft_doub_and_order(info));
	}
	return (0);
}
