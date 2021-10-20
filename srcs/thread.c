/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thread.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 09:40:53 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/20 14:57:26 by avuorio       ########   odam.nl         */
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
		if (rules->done)
			break ;
		go_to_sleep(rules, philo);
		log_status(rules, philo->id, THINK);
	}
	return (NULL);
}

void	check_death(t_philo *philo, t_rules *rules)
{

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
