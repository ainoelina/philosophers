/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 09:56:52 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/19 12:59:58 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arguments(t_rules *rules)
{
	if (rules->nb > 250 || rules->nb < 2 || rules->eat_time < 0
		|| rules->die_time < 0 || rules->sleep_time < 0)
		return (1);
	return (0);
}

/*
** initialising of philosophers is done in a loop that runs as many times
** as there are philosophers.
*/

int	init_philosophers(t_rules *rules)
{
	int	i;

	i = 0;
	rules->philo = malloc(sizeof(t_rules) * rules->nb);
	if (!rules->philo)
		return (1);
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->nb);
	if (!rules->forks)
		return (1);
	while (i < rules->nb)
	{
		rules->philo[i].id = i;
		rules->philo[i].full = 0;
		rules->philo[i].meal_count = 0;
		rules->philo[i].last_ate = 0;
		rules->philo[i].fork_left = i;
		rules->philo[i].fork_right = (i + 1) % rules->nb;
		rules->philo[i].rules = rules;
		i++;
	}
	return (0);
}

/*
** init_mutex initialises mutexes for forks and writing of status.
*/

int	init_mutex(t_rules *rules)
{
	int	i;

	i = 0;
	while (i <= rules->nb)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(rules->log), NULL))
		return (1);
	if (pthread_mutex_init(&(rules->meal), NULL))
		return (1);
	return (0);
}

/*
** init_rules gets the input from arguments given to the program.
** next it checks for the validity of input, and initialises
** philosophers and mutexes.
*/

int	init_rules(t_rules *rules, int ac, char **av)
{
	rules->nb = my_atoi(av[1]);
	rules->die_time = my_atoi(av[2]);
	rules->eat_time = my_atoi(av[3]);
	rules->sleep_time = my_atoi(av[4]);
	rules->start = 0;
	rules->done = 0;
	rules->dead = 0;
	if (ac == 6)
	{
		rules->eat_nb = my_atoi(av[5]);
		if (rules->eat_nb <= 0)
			return (philo_error("Error: argument input invalid.\n", rules));
	}
	else
		rules->eat_nb = -1;
	if (check_arguments(rules))
		return (philo_error("Error: argument input invalid.\n", rules));
	if (init_philosophers(rules))
		return (philo_error("Error: malloc failed.\n", rules));
	if (init_mutex(rules))
		return (philo_error("Error: mutex initialisation failed.\n", rules));
	return (0);
}
