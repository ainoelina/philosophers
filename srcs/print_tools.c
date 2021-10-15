/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_tools.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 12:15:25 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/15 12:48:09 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_rules(t_rules *philo)
{
	printf(B_PINK "\n  PROGRAM RULES ARE:  \n" RESET);
	printf(B_ORANGE "  number of philosophers: %i\n" RESET, philo->nb);
	printf(B_ORANGE"  number of forks:        %i\n" RESET, philo->nb);
	printf(B_MINT "  time to die:            %ims\n" RESET, philo->die_time);
	printf(B_CORAL "  time to eat:            %ims\n" RESET, philo->eat_time);
	printf(B_YELLOW "  time to sleep:          %ims\n" RESET, philo->sleep_time);
	if (philo->eat_nb != -1)
		printf("\033[85;1m\033[38;5;111m  number times to eat:    %i \033[m\033[m\n", philo->eat_nb);
	printf("\n");
}
