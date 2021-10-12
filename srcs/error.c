/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 10:00:26 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/12 10:14:32 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_error(char *message, t_philo *philo)
{
	write(1, message, str_len(message));
	free(philo);
}
