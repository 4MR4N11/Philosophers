/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:26:55 by kel-amra          #+#    #+#             */
/*   Updated: 2022/03/23 20:32:07 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	parcing(char **av, t_data *ptr)
{
	ptr->philos = ft_atoi(av[0]);
	ptr->to_die = ft_atoi(av[1]);
	ptr->to_eat = ft_atoi(av[2]);
	ptr->to_sleep = ft_atoi(av[3]);
	if(av[4])
		ptr->eat_times = ft_atoi(av[4]);
	if(ptr->philos <= 0)
		return (1);
	else if(ptr->to_die <= 0)
		return (1);
	else if(ptr->to_eat <= 0)
		return (1);
	else if(ptr->to_sleep <= 0)
		return (1);
	return 0;
}