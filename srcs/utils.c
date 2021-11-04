/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 07:57:49 by avuorio       #+#    #+#                 */
/*   Updated: 2021/11/03 14:58:09 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		current_time;

	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	my_atoi(char *str)
{
	long long	nb;
	int			sign;
	int			index;

	if (!str)
		return (0);
	sign = 1;
	index = 0;
	while (str[index] == ' ')
		index++;
	if (str[index] == '-')
		sign = -1;
	if (str[index] == '-' || str[index] == '+')
		index++;
	nb = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		nb = nb * 10 + (str[index] - '0');
		index++;
	}
	nb = nb * sign;
	if (nb < -2147483648 || nb > 2147483647)
		return (-1);
	return ((int)nb);
}
