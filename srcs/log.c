/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   log.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 11:22:37 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/15 11:22:30 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_log(t_rules *rules, int status, int id)
{
	long long	time;

	time = get_time() - rules->start;
	if (status == EAT)
		printf("%lli Philosopher %i is eating\n", time, id + 1);
	else if (status == SLEEP)
		printf("%lli Philosopher %i is sleeping\n", time, id + 1);
	else if (status == THINK)
		printf("%lli Philosopher %i is thinking\n", time, id + 1);
	else if (status == DED)
		printf ("%lli Philosopher %i had died\n", time, id + 1);
	else if (status == FORK)
		printf ("%lli Philosopher %i has taken a fork\n", time, id + 1);
	else if (status == FINISHED)
		printf ("%lli All philosophers have been fed\n", time);
	return (0);
}

void	log_status(t_rules *rules, int id, int status)
{
//	if (pthread_mutex_lock(&rules->log))
//		philo_error("Error: mutex lock failed.\n", rules);
	print_log(rules, status, id);
//	if (pthread_mutex_unlock(&rules->log))
//		philo_error("aaa Error: mutex lock failed.\n", rules);
}
