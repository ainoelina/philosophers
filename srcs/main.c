/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 11:44:43 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/12 14:02:20 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_rules	rules;

	if (ac < 2)
		write(1, "Error: too few arguments.\n", 27);
	init_rules(&rules, ac, av);
	print_rules(&rules);
//	system("leaks philo");
	return (0);
}
