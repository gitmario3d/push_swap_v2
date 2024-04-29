/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:55:58 by malena-b          #+#    #+#             */
/*   Updated: 2023/12/27 09:33:24 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*void	delete(void *content)
{
	free(content);
}

void	*str_toupper(void *s)
{
	int		i;

	i = 0;
	while (((char *)s)[i])
	{
		((char *)s)[i] = ft_toupper(((char *)s)[i]);
		i++;
	}
	return (s);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mod_lst;
	t_list	*mod_node;

	if (!f || !del)
		return (NULL);
	mod_lst = NULL;
	while (lst)
	{
		mod_node = ft_lstnew(f(lst->content));
		if (!mod_node)
		{
			ft_lstclear(&mod_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&mod_lst, mod_node);
		lst = lst->next;
	}
	return (mod_lst);
}

/*int	main(void)
{
	t_list	**header;
	t_list	*new_lst;
	t_list	*temp;

	*header = ft_lstnew((char *)(ft_strdup("First")));
	ft_lstadd_back(header, ft_lstnew((char *)ft_strdup("Second")));
	ft_lstadd_back(header, ft_lstnew((char *)ft_strdup("Third")));
	ft_lstadd_back(header, ft_lstnew((char *)ft_strdup("Fourth")));
	temp = *header;
	while (temp->next)
	{
		printf("%s -> ", temp->content);
		temp = temp->next;
	}
	printf("%s\n", temp->content);
	new_lst = ft_lstmap(*header, str_toupper, delete);
	if (!new_lst)
		return (0);
	temp = new_lst;
	while (temp->next)
	{
		printf("%s -> ", temp->content);
		temp = temp->next;
	}
	printf("%s\n", temp->content);
}*/
