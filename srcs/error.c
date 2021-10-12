/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 10:00:26 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/12 13:56:46 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_error(char *message, t_rules *rules)
{
	int	len;

	len = 0;
	while (message[len])
		len++;
	write(1, message, len);
	rules = NULL;
}
