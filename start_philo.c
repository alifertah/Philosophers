/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:52:31 by alfertah          #+#    #+#             */
/*   Updated: 2022/08/06 15:05:22 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	finished_meal(t_args *a)
{
	a->end = 1;
	usleep(1000);
	pthread_mutex_lock(&a->print_mutex);
	printf("\033[0;36mphilosophers have finished their TAJINES\n");
	pthread_mutex_unlock(&a->print_mutex);
}

int	creat_phthread(t_args *args)
{
	int			i;

	i = 0;
	args->start_time = get_time();
	while (i < args->philos_num)
	{
		args->philo[i].last_meal = get_time();
		if (pthread_create(&args->philo[i].philo_tid,
				NULL, routine, &args->philo[i]) != 0)
			return (EXIT_FAILURE);
		if (pthread_create(&args->philo[i].monitor_tid,
				NULL, ft_is_deathe, &args->philo[i]) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < args->philos_num)
	{
		if (pthread_join(args->philo[i].philo_tid, NULL) != 0)
			return (EXIT_FAILURE);
		if (pthread_join(args->philo[i].monitor_tid, NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	*routine(void *philo)
{
	t_philo		*p;
	t_args		*a;

	p = (t_philo *)philo;
	a = p->args;
	if (p->id % 2 == 0)
		usleep(1000 * a->eat_time);
	while (!a->end)
	{
		taking_forks(p, a);
		eating(p, a);
		if (a->end)
			break ;
		if (a->must_eat_num > 0 && a->ends_num >= a->philos_num)
		{
			finished_meal(a);
			break ;
		}
		sleeping(p, a);
		if (a->end)
			break ;
		thinking(p, a);
	}
	return (0);
}

void	*ft_is_deathe(void *philo)
{
	t_args		*a;
	t_philo		*p;

	p = (t_philo *)philo;
	a = p->args;
	while (!a->end)
	{
		if (get_time() - p->last_meal >= a->die_time)
		{
			a->end = 1;
			pthread_mutex_lock(&a->print_mutex);
			printf("%lld\t", get_time() - p->args->start_time);
			printf("%d\t%s\t(%d)\n", p->id + 1, "dead", p->eat_count);
			return (0);
		}
		usleep(100);
	}
	return (0);
}
