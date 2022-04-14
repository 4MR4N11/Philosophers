/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:51:23 by kel-amra          #+#    #+#             */
/*   Updated: 2022/04/14 00:34:26 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int main(int ac, char **av)
{
	t_data tmp = (t_data){0};
	t_philos *philos = NULL;
	if(ac != 5 && ac != 6)
		return(printf("Error: to few arguments\n"),2);
	philos = parsing(++av, &tmp);
	if(!philos)
		return(printf("Error: invalid arguments\n"),2);
	execute(philos);
}