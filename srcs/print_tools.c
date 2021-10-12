/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_tools.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 12:15:25 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/06 12:42:01 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_rules(t_philo *philo)
{
	printf("\033[85;1m\033[38;5;178m  PROGRAM RULES ARE:  \033[m\033[m\n\n");
	printf("\033[85;1m\033[38;5;209m  number of philosophers: %i \033[m\033[m\n", philo->nb);
	printf("\033[85;1m\033[38;5;209m  number of forks:        %i \033[m\033[m\n", philo->nb);
	printf("\033[85;1m\033[38;5;106m  time to die:            %ims \033[m\033[m\n", philo->die_time);
	printf("\033[85;1m\033[38;5;106m  time to eat:            %ims \033[m\033[m\n", philo->eat_time);
	printf("\033[85;1m\033[38;5;106m  time to sleep:          %ims \033[m\033[m\n", philo->sleep_time);
	if (philo->eat_nb != 0)
		printf("\033[85;1m\033[38;5;111m  number times to eat:    %i \033[m\033[m\n", philo->eat_nb);
	printf("\n");
}
