/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:51:23 by kel-amra          #+#    #+#             */
/*   Updated: 2022/03/23 20:32:37 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int main(int ac, char **av)
{
	t_data ptr;
	if(ac != 5 && ac != 6)
		return(printf("Error: to few arguments\n"),2);
	if(parcing(++av,&ptr) == 1)
		return(printf("Error: invalid arguments\n"),2);
}