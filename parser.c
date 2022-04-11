/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:26:55 by kel-amra          #+#    #+#             */
/*   Updated: 2022/04/11 02:33:38 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include <unistd.h>

long	get_time(void)
{
	long	time;
	struct timeval current_time;
	if(gettimeofday(&current_time, NULL))
		return -1;
	time = ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
	return (time);
}

static	int	args_checker(char **av)
{
	int	i;

	i = -1;
	while(av[++i])
	{
		if(ft_atoi(av[i]) <= 0)
			return (1);
	}
	return (0);
}

int	parsing(char **av, t_data *tmp)
{
	// t_philos *ptr;
	int i;

	if(args_checker(av))
		return (1);
	tmp->numofphils = ft_atoi(av[0]);
	if(tmp->numofphils <= 0)
		return (1);
	tmp->forks = ft_atoi(av[0]);
	tmp->philos = malloc(sizeof(t_philos) * tmp->numofphils);
	if(!tmp->philos)
		return (1);
	i = 0;	
	while(i < tmp->numofphils)
	{
		tmp->philos[i].index = i+1;
		tmp->philos[i].to_die = ft_atoi(av[1]);
		tmp->philos[i].to_eat = ft_atoi(av[2]);
		tmp->philos[i].to_sleep = ft_atoi(av[3]);
		if(av[4])
			tmp->philos[i].eat_times = ft_atoi(av[4]);
		i++;
	}
	return (0);
}
