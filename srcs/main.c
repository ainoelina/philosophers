/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 07:41:21 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/27 10:33:06 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** change return values and create error function
** make clear_all function
*/

/*
** main function checks for the number of arguments and mallocs memory for
** the main struct. then it initialises the rules and calls the threading
** function. errors are handled in a separate error -function.
*/

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc < 5 || argc > 6)
		return (error("wrong number of arguments", NULL));
	if (!memset(&rules, 0, sizeof(t_rules)))
		return (error("mallocing failed", &rules));
	if (init_rules(&rules, argv, argc))
		return (error("initialising failed", &rules));
	if (threading(&rules, rules.philo))
		return (error("threading failed", &rules));
	return (0);
}
