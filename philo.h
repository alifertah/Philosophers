#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int					id;
	int					eat_count;
	int					left_fork;
	int					right_fork;
	long long			last_meal;
	long long			is_dead;
	pthread_t			philo_tid;
	pthread_t			monitor_tid;
	struct s_args		*args;
}t_philo;

typedef struct s_args
{
	int					philos_num;
	int					die_time;
	int					eat_time;
	int					slp_time;
	int					must_eat_num;
	int					ends_num;
	int					end;
	long long			start_time;
	pthread_mutex_t		*forks_mutex;
	pthread_mutex_t		print_mutex;
	t_philo				*philo;
}t_args;

int		ft_atoi(const char *str);
int		ft_is_digit(char **av);
int		ft_error(char *msg);
int		ft_fill_args(t_args *args, int ac, char **av);
int		ft_malloc(t_args *args);
int		get_fork(t_args *args);
int		get_philo(t_args *args);
int		creat_phthread(t_args *args);
void	*routine(void *philo);
void	*ft_is_deathe(void *philo);
int		get_time(void);
void	print_philo(t_philo *philo, t_args *args, char *msg);
void	taking_forks(t_philo *p, t_args *a);
void	eating(t_philo *p, t_args *a);
void	sleeping(t_philo *p, t_args *a);
void	thinking(t_philo *p, t_args *a);

#endif
