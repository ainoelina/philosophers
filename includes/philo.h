/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 11:27:02 by avuorio       #+#    #+#                 */
/*   Updated: 2021/10/20 14:53:37 by avuorio       ########   odam.nl         */
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
	int				full;
	int				eating_now;
	int				meal_count;
	long long		last_ate;
	long long		time;
	pthread_mutex_t	lock;
	pthread_mutex_t	eating;
}				t_philo;

typedef struct s_rules
{
	int				nb;
	int				eat_time;
	int				die_time;
	int				sleep_time;
	int				eat_count;
	int				dead;
	int				done;
	long long		start;
	struct s_philo	*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	log;
	pthread_mutex_t	deceased;
}				t_rules;

/* ------------ PROGRAM ---------- */
void		start_threads(t_rules *rules);
void		exit_program(t_rules *rules);
void		take_forks(t_rules *rules, t_philo *philo);
void		go_to_sleep(t_rules *rules, t_philo *philo);
void		eat(t_philo *philo, t_rules *rules);

/* ------------ LOG -------------- */
void		log_status(t_rules *rules, int id, int status);

/* ------------ QUIT ------------- */
int			philo_error(char *message, t_rules *rules);

/* ------------ INITIALISE ------- */
int			init_rules(t_rules *rules, int ac, char **av);

/* ------------ UTILS ------------ */
int			my_atoi(char *str);
long long	get_time(void);

/* ------------ PRINT TOOLS ------ */
void		print_rules(t_rules *rules);

#endif
