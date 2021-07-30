/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:15:45 by hhoyl             #+#    #+#             */
/*   Updated: 2021/07/11 17:15:47 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	if (s)
	{
		while (s[n])
			n++;
	}
	return (n);
}

static int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

long long	ft_atoill(char *s)
{
	long long	ret;
	int			mod;
	int			i;
	int			len;

	ret = 0;
	i = 0;
	mod = 1;
	len = ft_strlen(s);
	if (len <= 19 || (s[0] == '-' && ft_strlen(&s[1]) <= 19))
	{
		if (s[0] == '-')
		{
			mod = -1;
			i = 1;
		}
		while (ft_isdigit(s[i]))
			ret = ret * 10 + s[i++] - '0';
	}
	return (ret * mod);
}

long long	get_time(long long begin_time)
{
	struct timeval	t3;

	gettimeofday(&t3, NULL);
	return ((t3.tv_sec * 1000 + t3.tv_usec / 1000) - begin_time);
}
