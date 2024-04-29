/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:37:10 by malena-b          #+#    #+#             */
/*   Updated: 2023/12/27 09:34:54 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*int main (void)
{
	char	dst[] = "Original string";
	const char	*src = "copied";
	size_t	finalSize = 9;
	int	i;

	printf("Original string:%s\n", dst);
	i = ft_strlcpy(dst, src, finalSize);
	printf("Modified string:%s\n", dst);
	printf("Return Value:%d\n", i);
}*/
