/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:51:23 by kel-amra          #+#    #+#             */
/*   Updated: 2022/04/15 22:12:31 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	main(int ac, char **av)
{
	t_data		tmp;
	t_philos	*philos;

	tmp.fork = NULL;
	if (ac != 5 && ac != 6)
		return (printf("Error: invalid arguments\n"), 2);
	tmp.status = 0;
	philos = parsing(++av, &tmp);
	if (tmp.status == 2)
		return (0);
	else if (tmp.status == 1)
		return (printf("Error: invalid arguments\n"), 2);
	else if (tmp.status != 0)
	{
		free(philos);
		free(tmp.fork);
		return (printf("Error: malloc\n"), 2);
	}
	if (execute(philos))
		return (printf("Error: malloc\n"), 2);
	free(philos);
	free(tmp.fork);
	return (0);
}
