/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:16:54 by kel-amra          #+#    #+#             */
/*   Updated: 2022/04/13 03:28:01 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	message(char msg, t_philos *philo)
{
	pthread_mutex_lock(&philo->data->msg);
	if(msg == 'f')
		printf("%ld [%d] has taken a \033[1;34mfork\e[0m\n", get_time(),philo->index);
	else if(msg == 'e')
		printf("%ld [%d] is \033[1;34meating\e[0m\n",get_time() ,philo->index);
	else if(msg == 's')
		printf("%ld [%d] is \033[1;34msleeping\e[0m\n", get_time(),philo->index);
	else if(msg == 't')
		printf("%ld [%d] is \033[1;34mthinking\e[0m\n", get_time(),philo->index);
	else if(msg == 'd')
	{
		printf("%ld [%d] \033[1;31mdied\e[0m\n", get_time(),philo->index);
		pthread_mutex_unlock(&philo->data->program);
		return ;
	}
	pthread_mutex_unlock(&philo->data->msg);	
}

long	get_time(void)
{
	long	time;
	struct timeval current_time;
	if(gettimeofday(&current_time, NULL))
		return -1;
	time = ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
	return (time);
}

void	*check_death(void *ptr)
{
	t_philos *philo;
	
	philo = (t_philos *)ptr;
	while(1)
	{
		if(get_time() > (philo->last_meal + philo->data->to_die))
		{
			message('d', philo);
			break;
		}
	
	}
	return (NULL);
}

void	*routine(void *tmp)
{
	t_philos *philo;
	int		count;
	
	count = 0;
	philo = (t_philos *)tmp;
	philo->last_meal = get_time();
	pthread_create(&philo->data->check, NULL, &check_death, tmp);
	pthread_detach(philo->data->check);
	while (1)
	{
		philo->last_meal = get_time();
		pthread_mutex_lock(&philo->data->fork[philo->index - 1]);
		pthread_mutex_lock(&philo->data->fork[(philo->index) % philo->data->numofphils]);
		message('f', philo);
		message('f', philo);
		message('e', philo);
		// printf("%ld [%d] has taken a \033[1;34mfork\e[0m\n", get_time(),philo->index);
		// printf("%ld [%d] has taken a \033[1;34mfork\e[0m\n", get_time(),philo->index);
		// printf("%ld [%d] is \033[1;34meating\e[0m\n",get_time() ,philo->index);
		philo->eat_times--;
		usleep(philo->data->to_eat * 1000);
		pthread_mutex_unlock(&philo->data->fork[philo->index - 1]);
		pthread_mutex_unlock(&philo->data->fork[(philo->index) % philo->data->numofphils]);
		// if(philo->eat_times == 0)
		// {
		// 	count++;
		// 	break;
		// }
		philo->last_meal = get_time();
		message('s', philo);
		// printf("%ld [%d] is \033[1;34msleeping\e[0m\n", get_time(),philo->index);
		usleep(philo->data->to_sleep * 1000);
		message('t', philo);
		// printf("%ld [%d] is \033[1;34mthinking\e[0m\n", get_time(),philo->index);
	}
	// printf("\033[1;32mall philosophers ate their meals\e[0m\n");
	// pthread_mutex_unlock(&philo->data->program);
	return NULL;
}
int	execute(t_philos *philos)
{
	int i = 0;

	pthread_t *philo;
	int count;

	pthread_mutex_init(&philos->data->program, NULL);
	pthread_mutex_init(&philos->data->msg, NULL);
	count = 0;
	philo = malloc(sizeof(pthread_t) * philos->data->numofphils);
	i = -1;
	while(++i < philos->data->numofphils)
		pthread_create(&philo[i], NULL, &routine, &philos[i]);
	pthread_mutex_lock(&philos->data->program);
	i = -1;
	while(++i < philos->data->numofphils)
		pthread_detach(philo[i]);
	pthread_mutex_lock(&philos->data->program);
	// pthread_mutex_unlock(&philos->data->program);
	i = -1;
	while(++i < philos->data->numofphils)
		pthread_mutex_destroy(&philos->data->fork[i]);
	i = -1;
	return (0);
}