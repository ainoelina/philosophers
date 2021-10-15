/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 08:29:31 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/15 12:11:00 by avuorio       ########   odam.nl         */
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
	if (pthread_mutex_lock(&rules->forks[philo->fork_left]) == -1)
		philo_error("Error: mutex lock failed.\n", rules);
	log_status(rules, philo->id, FORK);
//	printf("-----fork is %i\n", philo->fork_left + 1);
	if (pthread_mutex_lock(&rules->forks[philo->fork_right]) == -1)
		philo_error("Error: mutex lock failed.\n", rules);
	log_status(rules, philo->id, FORK);
//	printf("-----fork is %i\n", philo->fork_right + 1);
	log_status(rules, philo->id, EAT);
	philo->last_ate = get_time();
	timer(rules->eat_time, rules);
	philo->meal_count++;
	pthread_mutex_unlock(&(rules->forks[philo->fork_left]));
//	printf("~~~~~~~ fork nr %i unlocked\n", philo->fork_left);
	pthread_mutex_unlock(&(rules->forks[philo->fork_right]));
//	printf("~~~~~~~ fork nr %i unlocked\n", philo->fork_right);
}
