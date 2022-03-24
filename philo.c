/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:51:23 by kel-amra          #+#    #+#             */
/*   Updated: 2022/03/24 20:42:34 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int main(int ac, char **av)
{
	t_philos *ptr;
	t_data tmp;
	int i = -1;
	if(ac != 5 && ac != 6)
		return(printf("Error: to few arguments\n"),2);
	ptr = parsing(++av, &tmp);
	if(ptr == NULL)
		return(printf("Error: invalid arguments\n"),2);
	while(++i < 5)
	{
		printf("%d %d %d %d\n", ptr[i].to_die, ptr[i].to_eat,ptr[i].to_sleep, ptr[i].eat_times);
	}
	// printf("%d  %d  %d  %d\n", ptr.to_die, ptr.to_eat, ptr.to_sleep, ptr.eat_times);
	// while()
	// while(++i < ptr.numofphil)
	// 	printf("%d\n",ptr.philos[i]);
	
}