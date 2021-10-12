/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 11:21:58 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/12 11:29:15 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	printf("%ld\n", (time.tv_sec * 1000 + time.tv_usec / 1000));
}
