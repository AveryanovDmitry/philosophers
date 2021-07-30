/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:01:22 by hhoyl             #+#    #+#             */
/*   Updated: 2021/07/11 17:15:39 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo {
	int				num;
	int				is_death;
	int				is_done;
	int				num_eat;
	long long		last_time_eat;
	long long		time_die;
	long long		time_eat;
	long long		time_sleep;
	long long		begin_time;
	long long		begin_life;

	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*chat;
}	t_philo;

typedef struct s_all {
	pthread_mutex_t	chat;
	int				num_philos;
	int				num_eat;
	long long		time_die;
	long long		time_eat;
	long long		time_sleep;
	long long		begin_time;

	t_philo			*philos;
}	t_all;

void		take_forks(t_philo *philo);
long long	ft_atoill(char *s);
long long	get_time(long long begin_time);
int			pars_input(int argc, char **argv, t_all *all);
void		take_fork(t_philo *philo);
void		put_fork(t_philo *philo);
void		eating(t_philo *philo);
void		sleeping_thinking(t_philo *philo);
void		my_usleep(long long time);
#endif
