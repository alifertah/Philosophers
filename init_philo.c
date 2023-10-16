#include "philo.h"

int	ft_fill_args(t_args *args, int ac, char **av)
{
	if (!ft_is_digit(av))
		return (1);
	args->philos_num = ft_atoi(av[1]);
	args->die_time = ft_atoi(av[2]);
	args->eat_time = ft_atoi(av[3]);
	args->slp_time = ft_atoi(av[4]);
	if (ac == 6)
		args->must_eat_num = ft_atoi(av[5]);
	else
		args->must_eat_num = -1;
	if (args->philos_num <= 0 || args->die_time <= 0 || \
		args->eat_time <= 0 || args->slp_time <= 0 || \
		args->must_eat_num == 0)
		return (1);
	args->ends_num = 0;
	args->end = 0;
	return (0);
}

int	ft_malloc(t_args *args)
{
	args->philo = malloc(sizeof(t_philo) * args->philos_num);
	if (!args->philo)
		return (1);
	args->forks_mutex = malloc(sizeof(pthread_mutex_t) * args->philos_num);
	if (!args->forks_mutex)
	{
		free(args->philo);
		return (1);
	}
	return (0);
}

int	get_philo(t_args *args)
{
	int		i;

	i = 0;
	while (i < args->philos_num)
	{
		args->philo[i].id = i;
		args->philo[i].eat_count = 0;
		args->philo[i].last_meal = 0;
		args->philo[i].is_dead = 0;
		args->philo[i].args = args;
		args->philo[i].left_fork = i;
		args->philo[i].right_fork = (i + 1) % args->philos_num;
		i++;
	}
	return (0);
}

int	get_fork(t_args *args)
{
	int		i;

	i = 0;
	while (i < args->philos_num)
	{
		if (pthread_mutex_init(&args->forks_mutex[i], NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&args->print_mutex, NULL) != 0)
		return (1);
	return (0);
}
