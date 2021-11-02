/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 08:06:40 by avuorio       #+#    #+#                 */
/*   Updated: 2021/11/02 11:54:27 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** delete unnecessary printf statements 
** fix freeing part of error function
** or ACTUALLY make a separate clear -function
*/

int	delete_mutex(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb)
	{
		printf(B_GREEN "mutex nro %i destroyed\n" RESET, i + 1);
		if (pthread_mutex_destroy(&rules->forks[i]))
			return (1);
		i++;
	}
	if (pthread_mutex_destroy(&rules->log))
		return (1);
	return (0);
}

int	free_all(t_rules *rules)
{
	if (!rules)
		return (0);
	if (rules->forks)
		free (rules->forks);
	if (rules->philo)
		free (rules->philo);
	return (1);
}

int	error(char *message, t_rules *rules)
{
	printf(B_RED "Error: " RESET);
	printf(ITALIC "%s\n" RESET, message);
	free_all(rules);
	return (1);
}
