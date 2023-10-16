#include "philo.h"

void	end_routine(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->philos_num)
	{
		pthread_mutex_destroy(&(args->forks_mutex[i]));
		i++;
	}
	pthread_mutex_destroy(&(args->print_mutex));
	free(args->forks_mutex);
	free(args->philo);
}

int	main(int ac, char **av)
{
	t_args			args;

	if (ac > 4 && ac < 7)
	{
		if (ft_fill_args(&args, ac, av))
			return (ft_error("Invalid argsuments"));
		if (ft_malloc(&args))
			return (ft_error("Malloc Failed"));
		if (get_philo(&args) || get_fork(&args))
			return (ft_error("Initialize failed"));
		if (creat_phthread(&args))
			return (ft_error("Thread failed"));
		end_routine(&args);
	}
	else
		return (ft_error("Wrong argsuments"));
}
