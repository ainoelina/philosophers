/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thread.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 09:40:53 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/20 14:47:38 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*new_thread(void *arg)
{
	t_philo	*philo;
	t_rules	*rules;

	philo = (t_philo *)arg;
	rules = philo->rules;
	if (philo->id % 2)
		usleep(15000);
	while (rules->dead == 0)
	{
		take_forks(rules, philo);
		eat(philo, rules);
		go_to_sleep(rules, philo);
		log_status(rules, philo->id, THINK);
	}
	return (NULL);
}

long long	time_diff(long long past, long long present)
{
	return (present - past);
}

void	check_death(t_philo *philo, t_rules *rules)
{
	int	i;
	long long diff;

	while (!(rules->done))
	{
		i = 0;
		while (i < rules->nb && !(rules->dead))
		{
			pthread_mutex_lock(&philo->lock);
			diff = get_time() - philo[i].last_ate;
			if (diff > rules->die_time)
			{
				log_status(rules, i, DED);
				rules->dead = 1;
			}
			pthread_mutex_unlock(&philo->lock);
			usleep(100);
			i++;
		}
		if (rules->dead == 1)
			break ;
		while (rules->eat_count != -1 && i < rules->nb && philo[i].meal_count >= rules->eat_count)
			i++;
		if (i == rules->nb)
			rules->done = 1;
	}
}

void	start_threads(t_rules *rules)
{
	t_philo	*philo;
	int		i;

	rules->start = get_time();
	i = 0;
	philo = rules->philo;
	while (i < rules->nb)
	{
		if (pthread_create(&philo[i].thread, NULL, new_thread, &philo[i]))
			philo_error("Error: thread creation failed.\n", rules);
		philo[i].last_ate = get_time();
		i++;
	}
	check_death(rules->philo, rules);
	exit_program(rules);
}
