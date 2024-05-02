/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:10:47 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/02 12:00:52 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*void	ft_leaks(void)
{
	system("leaks -q push_swap");
}*/

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc == 1)
		return (0);
	info = NULL;
	info = ft_init_info();
	ft_check_errors(ft_check_arg(argc, argv, info), info);
	ft_arr_to_stack(info);
	ft_index_stack(&(info->stack_a));
	ft_check_size_and_sort(info);
	free_and_report("", info);
	return (0);
}
