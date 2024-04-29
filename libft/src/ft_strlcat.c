/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:30:59 by malena-b          #+#    #+#             */
/*   Updated: 2023/12/27 09:34:51 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char	*dst, const char	*src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_size;
	size_t	dst_size;

	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	i = dst_size;
	j = 0;
	if (dst_size >= dstsize)
		return (dstsize + src_size);
	while (i < (dstsize - 1) && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (src_size + dst_size);
}

/*int main (void)
{
	char	dst[] = "Hello";
	const char	*src = " World";
	size_t	dstsize = 0;
	size_t	i;

	printf("Original string:%s\n", dst);
	i = ft_strlcat(dst, src, dstsize);
	printf("Modified string:%s\n", dst);
	printf("Return Value:%zu\n", i);
}*/