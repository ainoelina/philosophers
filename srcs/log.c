/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   log.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 12:05:45 by avuorio       #+#    #+#                 */
/*   Updated: 2021/11/03 14:28:16 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_status(t_rules *rules, int id, int status)
{
	long long	timestamp;

	pthread_mutex_lock(&rules->log);
	timestamp = get_time() - rules->start;
	if (rules->done == 0 && rules->dead == 0)
	{
		if (status == FORK)
			printf("%-8lli %i has taken a fork\n", timestamp, id + 1);
		if (status == EAT)
			printf("%-8lli %i is eating\n", timestamp, id + 1);
		if (status == SLEEP)
			printf("%-8lli %i is sleeping\n", timestamp, id + 1);
		if (status == THINK)
			printf("%-8lli %i is thinking\n", timestamp, id + 1);
	}
	if (status == DED)
		printf("%-8lli %i died\n", timestamp, id + 1);
	if (status == FINISHED && rules->dead == 0)
		printf("%-8lli All philosophers have been fed %i times\n", timestamp,
			rules->eat_count);
	pthread_mutex_unlock(&rules->log);
}
