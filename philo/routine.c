/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:37:11 by kel-amra          #+#    #+#             */
/*   Updated: 2022/04/15 22:34:06 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

long	get_time(void)
{
	long			time;
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL))
		return (-1);
	time = ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
	return (time);
}

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
			pthread_mutex_unlock(&philo->data->program);
			break ;
		}
	}
	return (NULL);
}

void	routine(t_philos *philo)
{
	int			n_philo;

	n_philo = philo->data->philo_n;
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
}

void	*routine_caller(void *tmp)
{
	t_philos	*philo;
	int			n_philo;

	philo = (t_philos *)tmp;
	n_philo = philo->data->philo_n;
	philo->last_meal = get_time();
	pthread_create(&philo->data->check, NULL, &check_death, tmp);
	pthread_detach(philo->data->check);
	routine(philo);
	pthread_mutex_lock(&philo->data->meals);
	if (philo->data->meals_count != (philo->numofmeals * n_philo))
		pthread_mutex_lock(&philo->data->meals);
	pthread_mutex_unlock(&philo->data->meals);
	pthread_mutex_unlock(&philo->data->program);
	return (NULL);
}
