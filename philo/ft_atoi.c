/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:25:36 by kel-amra          #+#    #+#             */
/*   Updated: 2022/04/14 20:11:50 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	ft_skip_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == 32)
		i++;
	return (i);
}

static int	ft_sign(const char *str)
{
	int	i;

	i = ft_skip_space(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] < 48 || str[i + 1] > 57)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;

	nb = 0;
	i = ft_skip_space(str);
	i = ft_sign(str);
	if (i == -1)
		return (-1);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			nb = nb + (str[i] - 48);
			if (str[i + 1] != '\0' && (str[i + 1] <= 57 && str[i + 1] >= 48))
				nb = nb * 10;
		}
		else
			return (-1);
		i++;
	}
	i = ft_skip_space(str);
	i = ft_sign(str);
	if (str[i - 1] == '-')
		nb = nb * -1;
	return (nb);
}
