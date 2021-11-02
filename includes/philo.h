/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 07:51:08 by avuorio       #+#    #+#                 */
/*   Updated: 2021/11/02 13:10:06 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>
# include "colours.h"

enum e_status {FORK, EAT, SLEEP, THINK, DED, FINISHED};

typedef struct s_philo
{
	pthread_t		thread;
	struct s_rules	*rules;
	int				fork_left;
	int				fork_right;
	int				id;
	int				meal_count;
	long long		last_ate;
	long long		time;
	pthread_mutex_t	lock;
}				t_philo;

typedef struct s_rules
{
	int				nb;
	int				eat_time;
	int				die_time;
	int				sleep_time;
	int				eat_count;
	int				fed;
	int				dead;
	int				done;
	long long		start;
	struct s_philo	*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	log;
	pthread_mutex_t	lock;
}				t_rules;

/* ~~~~~~~ INIT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
int			init_rules(t_rules *rules, char **av, int ac);

/* ~~~~~~~ PROGRAM ~~~~~~~~~~~~~~~~~~~~~~~~~ */
int			threading(t_rules *rules, t_philo *philo);

/* ~~~~~~~ ACTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~ */
int			get_forks(t_rules *rules, t_philo *philo);
int			eat(t_rules *rules, t_philo *philo);
void		sleeper(long long duration);

/* ~~~~~~~ LOG ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
void		log_status(t_rules *rules, int id, int status);

/* ~~~~~~~ EXIT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
int			error(char *message, t_rules *rules);
int			delete_mutex(t_rules *rules);
int			free_all(t_rules *rules);

/* ~~~~~~~ UTILS ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
int			my_atoi(char *str);

long long	get_time(void);

#endif
