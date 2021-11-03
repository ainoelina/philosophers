/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 11:58:35 by avuorio       #+#    #+#                 */
/*   Updated: 2021/11/03 13:41:33 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeper(long long duration)
{
	long long	time;
	long long	temp;

	time = get_time() + duration;
	temp = 0;
	while (temp < time)
	{
		temp = get_time();
		usleep(50);
	}
}

int	get_forks(t_rules *rules, t_philo *philo)
{
	if (pthread_mutex_lock(&rules->forks[philo->fork_left]))
		return (1);
	log_status(rules, philo->id, FORK);
	if (pthread_mutex_lock(&rules->forks[philo->fork_right]))
		return (1);
	log_status(rules, philo->id, FORK);
	return (0);
}

int	eat(t_rules *rules, t_philo *philo)
{
	if (pthread_mutex_lock(&rules->lock))
		return (1);
	log_status(rules, philo->id, EAT);
	philo->last_ate = get_time();
	if (pthread_mutex_unlock(&rules->lock))
		return (1);
	sleeper(rules->eat_time);
	philo->meal_count++;
	if (pthread_mutex_unlock(&rules->forks[philo->fork_left]))
		return (1);
	if (pthread_mutex_unlock(&rules->forks[philo->fork_right]))
		return (1);
	return (0);
}
