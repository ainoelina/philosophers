/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 11:44:43 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/12 10:07:05 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;

	philo = NULL;
	philo = init_philo(philo);
	if (ac < 2)
		write(1, "Error: too few arguments.\n", 27);
	parser(philo, ac, av);
	return (0);
}
