/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threading.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 09:52:27 by avuorio       #+#    #+#                 */
/*   Updated: 2021/11/02 07:33:35 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_check(t_rules *rules, t_philo *philo)
{
	if (philo->meal_count > 0)
		rules->fed++;
	if (rules->fed == rules->eat_count * rules->nb)
		return (1);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_rules	*rules;

	philo = (t_philo *)arg;
	rules = philo->rules;
	if (philo->id % 2)
		usleep(15000);
	while (!rules->done)
	{
		if (get_forks(rules, philo))
			break ;
		if (eat(rules, philo))
			break ;
		if (rules->eat_count > 0 && philo_check(rules, philo))
		{
			rules->done = 1;
			log_status(rules, 0, FINISHED);
			break ;
		}
		log_status(rules, philo->id, SLEEP);
		sleeper(rules->sleep_time);
		log_status(rules, philo->id, THINK);
	}
	return (NULL);
}

/*
** threading function creates
*/

int	threading(t_rules *rules, t_philo *philo)
{
	int	i;

	i = 0;
	rules->start = get_time();
	while (i < rules->nb)
	{
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]))
			return (error("thread creation failed", rules));
		i++;
	}
	i = 0;
	while (i < rules->nb)
	{
		if (pthread_join(philo[i].thread, NULL))
			return (error("thread join failed", rules));
		i++;
	}
	delete_mutex(rules);
	return (0);
}
