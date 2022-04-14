#	ifndef INCLUDES_H
# define INCLUDES_H

#define MAX_INT 2147483647
#define MIN_INT -2147483648

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_data
{
    long to_die;
    int meals_count;
    pthread_mutex_t program;
    pthread_mutex_t meals;
    pthread_mutex_t tmp;
    pthread_mutex_t msg;
    int philo_n;
    int to_eat;
    int to_sleep;
    pthread_t check;
    pthread_mutex_t *fork;
} t_data;

typedef struct s_philos
{
    t_data *data;
    int index;
    int is_eating;
    int numofmeals;
    long last_meal;
}   t_philos;

void    message(char msg, t_philos *philo);
long	get_time(void);
int	execute(t_philos *philos);
int	ft_atoi(const char *str);
t_philos	*parsing(char **av, t_data *tmp);
void    *check_death(void *ptr);


#	endif