/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threading.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 09:52:27 by avuorio       #+#    #+#                 */
/*   Updated: 2021/11/03 11:45:04 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_check(t_rules *rules, t_philo *philo)
{
	if (philo->meal_count > 0)
		rules->fed++;
	if (rules->fed == rules->eat_count * rules->nb)
	{
		rules->done = 1;
		log_status(rules, 0, FINISHED);
		return (1);
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_rules	*rules;

	philo = (t_philo *)arg;
	rules = philo->rules;
//	if (philo->id % 2)
//		usleep(15000);
	while (!rules->dead)
	{
		if (get_forks(rules, philo))
			break ;
		if (eat(rules, philo))
			break ;
		if (rules->done)
			break ;
		if (rules->eat_count > 0 && philo_check(rules, philo))
			break ;
		log_status(rules, philo->id, SLEEP);
		sleeper(rules->sleep_time);
		log_status(rules, philo->id, THINK);
	}
	return (NULL);
}

/*
** threading function creates
*/

void	check_death(t_rules *rules, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < rules->nb && !rules->dead)
	{
		pthread_mutex_lock(&rules->lock);
		if (get_time() - philo->last_ate > rules->die_time)
		{
			log_status(rules, i, DED);
			rules->dead = 1;
		}
		pthread_mutex_unlock(&rules->lock);
		usleep(50);
		i++;
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
		p->last_ate = get_time();
		usleep(1500);
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
