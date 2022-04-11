/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:51:23 by kel-amra          #+#    #+#             */
/*   Updated: 2022/04/11 02:34:37 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int main(int ac, char **av)
{
	t_data tmp;
	int i = -1;
	if(ac != 5 && ac != 6)
		return(printf("Error: to few arguments\n"),2);
	if(parsing(++av, &tmp))
		return(printf("Error: invalid arguments\n"),2);
	tmp.current_time = get_time();
	if(tmp.current_time == -1)
		return (printf("Error: can't get current time"),2);
	if(tmp.philos == NULL)
		return(printf("Error: invalid arguments\n"),2);
	while(++i < tmp.numofphils)
	{
		printf("%ld Philosopher[%d] : %d %d %d %d\n", tmp.current_time ,tmp.philos[i].index , tmp.philos[i].to_die, tmp.philos[i].to_eat,tmp.philos[i].to_sleep, tmp.philos[i].eat_times);
	}
	execute(&tmp);
	// free(ptr);
	// printf("%d  %d  %d  %d\n", ptr.to_die, ptr.to_eat, ptr.to_sleep, ptr.eat_times);
	// while()
	// while(++i < ptr.numofphil)
	// 	printf("%d\n",ptr.philos[i]);
	
}