/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:57:35 by malena-b          #+#    #+#             */
/*   Updated: 2024/02/14 11:38:48 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_mallocformat(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[0] != c && s[0] != '\0')
		count++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

static int	ft_nextdel(const char *s, char c, int i)
{
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_reduce_lines(char **mat, int count)
{
	mat[count] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**mat;
	int		mat_pos;
	int		i;
	int		count;

	count = ft_mallocformat(s, c);
	mat = (char **)malloc((count + 1) * sizeof(char *));
	if (mat == NULL)
		return (NULL);
	i = ft_reduce_lines(mat, count);
	mat_pos = 0;
	while (mat_pos < count)
	{
		while (s[i])
		{
			if (s[i] != c && s[i])
			{
				mat[mat_pos++] = ft_substr(s, i, (ft_nextdel(s, c, i) - i));
				i = ft_nextdel(s, c, i);
			}
			else
				i++;
		}
	}
	return (mat);
}
