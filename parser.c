/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:26:55 by kel-amra          #+#    #+#             */
/*   Updated: 2022/04/12 02:58:20 by kel-amra         ###   ########.fr       */
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

t_philos	*parsing(char **av, t_data *tmp)
{
	int i;
	t_philos *philos;

	if(args_checker(av))
		return (NULL);
	tmp->numofphils = ft_atoi(av[0]);
	if(tmp->numofphils <= 0)
		return (NULL);
	tmp->to_die = ft_atoi(av[1]);
	tmp->to_eat = ft_atoi(av[2]);
	tmp->to_sleep = ft_atoi(av[3]);
	if(av[4])
		tmp->eat_times = ft_atoi(av[4]);
	tmp->fork = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) * tmp->numofphils);
	philos = (t_philos*)malloc(sizeof(t_philos) * tmp->numofphils);
	if(!philos || !tmp->fork)
		return (NULL);
	i = -1;
	while (++i < tmp->numofphils)
		pthread_mutex_init(&tmp->fork[i], NULL);
	i = 0;
	while(i < tmp->numofphils)
	{
		philos[i].index = i +1;
		philos[i].data = tmp;
		i++;
	}
	return (philos);
}
