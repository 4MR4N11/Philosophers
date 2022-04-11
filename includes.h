#	ifndef INCLUDES_H
# define INCLUDES_H

#define MAX_INT 2147483647
#define MIN_INT -2147483648

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_philos
{
    int fork[2];
    int index;
    int to_die;
    int to_eat;
    int to_sleep;
    int eat_times;
} t_philos;

typedef struct s_data
{
    t_philos *philos;
    int forks;
    long current_time;
    int numofphils;
    long die_time;
}   t_data;

long	get_time(void);
int	execute(t_data *tmp);
int	ft_atoi(const char *str);
int    parsing(char **av, t_data *tmp);


#	endif