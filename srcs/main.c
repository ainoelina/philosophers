/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 07:55:28 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/15 11:09:46 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** change return (1) to free-er function.
*/

int	main(int ac, char **av)
{
	t_rules	rules;

	if (ac < 5 || ac > 6)
		printf("Error: wrong number of arguments\n");
	if (init_rules(&rules, ac, av))
		return (1);
	print_rules(&rules);
	start_threads(&rules);
	system("leaks philo");
	return (0);
}
