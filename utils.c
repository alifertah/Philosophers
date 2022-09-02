/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:52:36 by alfertah          #+#    #+#             */
/*   Updated: 2022/08/06 14:55:58 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *msg)
{
	printf("\033[0;31mERROR:  %s\n", msg);
	return (1);
}

int	ft_atoi(const char *str)
{
	long		nbr;
	long		sign;
	size_t		i;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i++] - '0');
		if (nbr > 2147483647 && sign == 1)
			return (-1);
		if (nbr > 2147483648 && sign == -1)
			return (0);
	}
	return (nbr * sign);
}

int	ft_is_digit(char **av)
{
	int			i;
	int			j;

	i = 1;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	get_time(void)
{
	long long		ret;
	struct timeval	time;

	ret = 0;
	if (gettimeofday(&time, NULL) == -1)
		ft_error("Error getting time");
	ret = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ret);
}

void	print_philo(t_philo *philo, t_args *args, char *msg)
{
	if (args->end)
		return ;
	pthread_mutex_lock(&args->print_mutex);
	printf("%lld\t", get_time() - philo->args->start_time);
	printf("%d\t", philo->id + 1);
	printf("%s\t\n", msg);
	pthread_mutex_unlock(&args->print_mutex);
}
