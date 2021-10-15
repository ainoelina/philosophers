/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thread.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 09:40:53 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/15 12:16:33 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*new_thread(void *arg)
{
	t_philo	*p_i;
	t_rules	*rules;

	p_i = (t_philo *)arg;
	rules = p_i->rules;
	while (rules->dead == 0)
	{
		eat(p_i, rules);
		if (rules->done)
			break ;
		log_status(rules, p_i->id, SLEEP);
		timer(rules->sleep_time, rules);
		log_status(rules, p_i->id, THINK);
	}
	// pthread_mutex_unlock(&(rules->forks[p_i->fork_left]));
	// printf("~~~~~~~ fork nr %i unlocked\n", p_i->fork_left);
	// pthread_mutex_unlock(&(rules->forks[p_i->fork_right]));
	// printf("~~~~~~~ fork nr %i unlocked\n", p_i->fork_right);
	return (NULL);
}

void	check_death(t_philo *philo, t_rules *rules)
{
	int	i;

	while (!(rules->done))
	{
		i = 0;
		while (i < rules->nb && !(rules->dead))
		{
			pthread_mutex_lock(&rules->meal);
			if ((get_time() - philo[i].last_ate) > rules->die_time)
			{
				log_status(rules, i, DED);
				rules->dead = 1;
			}
			pthread_mutex_unlock(&rules->meal);
			usleep(100);
			i++;
		}
		if (rules->dead == 1)
			break ;
		while (rules->eat_nb != -1 && i < rules->nb && philo[i].meal_count >= rules->eat_nb)
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
		if (pthread_create(&(philo[i].thread), NULL, new_thread, &(philo[i])))
			philo_error("Error: thread creation failed.\n", rules);
		philo[i].last_ate = get_time();
		i++;
	}
	check_death(rules->philo, rules);
	exit_program(rules);
}
