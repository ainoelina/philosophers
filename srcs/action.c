/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 08:29:31 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/19 13:16:39 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	timer(long long duration, t_rules *rules)
{
	long long	time1;

	time1 = get_time();
	while (!rules->dead)
	{
		if ((get_time() - time1) >= duration)
			break ;
		usleep(50);
	}
}

void	eat(t_philo *philo, t_rules *rules)
{
	pthread_mutex_lock(&rules->forks[philo->fork_left]);
	log_status(rules, philo->id, FORK);
	pthread_mutex_lock(&rules->forks[philo->fork_right]);
	log_status(rules, philo->id, FORK);
	pthread_mutex_lock(&rules->meal);
	log_status(rules, philo->id, EAT);
	philo->last_ate = get_time();
	pthread_mutex_unlock(&rules->meal);
	timer(rules->eat_time, rules);
	philo->meal_count++;
	pthread_mutex_unlock(&(rules->forks[philo->fork_left]));
	pthread_mutex_unlock(&(rules->forks[philo->fork_right]));
}
