/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:16:54 by kel-amra          #+#    #+#             */
/*   Updated: 2022/04/11 02:42:20 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static void	*eat()
{
	int i = 0;
	pthread_mutex_t tmp;
	pthread_mutex_lock(&tmp);
	usleep(10000000);
	printf("%d",i);
	i++;
	pthread_mutex_unlock(&tmp);
	return NULL;
}
int	execute(t_data *tmp)
{
	int i = 0;
	pthread_t philos;
	tmp->die_time = (get_time() + tmp->philos[0].to_die);
	while(i < tmp->numofphils)
	{
		pthread_create(&philos, NULL, &eat, tmp);
		i++;
	}
	pthread_join(philos, NULL);
	return (0);
}