#	ifndef INCLUDES_H
# define INCLUDES_H

#define MAX_INT 2147483647
#define MIN_INT -2147483648

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

typedef struct s_philos
{
    int to_die;
    int to_eat;
    int to_sleep;
    int eat_times;
} t_philos;

typedef struct s_data
{
    int numofphils;
}   t_data;

int	ft_atoi(const char *str);
t_philos	*parsing(char **av, t_data *tmp);


#	endif