/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:51:23 by kel-amra          #+#    #+#             */
/*   Updated: 2022/04/14 23:29:02 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	main(int ac, char **av)
{
	t_data		tmp;
	t_philos	*philos;

	philos = NULL;
	tmp.fork = NULL;
	if (ac != 5 && ac != 6)
		return (printf("Error: to few arguments\n"), 2);
	philos = parsing(++av, &tmp);
	if (tmp.status == 2)
		return (0);
	if (!philos)
		return (printf("Error: invalid arguments\n"), 2);
	execute(philos);
	return (0);
}
