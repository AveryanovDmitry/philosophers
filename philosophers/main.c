/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:49:32 by hhoyl             #+#    #+#             */
/*   Updated: 2021/06/19 14:49:34 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	*funk_for_tread(void *philo_tmp)
{
	t_philo	*philo;

	philo = (t_philo *)philo_tmp;
	philo->begin_life = get_time(0);
	while (1)
	{
		take_fork(philo);
		eating(philo);
		put_fork(philo);
		if (philo->num_eat != -1 && philo->num_eat != 0)
		{
			--philo->num_eat;
		}
		sleeping_thinking(philo);
	}
	return (NULL);
}

static	int	check_death(t_all *data, int *did_eat, int *i)
{
	if (data->time_die < get_time(data->philos[*i].begin_life))
	{
		pthread_mutex_lock(&data->chat);
		printf("%lld %d died\n",
			get_time(data->philos[*i].begin_time), *i + 1);
		return (1);
	}
	if (data->philos[*i].num_eat == 0)
		--*did_eat;
	return (0);
}

static	void	*monitoring(void *date_tmp)
{
	int		i;
	int		did_eat;
	t_all	*data;

	data = date_tmp;
	while (1)
	{
		i = -1;
		did_eat = data->num_philos;
		while (++i < data->num_philos)
		{
			if (check_death(data, &did_eat, &i))
				return (NULL);
		}
		if (did_eat == 0)
		{
			pthread_mutex_lock(&data->chat);
			return (NULL);
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_all			all;
	pthread_t		*treads_philo;
	int				i;

	i = 0;
	if (!(pars_input(argc, argv, &all)))
		return (-1);
	treads_philo = malloc((all.num_philos + 1) * sizeof(pthread_t));
	if (treads_philo == NULL)
		return (-1);
	while (i < all.num_philos)
	{
		pthread_create(&treads_philo[i], NULL, funk_for_tread, &all.philos[i]);
		i++;
	}
	pthread_create(&treads_philo[all.num_philos], NULL, monitoring, &all);
	pthread_join(treads_philo[all.num_philos], NULL);
	i = 0;
	while (i < all.num_philos)
		pthread_detach(treads_philo[i++]);
	return (0);
}
