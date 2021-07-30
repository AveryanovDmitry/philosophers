/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:15:13 by hhoyl             #+#    #+#             */
/*   Updated: 2021/07/11 17:15:21 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	pair_forks(t_philo *philo, \
	pthread_mutex_t *fork, int l, int r)
{
	philo->left_fork = &fork[l];
	philo->right_fork = &fork[r];
}

static void	for_norminette(t_all *all, int i, int argc)
{
	all->philos[i].num = i;
	all->philos[i].last_time_eat = 0;
	all->philos[i].is_death = 0;
	all->philos[i].is_done = 0;
	all->philos[i].time_die = all->time_die;
	all->philos[i].time_eat = all->time_eat;
	all->philos[i].time_sleep = all->time_sleep;
	all->philos[i].last_time_eat = 0;
	all->philos[i].begin_time = all->begin_time;
	all->philos[i].begin_life = all->begin_time;
	if (argc == 6)
		all->philos[i].num_eat = all->num_eat;
	else
		all->philos[i].num_eat = -1;
}

static int	pars_philo(t_all *all, int argc)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(all->num_philos * sizeof(pthread_mutex_t));
	if (forks == NULL)
		return (-1);
	i = 0;
	while (i < all->num_philos)
	{
		all->philos[i].chat = &all->chat;
		pthread_mutex_init(&forks[i], NULL);
		for_norminette(all, i, argc);
		if (i % 2 != 0 && i > 0 && all->num_philos > 2)
			pair_forks(&all->philos[i], forks, i - 1, i);
		else if (i > 0 && all->num_philos > 2)
			pair_forks(&all->philos[i], forks, i, i - 1);
		else if (i >= 0 && all->num_philos == 2)
			pair_forks(&all->philos[i], forks, i, i + 1);
		i++;
	}
	all->philos[0].left_fork = &forks[0];
	all->philos[0].right_fork = &forks[all->num_philos - 1];
	return (1);
}

static int	check_argc(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Wrong args\n");
		return (1);
	}
	return (0);
}

int	pars_input(int argc, char **argv, t_all *all)
{
	if (check_argc(argc))
		return (0);
	all->begin_time = get_time(0);
	all->num_philos = ft_atoill(argv[1]);
	all->time_die = ft_atoill(argv[2]);
	all->time_eat = ft_atoill(argv[3]);
	all->time_sleep = ft_atoill(argv[4]);
	if (argc == 6)
		all->num_eat = ft_atoill(argv[5]);
	else
		all->num_eat = 0;
	if (all->time_die <= 0 || all->time_sleep <= 0
		|| all->time_eat <= 0)
	{
		printf("Wrong args\n");
		return (0);
	}
	all->philos = malloc(all->num_philos * sizeof(t_philo));
	if (all->philos == NULL)
		return (-1);
	if (!(pars_philo(all, argc)))
		return (-1);
	return (1);
}
