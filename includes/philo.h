/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 11:27:02 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/12 11:00:00 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_philo
{
	int			nb;
	int			eat_time;
	int			die_time;
	int			sleep_time;
	int			eat_nb;
	pthread_t	id;
}				t_philo;

/* ------------ PARSER ----------- */

void	parser(t_philo *philo, int ac, char **av);

/* ------------ QUIT ------------- */
void	philo_error(char *message, t_philo *philo);

/* ------------ INITIALISE ------- */
t_philo	*init_philo(t_philo *philo);

/* ------------ UTILS ------------ */
int		my_atoi(char *str);
int		str_len(char *str);

/* ------------ PRINT TOOLS ------ */
void	print_rules(t_philo *philo);

#endif
