pthread_t		philosophers[5];
pthread_mutex_t	forks[5];

void	*routine(int n)
{
	printf("\nPhilosopher %d is thinking.", n);
	pthread_mutex_lock(&forks[n]);
	pthread_mutex_lock(&forks[(n + 1) % 5]);
	printf("\nPhilosopher %d is eating", n);
	sleep(1);
	pthread_mutex_unlock(&forks[n]);
	pthread_mutex_unlock(&forks[(n + 1) % 5]);
	printf("\nPhilosopher %d finished eating", n);
	return (0);
}

void	start_program(t_philo *philo)
{
	int				i;
	int				k;
	void			*msg;

	i = 1;
	while (i <= philo->nb)
	{
		k = pthread_mutex_init(&forks[i], NULL);
		if (k == -1)
		{
			philo_error("Error: mutex initialisation failed.\n", philo);
			exit (1);
		}
		i++;
	}
	i = 1;
	while (i <= philo->nb)
	{
		k = pthread_create(&philosophers[i], NULL, &routine, i);
		if (k != 0)
		{
			philo_error("Error: thread creation failed.\n", philo);
			exit (1);
		}
		i++;
	}
	i = 1;
	while (i <= philo->nb)
	{
		k = pthread_join(philosophers[i], &msg);
		if (k != 0)
		{
			philo_error("Error: thread join failed.\n", philo);
			exit (1);
		}
		i++;
	}
	i = 1;
	while (i <= philo->nb)
	{
		k = pthread_mutex_destroy(&forks[i]);
		if (k != 0)
		{
			philo_error("Error: mutex destroyed.\n", philo);
			exit (1);
		}
		i++;
	}
}