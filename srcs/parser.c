/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 11:50:15 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/06 12:18:26 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parser(t_philo *philo, int ac, char **av)
{
	philo->nb = my_atoi(av[1]);
	philo->die_time = my_atoi(av[2]);
	philo->eat_time = my_atoi(av[3]);
	philo->sleep_time = my_atoi(av[4]);
	if (ac == 6)
		philo->eat_nb = my_atoi(av[5]);
	print_rules(philo);
}
