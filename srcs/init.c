/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 09:56:52 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/12 13:58:44 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_arguments(t_rules *rules)
{
	if (rules->nb > 250 || rules->eat_time < 0 || rules->die_time < 0
		|| rules->sleep_time < 0 || rules->nb < 2)
		philo_error("Error: argument input incorrect.\n", rules);
}

void	init_rules(t_rules *rules, int ac, char **av)
{
	rules->nb = my_atoi(av[1]);
	rules->die_time = my_atoi(av[2]);
	rules->eat_time = my_atoi(av[3]);
	rules->sleep_time = my_atoi(av[4]);
	if (ac == 6)
	{
		rules->eat_nb = my_atoi(av[5]);
		if (rules->eat_nb <= 0)
			philo_error("Error: argument input incorrect.\n", rules);
	}
	check_arguments(rules);
}
