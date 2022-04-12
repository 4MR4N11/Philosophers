/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:16:54 by kel-amra          #+#    #+#             */
/*   Updated: 2022/04/12 03:02:53 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	*routine(void *tmp)
{
	t_philos *philo = (t_philos *)tmp;
	pthread_mutex_lock(&philo->data->fork[philo->index - 1]);
	pthread_mutex_lock(&philo->data->fork[(philo->index) % philo->data->numofphils]);
	printf("philosopher [%d] has taken the first fork\n",philo->index);
	printf("philosopher [%d] has taken the second fork\n",philo->index);
	printf("philosopher [%d] start eating\n",philo->index);
	usleep(philo->data->to_eat * 1000);
	pthread_mutex_unlock(&philo->data->fork[philo->index - 1]);
	pthread_mutex_unlock(&philo->data->fork[(philo->index) % philo->data->numofphils]);
	return NULL;
}
int	execute(t_philos *philos)
{
	int i = 0;
	pthread_t *philo;
	philo = malloc(sizeof(pthread_t) * philos->data->numofphils);
	while(i < philos->data->numofphils)
	{
		pthread_create(&philo[i], NULL, &routine, &philos[i]);
		i++;
		usleep(100);
	}
	i = 0;
	while(i < philos->data->numofphils)
	{
		pthread_join(philo[i], NULL);
		i++;
	}
	i = 0;
	while(i < philos->data->numofphils)
	{
		pthread_mutex_destroy(&philos->data->fork[i]);
		i++;
	}
	return (0);
}