/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:26:55 by kel-amra          #+#    #+#             */
/*   Updated: 2022/03/24 20:45:29 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include <unistd.h>

// void	get_time(t_data *ptr)
// {
	
// }
static	int	args_checker(char **av)
{
	int	i;

	i = -1;
	while(av[++i])
	{
		if(ft_atoi(av[i]) <= 0)
			return (1);
	}
	return (0);
}

t_philos	*parsing(char **av, t_data *tmp)
{
	t_philos *ptr;
	int i;

	if(args_checker(av))
		return (NULL);
	tmp->numofphils = ft_atoi(av[0]);
	if(tmp->numofphils <= 0)
		return (NULL);
	ptr = malloc(sizeof(t_philos) * tmp->numofphils);
	if(!ptr)
		return (NULL);
	i = 0;	
	while(i < tmp->numofphils)
	{
		ptr[i].to_die = ft_atoi(av[0]);
		ptr[i].to_eat = ft_atoi(av[1]);
		ptr[i].to_sleep = ft_atoi(av[2]);
		if(av[3])
			ptr[i].eat_times = ft_atoi(av[3]);
		i++;
	}
	return (ptr);
}