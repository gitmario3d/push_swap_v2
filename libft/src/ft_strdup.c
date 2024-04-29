/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:33:14 by malena-b          #+#    #+#             */
/*   Updated: 2023/12/27 09:34:31 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	copy = (char *)malloc(sizeof(const char) * (len + 1));
	if (copy == NULL)
		return (copy);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*int	main(void)
{
	const char	s1[] = "Testing the function";
	char		*copy;

	copy = ft_strdup(s1);
	printf("Original string: %s\n", s1);
	printf("Copy of the original string: %s\n", copy);
	free(copy);
	return (0);
}*/