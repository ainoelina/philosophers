/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 07:55:28 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/20 13:55:44 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** change return (1) to free-er function.
*/

void	meal(t_rules *rules, t_philo *philo)
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

void	get_forks(t_rules *rules, t_philo *philo)
{
	pthread_mutex_lock(&rules->forks[philo->fork_left]);
	log_status(rules, philo->id, FORK);
	pthread_mutex_lock(&rules->forks[philo->fork_right]);
	log_status(rules, philo->id, FORK);
}

void	free_forks(t_rules *rules, t_philo *philo)
{
	log_status(rules, philo->id, SLEEP);
	pthread_mutex_unlock(&rules->forks[philo->fork_left]);
	pthread_mutex_unlock(&rules->forks[philo->fork_right]);
	usleep(rules->sleep_time * 1000);
}

void	*routine(void *arg)
{
	t_rules	*rules;
	t_philo	*philo;

	philo = (t_philo *)arg;
	rules = philo->rules;
//	printf("%i philosophers, thread %i\n", rules->nb, philo->id + 1);
	while (rules->dead == 0)
	{
		get_forks(rules, philo);
		meal(rules, philo);
		free_forks(rules, philo);
		log_status(rules, philo->id, THINK);
	}
	return (0);
}

void	checker(t_rules *rules)
{
	printf("rules %i\n", rules->nb);

}

int	starter(t_rules *rules)
{
	t_philo	*philo;
	int		i;

	rules->start = get_time();
	philo = rules->philo;
	i = 0;
	printf("start time %lli\n", philo->rules->start - get_time());
	while (i < rules->nb)
	{
		pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < rules->nb)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	checker(rules);
//	free(philo);
	return (0);
}

int	main(int ac, char **av)
{
	t_rules	rules;

	if (ac < 5 || ac > 6)
		printf("Error: wrong number of arguments\n");
	if (init_rules(&rules, ac, av))
		return (1);
//	print_rules(&rules);
//	starter(&rules);
	start_threads(&rules);
//	system("leaks philo");
	return (0);
}
