/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 09:56:52 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/12 10:14:30 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(t_philo *philo)
{
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		philo_error("Error: malloc fail.\n", philo);
	philo->die_time = 0;
	philo->eat_time = 0;
	philo->sleep_time = 0;
	philo->eat_nb = 0;
	philo->id = NULL;
	philo->nb = 0;
	return (philo);
}
