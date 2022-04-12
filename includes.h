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
    int to_die;
    int numofphils;
    int to_eat;
    int to_sleep;
    int eat_times;
    long current_time;
    pthread_mutex_t *fork;
} t_data;

typedef struct s_philos
{
    t_data *data;
    int index;
    long die_time;
}   t_philos;

long	get_time(void);
int	execute(t_philos *philos);
int	ft_atoi(const char *str);
t_philos	*parsing(char **av, t_data *tmp);


#	endif