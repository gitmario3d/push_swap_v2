/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:42:53 by malena-b          #+#    #+#             */
/*   Updated: 2023/12/27 09:34:48 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		finallen;
	char	*str;
	int		i;
	int		j;

	finallen = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(finallen * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

/*int	main(void)
{
	char	*s1 = "Let's ";
	char	*s2 = "Go";

	printf("First string: %s\n", s1);
	printf("Second string: %s\n", s2);
	printf("ft_strjoin result: %s\n", (ft_strjoin(s1, s2)));
}*/