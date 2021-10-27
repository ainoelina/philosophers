/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   log.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 12:05:45 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/27 14:26:10 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_status(t_rules *rules, int id, int status)
{
	long long	timestamp;

	pthread_mutex_lock(&rules->log);
	timestamp = get_time() - rules->start;
	if (rules->done == 0)
	{
		if (status == FORK)
			printf("%lli Philosopher %i has taken a fork\n", timestamp, id + 1);
		if (status == EAT)
			printf("%lli Philosopher %i is eating\n", timestamp, id + 1);
		if (status == SLEEP)
			printf("%lli Philosopher %i is sleeping\n", timestamp, id + 1);
		if (status == THINK)
			printf("%lli Philosopher %i is thinking\n", timestamp, id + 1);
		if (status == DED)
			printf("%lli Philosopher %i died\n", timestamp, id + 1);
	}
	if (status == FINISHED)
		printf("%lli All philosophers have been fed\n", timestamp);
	pthread_mutex_unlock(&rules->log);
}
