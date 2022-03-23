#	ifndef INCLUDES_H
# define INCLUDES_H

#define MAX_INT 2147483647
#define MIN_INT -2147483648

#include <stdio.h>

typedef struct s_data
{
    int philos;
    int to_die;
    int to_eat;
    int to_sleep;
    int eat_times;
	
} t_data;

int	ft_atoi(const char *str);
int	parcing(char **av, t_data *ptr);


#	endif