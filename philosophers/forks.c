/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 01:06:31 by hhoyl             #+#    #+#             */
/*   Updated: 2021/07/16 01:06:33 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	printf("%lld %d has taken a fork\n",
		get_time(philo->begin_time), philo->num + 1);
	pthread_mutex_lock(philo->left_fork);
	printf("%lld %d has taken a fork\n",
		get_time(philo->begin_time), philo->num + 1);
}

void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	eating(t_philo *philo)
{
	printf("%lld %d is eating\n",
		get_time(philo->begin_time), philo->num + 1);
	philo->begin_life = get_time(0);
	my_usleep(philo->time_eat);
}

void	sleeping_thinking(t_philo *philo)
{
	printf("%lld %d is sleeping\n",
		get_time(philo->begin_time), philo->num + 1);
	my_usleep(philo->time_sleep);
	printf("%lld %d is thinking\n",
		get_time(philo->begin_time), philo->num + 1);
}

void	my_usleep(long long time)
{
	struct timeval	t1;
	ssize_t			timing;

	gettimeofday(&t1, NULL);
	timing = t1.tv_sec * 1000 + t1.tv_usec / 1000;
	while (time > (t1.tv_sec * 1000 + t1.tv_usec / 1000) - timing)
	{
		gettimeofday(&t1, NULL);
		usleep(100);
	}
}
