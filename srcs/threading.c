/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threading.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 09:52:27 by avuorio       #+#    #+#                 */
/*   Updated: 2021/11/04 10:40:30 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	t_rules	*rules;

	philo = (t_philo *)arg;
	rules = philo->rules;
	while (!rules->dead)
	{
		if (get_forks(rules, philo))
			break ;
		if (eat(rules, philo))
			break ;
		if (rules->done)
			break ;
		log_status(rules, philo->id, SLEEP);
		sleeper(rules->sleep_time);
		log_status(rules, philo->id, THINK);
	}
	return (NULL);
}

void	check_philo(t_rules *rules, t_philo *philo, int i)
{
	if (get_time() - philo[i].last_ate > rules->die_time)
	{
		log_status(rules, i, DED);
		rules->dead = 1;
	}
}

void	check_death(t_rules *rules, t_philo *philo)
{
	int	i;

	i = 0;
	while (!rules->done)
	{
		while (i < rules->nb && !rules->dead)
		{
			pthread_mutex_lock(&rules->lock);
			check_philo(rules, philo, i);
			pthread_mutex_unlock(&rules->lock);
			usleep(100);
			i++;
		}
		if (rules->dead)
			break ;
		i = 0;
		while (rules->eat_count != -1 && i < rules->nb
			&& philo[i].meal_count >= rules->eat_count)
			i++;
		if (i == rules->nb)
		{	
			log_status(rules, 0, FINISHED);
			rules->done = 1;
		}
	}
}

int	threading(t_rules *rules, t_philo *p)
{
	int			i;

	i = 0;
	rules->start = get_time();
	while (i < rules->nb)
	{
		if (pthread_create(&p[i].thread, NULL, routine, &p[i]))
			return (error("thread creation failed", rules));
		p[i].last_ate = get_time();
		usleep(1000);
		i++;
	}
	check_death(rules, p);
	i = 0;
	while (i < rules->nb)
	{
		if (pthread_join(p[i].thread, NULL))
			return (error("thread join failed", rules));
		i++;
	}
	delete_mutex(rules);
	return (0);
}
