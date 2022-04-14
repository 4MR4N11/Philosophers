/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:22:00 by kel-amra          #+#    #+#             */
/*   Updated: 2022/04/14 23:27:02 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef INCLUDES_H
# define INCLUDES_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_data
{
	long			to_die;
	int				status;
	int				meals_count;
	pthread_mutex_t	program;
	pthread_mutex_t	meals;
	pthread_mutex_t	tmp;
	pthread_mutex_t	msg;
	int				philo_n;
	int				to_eat;
	int				to_sleep;
	pthread_t		check;
	pthread_mutex_t	*fork;
}	t_data;

typedef struct s_philos
{
	t_data	*data;
	int		index;
	int		is_eating;
	int		numofmeals;
	long	last_meal;
}	t_philos;

void		message(char msg, t_philos *philo);
long		get_time(void);
int			execute(t_philos *philos);
void		free_data(t_philos	*data, pthread_t *philos_t);
int			ft_atoi(const char *str);
t_philos	*parsing(char **av, t_data *tmp);
void		meals_checker(t_philos *philos);
void		*routine_caller(void *tmp);
void		*check_death(void *ptr);
int			ft_isdigit(int c);
int			get_data(char **av, t_data *tmp);

#	endif