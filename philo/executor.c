/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:16:54 by kel-amra          #+#    #+#             */
/*   Updated: 2022/04/14 01:59:51 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	message(char msg, t_philos *philo)
{
	pthread_mutex_lock(&philo->data->msg);
	if (msg == 'F')
		printf("%ld [%d] has taken a fork\n", get_time(), philo->index);
	else if (msg == 'E')
	{
		printf("%ld [%d] is \033[1;34meating\e[0m\n", get_time(), philo->index);
		philo->numofmeals--;
		philo->data->meals_count++;
	}
	else if (msg == 'S')
		printf("%ld [%d] is \033[1;34msleeping\e[0m\n", get_time(), philo->index);
	else if (msg == 'T')
		printf("%ld [%d] is \033[1;34mthinking\e[0m\n", get_time(), philo->index);
	pthread_mutex_unlock(&philo->data->msg);
}

long	get_time(void)
{
	long			time;
	struct timeval	current_time;
	if (gettimeofday(&current_time, NULL))
		return (-1);
	time = ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
	return (time);
}

void	*check_death(void *ptr)
{
	t_philos	*philo;

	philo = (t_philos *)ptr;
	pthread_mutex_init(&philo->data->tmp, NULL);
	while (1)
	{
		if (get_time() > (philo->last_meal + philo->data->to_die))
		{
			pthread_mutex_lock(&philo->data->tmp);
			pthread_mutex_lock(&philo->data->msg);
			if (philo->numofmeals != (philo->numofmeals * philo->data->philo_n))
				printf("%ld [%d] \033[1;31mdied\e[0m\n", get_time(), philo->index);
			// pthread_mutex_unlock(&philo->data->msg);
			pthread_mutex_unlock(&philo->data->program);
			break;
		}
	}
	return (NULL);
}

void	*routine(void *tmp)
{
	t_philos *philo;

	philo = (t_philos *)tmp;
	int n_philo = philo->data->philo_n;
	philo->last_meal = get_time();

	pthread_create(&philo->data->check, NULL, &check_death, tmp);
	pthread_detach(philo->data->check);
	while (1)
	{
		if (philo->numofmeals == 0)
			break ;
		pthread_mutex_lock(&philo->data->fork[philo->index - 1]);
		message('F', philo);
		pthread_mutex_lock(&philo->data->fork[philo->index % n_philo]);
		message('F', philo);
		message('E', philo);
		philo->last_meal = get_time();
		usleep(philo->data->to_eat * 1000);
		pthread_mutex_unlock(&philo->data->fork[philo->index - 1]);
		pthread_mutex_unlock(&philo->data->fork[philo->index % n_philo]);
		message('S', philo);
		usleep(philo->data->to_sleep * 1000);
		message('T', philo);
	}
	pthread_mutex_lock(&philo->data->meals);
	if (philo->data->meals_count != (philo->numofmeals * n_philo))
		pthread_mutex_lock(&philo->data->meals);
	pthread_mutex_unlock(&philo->data->meals);
	pthread_mutex_unlock(&philo->data->program);
	return (NULL);
}

int	execute(t_philos *philos)
{
	int			i;
	pthread_t	*philo;
	int			count;

	i = -1;
	count = 0;
	pthread_mutex_init(&philos->data->program, NULL);
	pthread_mutex_init(&philos->data->msg, NULL);
	pthread_mutex_init(&philos->data->meals, NULL);
	philo = malloc(sizeof(pthread_t) * philos->data->philo_n);
	philos->data->meals_count = 0;
	while (++i < philos->data->philo_n)
	{
		pthread_create(&philo[i], NULL, &routine, &philos[i]);
		usleep(100);
	}
	pthread_mutex_lock(&philos->data->program);
	i = -1;
	while (++i < philos->data->philo_n)
		pthread_detach(philo[i]);
	pthread_mutex_lock(&philos->data->program);
	i = -1;
	while (++i < philos->data->philo_n)
	{
		if (philos->numofmeals == 0)
			count++;
		if (count + 1 == philos->data->philo_n)
			printf("\033[1;32mall philosophers ate thier meals\e[0m\n");
	}
	i = -1;
	while (++i < philos->data->philo_n)
		pthread_mutex_destroy(&philos->data->fork[i]);
	pthread_mutex_destroy(&philos->data->tmp);
	pthread_mutex_destroy(&philos->data->program);
	pthread_mutex_destroy(&philos->data->meals);
	pthread_mutex_destroy(&philos->data->msg);
	i = -1;
	return (0);
}
