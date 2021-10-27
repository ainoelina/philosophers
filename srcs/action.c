/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 11:58:35 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/27 14:23:32 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	usleep(rules->eat_time * 1000);
	if (pthread_mutex_unlock(&rules->lock))
		return (1);
	philo->meal_count++;
	if (pthread_mutex_unlock(&rules->forks[philo->fork_left]))
		return (1);
	if (pthread_mutex_unlock(&rules->forks[philo->fork_right]))
		return (1);
	return (0);
}
