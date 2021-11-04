/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   log.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 12:05:45 by avuorio       #+#    #+#                 */
/*   Updated: 2021/11/04 11:39:42 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_status(t_rules *rules, int id, int status)
{
	long long	stamp;

	pthread_mutex_lock(&rules->log);
	stamp = get_time() - rules->start;
	if (rules->done == 0 && rules->dead == 0)
	{
		if (status == FORK)
			printf("%-8lli Philosopher %i has taken a fork\n", stamp, id + 1);
		if (status == EAT)
			printf("%-8lli Philosopher %i is eating\n", stamp, id + 1);
		if (status == SLEEP)
			printf("%-8lli Philosopher %i is sleeping\n", stamp, id + 1);
		if (status == THINK)
			printf("%-8lli Philosopher %i is thinking\n", stamp, id + 1);
	}
	if (status == DED)
		printf("%-8lli " RED "Philosopher %i died\n" RESET, stamp, id + 1);
	if (status == FINISHED && rules->dead == 0)
		printf("%-8lli " GREEN "All philosophers have been fed %i times.\n"
			RESET, stamp, rules->eat_count);
	pthread_mutex_unlock(&rules->log);
}
