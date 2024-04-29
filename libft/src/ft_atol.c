/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:49:16 by malena-b          #+#    #+#             */
/*   Updated: 2024/02/22 12:01:52 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_normatoi(long result, long i, long sign, const char	*str)
{
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i + 1] >= '0' && str [i + 1] <= '9')
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
		else
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		if (str[i + 1] < '0' || str[i + 1] > '9')
			return (result * sign);
		i++;
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	long	i;
	long	sign;

	result = 0;
	sign = 1;
	i = 0;
	result = ft_normatoi(result, i, sign, str);
	return (result);
}
