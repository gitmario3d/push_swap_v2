/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:11:30 by malena-b          #+#    #+#             */
/*   Updated: 2024/04/29 12:32:41 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				number;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	int				cost_t;
	int				min_index;
	int				min_index_pos;
	int				max_index;
	struct s_stack	*next;
}					t_stack;

typedef struct t_info_
{
	int		*numbers;
	char	**mat;
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;
}				t_info;

int		ft_check_arg(int argc, char **argv, t_info *info);
int		ft_mat_len(char **mat);
void	ft_arr_to_stack(t_info *info);
t_info	*ft_init_info(void);
void	ft_check_errors(int error_check, t_info *info);
void	ft_printstack(t_stack **stack);

//-------------------------Free functions-------------------------//
void	ft_free_mat(char **mat);
void	free_and_report(char *str, t_info *info);

//-------------------------Node functions-------------------------//
t_stack	*ft_newstacknode(int number);
void	ft_nodeadd_back(t_stack **stack, t_stack *new_node);
t_stack	*ft_stacklastnode(t_stack *stack);
int		ft_stacksize(t_stack **stack);
void	ft_send_to_tpos(t_info *info, t_stack *node);

//-------------------Stack operations functions-------------------//
int		ft_swap(t_stack **stack);
int		ft_push(t_stack **stack_a, t_stack **stack_b);
int		ft_rotate(t_stack **stack);
int		ft_reverse_rotate(t_stack **stack);

//-------------------Calls to stack operations-------------------//
int		ft_call_push(t_info	*info, char c);
int		ft_call_swap(t_info	*info, char c);
int		ft_call_rotate(t_info *info, char c);
int		ft_call_rev_rot(t_info *info, char c);

//-----------------Stack calculations functions-----------------//
void	ft_index_stack(t_stack **stack);
void	ft_printstack(t_stack **stack);
void	ft_check_size_and_sort(t_info *info);
void	ft_pos_in_stack(t_stack **stack);
void	ft_target_pos(t_info *info);
int		ft_cost_calc(t_info *info);
int		ft_cheapest_node(t_stack *stack_b);
void	ft_max_index_tpos(t_info *info);

#endif