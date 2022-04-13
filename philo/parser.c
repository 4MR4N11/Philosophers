/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:26:55 by kel-amra          #+#    #+#             */
/*   Updated: 2022/04/12 22:58:41 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include <unistd.h>

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
	if(tmp->numofphils == 1)
	{
		printf("%ld [%d] \033[1;31mdied\e[0m\n", get_time(),1);
		exit(1);
	}
	tmp->to_die = ft_atoi(av[1]);
	tmp->to_eat = ft_atoi(av[2]);
	tmp->to_sleep = ft_atoi(av[3]);
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
		if(av[4])
			philos[i].eat_times = ft_atoi(av[4]);
		else
			philos[i].eat_times = -1;
		philos[i].index = i +1;
		philos[i].data = tmp;
		i++;
	}
	return (philos);
}
