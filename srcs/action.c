/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 08:29:31 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/20 14:48:58 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	go_to_sleep(t_rules *rules, t_philo *philo)
{
	pthread_mutex_unlock(&rules->forks[philo->fork_left]);
	pthread_mutex_unlock(&rules->forks[philo->fork_right]);
	log_status(rules, philo->id, SLEEP);
	usleep (rules->sleep_time * 1000);
}

void	take_forks(t_rules *rules, t_philo *philo)
{
	pthread_mutex_lock(&rules->forks[philo->fork_left]);
	log_status(rules, philo->id, FORK);
	pthread_mutex_lock(&rules->forks[philo->fork_right]);
	log_status(rules, philo->id, FORK);
}

void	eat(t_philo *philo, t_rules *rules)
{
	pthread_mutex_lock(&philo->lock);
	philo->last_ate = get_time();
	philo->eating_now = 1;
	log_status(rules, philo->id, EAT);
	usleep(rules->eat_time * 1000);
	philo->meal_count++;
	philo->eating_now = 0;
	pthread_mutex_unlock(&philo->lock);
}
