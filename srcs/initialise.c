/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialise.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 07:52:34 by avuorio       #+#    #+#                 */
/*   Updated: 2021/11/03 11:11:43 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_rules(t_rules *rules, int ac)
{
	if (rules->nb > 250 || rules->nb < 2)
		return (1);
	if (rules->die_time < 0 || rules->eat_time < 0 || rules->sleep_time < 0)
		return (1);
	if (ac == 6 && rules->eat_count < 0)
		return (1);
	return (0);
}

int	init_mutex(t_rules *rules)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&rules->log, NULL))
		return (1);
	if (pthread_mutex_init(&rules->lock, NULL))
		return (1);
	while (i < rules->nb)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

int	init_philosophers(t_rules *rules)
{
	int	i;

	rules->philo = malloc(rules->nb * sizeof(t_rules));
	rules->forks = malloc(rules->nb * sizeof(pthread_mutex_t));
	if (!rules->philo || !rules->forks)
		return (2);
	i = 0;
	while (i < rules->nb)
	{
		rules->philo[i].rules = rules;
		rules->philo[i].id = i;
		rules->philo[i].last_ate = 0;
		rules->philo[i].meal_count = 0;
		rules->philo[i].fork_left = i;
		rules->philo[i].fork_right = (i + 1) % rules->nb;
		i++;
	}
	if (init_mutex(rules))
		return (1);
	return (0);
}

/*
** parsing the arguments in the rules -struct, checking for the validity of input
** and initialising the philosophers in separate function in a loop.
*/

int	init_rules(t_rules *rules, char **av, int ac)
{
	rules->nb = my_atoi(av[1]);
	rules->die_time = my_atoi(av[2]);
	rules->eat_time = my_atoi(av[3]);
	rules->sleep_time = my_atoi(av[4]);
	if (ac == 6)
		rules->eat_count = my_atoi(av[5]);
	else
		rules->eat_count = -1;
	if (check_rules(rules, ac))
		return (1);
	if (init_philosophers(rules))
		return (1);
	return (0);
}
