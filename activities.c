/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:52:08 by alfertah          #+#    #+#             */
/*   Updated: 2022/08/06 13:01:20 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_forks(t_philo *p, t_args *a)
{
	if (a->philos_num == 1)
	{
		pthread_mutex_lock(&a->forks_mutex[p->right_fork]);
		print_philo(p, a, "has taken a right fork");
	}
	else
	{
		pthread_mutex_lock(&a->forks_mutex[p->right_fork]);
		print_philo(p, a, "has taken a right fork");
		pthread_mutex_lock(&a->forks_mutex[p->left_fork]);
		print_philo(p, a, "has taken a left fork");
	}
}

void	eating(t_philo *p, t_args *a)
{
	if (a->philos_num == 1)
	{
		while (!a->end)
			usleep(1000);
		pthread_mutex_unlock(&a->forks_mutex[p->right_fork]);
	}
	else
	{
		print_philo(p, a, "is eating");
		p->last_meal = get_time();
		while (get_time() - p->last_meal <= a->eat_time)
			usleep(1000);
		p->eat_count++;
		if (p->eat_count >= a->must_eat_num)
			a->ends_num++;
		pthread_mutex_unlock(&a->forks_mutex[p->right_fork]);
		pthread_mutex_unlock(&a->forks_mutex[p->left_fork]);
	}
}

void	sleeping(t_philo *p, t_args *a)
{
	long long	start_sleeping;

	start_sleeping = get_time();
	print_philo(p, a, "is sleeping");
	while (get_time() - start_sleeping <= a->slp_time)
		usleep(1000);
}

void	thinking(t_philo *p, t_args *a)
{
	print_philo(p, a, "is thinking");
}
