/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 10:00:26 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/15 10:42:52 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_error(char *message, t_rules *rules)
{
	printf("%s\n", message);
	rules = NULL;
	return (1);
}

void	exit_program(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb)
	{
		pthread_join(rules->philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < rules->nb)
	{
		pthread_mutex_destroy(&(rules->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(rules->log));
}
