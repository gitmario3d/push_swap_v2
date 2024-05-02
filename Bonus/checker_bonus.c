/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:45:21 by malena-b          #+#    #+#             */
/*   Updated: 2024/05/02 12:19:28 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

/*void	ft_leaks(void)
{
	system("leaks -q checker");
}*/

static void	ft_identify_calls(char *line, t_info *info)
{
	if (!ft_strncmp(line, "sa\n", ft_strlen(line)))
		ft_call_swap(info, 'a');
	else if (!ft_strncmp(line, "sb\n", ft_strlen(line)))
		ft_call_swap(info, 'b');
	else if (!ft_strncmp(line, "ss\n", ft_strlen(line)))
		ft_call_swap(info, 's');
	else if (!ft_strncmp(line, "pa\n", ft_strlen(line)))
		ft_call_push(info, 'a');
	else if (!ft_strncmp(line, "pb\n", ft_strlen(line)))
		ft_call_push(info, 'b');
	else if (!ft_strncmp(line, "ra\n", ft_strlen(line)))
		ft_call_rotate(info, 'a');
	else if (!ft_strncmp(line, "rb\n", ft_strlen(line)))
		ft_call_rotate(info, 'b');
	else if (!ft_strncmp(line, "rr\n", ft_strlen(line)))
		ft_call_rotate(info, 'r');
	else if (!ft_strncmp(line, "rra\n", ft_strlen(line)))
		ft_call_rev_rot(info, 'a');
	else if (!ft_strncmp(line, "rrb\n", ft_strlen(line)))
		ft_call_rev_rot(info, 'b');
	else if (!ft_strncmp(line, "rrr\n", ft_strlen(line)))
		ft_call_rev_rot(info, 'r');
	else
		free_and_report("Error", info);
}

static void	ft_check_calls(t_info *info)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		ft_identify_calls(line, info);
		free(line);
		line = get_next_line(0);
	}
	if (!ft_check_sorted(info))
		free_and_report("KO", info);
	ft_printf("OK\n");
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc < 2)
		return (0);
	info = NULL;
	if (argc == 2 && !argv[1][0])
		free_and_report("Error", info);
	info = ft_init_info();
	ft_check_errors(ft_check_arg(argc, argv, info), info);
	ft_arr_to_stack(info);
	ft_check_calls(info);
	free_and_report("", info);
	return (0);
}
