/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 11:27:02 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/12 14:12:34 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_rules
{
	int				nb;
	int				eat_time;
	int				die_time;
	int				sleep_time;
	int				eat_nb;
	pthread_mutex_t	forks[250];
	struct s_philo	philo[250];
}				t_rules;

typedef struct s_philo
{
	pthread_t		thread;
	struct s_rules	*rules;
	int				fork_left;
	int				fork_right;
	int				id;
	int				full;
	long long		last_ate;
}				t_philo;

/* ------------ PARSER ----------- */

void	parser(t_rules *rules, int ac, char **av);

/* ------------ QUIT ------------- */
void	philo_error(char *message, t_rules *rules);

/* ------------ INITIALISE ------- */
void	init_rules(t_rules *rules, int ac, char **av);

/* ------------ UTILS ------------ */
int		my_atoi(char *str);
void	get_time(void);

/* ------------ PRINT TOOLS ------ */
void	print_rules(t_rules *rules);

#endif
