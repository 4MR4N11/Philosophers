/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:16:54 by kel-amra          #+#    #+#             */
/*   Updated: 2022/04/14 21:25:47 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	free_data(t_philos	*data, pthread_t *philos_t)
{
	// int	i;

	// i = -1;
	// while (++i < data->data->philo_n)
	// 	pthread_mutex_destroy(&data->data->fork[i]);
	// pthread_mutex_destroy(&data->data->tmp);
	// pthread_mutex_destroy(&data->data->program);
	// pthread_mutex_destroy(&data->data->meals);
	// pthread_mutex_destroy(&data->data->msg);
	// free(data->data->fork);
	data->data->fork = NULL;
	philos_t = NULL;
	free(data);
	// free(philos_t);
}

void	meals_checker(t_philos *philos)
{
	int			i;
	int			count;

	i = -1;
	count = 0;
	while (++i < philos->data->philo_n)
	{
		if (philos->numofmeals == 0)
			count++;
		if (count + 1 == philos->data->philo_n)
			printf("\033[1;32mall philosophers ate thier meals\e[0m\n");
	}
}

int	execute(t_philos *philos)
{
	int			i;
	pthread_t	*philo;

	i = -1;
	pthread_mutex_init(&philos->data->program, NULL);
	pthread_mutex_init(&philos->data->msg, NULL);
	pthread_mutex_init(&philos->data->meals, NULL);
	philo = malloc(sizeof(pthread_t) * philos->data->philo_n);
	if (!philo)
		return (free_data(NULL, philo), 1);
	philos->data->meals_count = 0;
	while (++i < philos->data->philo_n)
	{
		pthread_create(&philo[i], NULL, &routine_caller, &philos[i]);
		usleep(100);
	}
	pthread_mutex_lock(&philos->data->program);
	i = -1;
	while (++i < philos->data->philo_n)
		pthread_detach(philo[i]);
	pthread_mutex_lock(&philos->data->program);
	meals_checker(philos);
	return (free_data(philos, philo), 0);
}
