/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:51:23 by kel-amra          #+#    #+#             */
/*   Updated: 2022/04/12 02:59:28 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int main(int ac, char **av)
{
	t_data tmp = (t_data){0};
	t_philos *philos = NULL;
	if(ac != 5 && ac != 6)
		return(printf("Error: to few arguments\n"),2);
	tmp.current_time = get_time();
	if(tmp.current_time == -1)
		return (printf("Error: can't get current time"),2);
	philos = parsing(++av, &tmp);
	if(!philos)
		return(printf("Error: invalid arguments\n"),2);
	execute(philos);
	// while(++i < tmp.numofphils)
	// {
	// 	printf("%ld Philosopher[%d] : %d %d %d\n", tmp.current_time  , tmp.philos[i].to_die, tmp.philos[i].to_eat,tmp.philos[i].to_sleep, tmp.philos[i].eat_times);
	// }
	// free(ptr);
	// printf("%d  %d  %d  %d\n", ptr.to_die, ptr.to_eat, ptr.to_sleep, ptr.eat_times);
	// while()
	// while(++i < ptr.numofphil)
	// 	printf("%d\n",ptr.philos[i]);
	
}