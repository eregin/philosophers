/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:35:47 by ereginia          #+#    #+#             */
/*   Updated: 2022/03/21 11:44:27 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_msleep(int millisec)
{
	struct timeval	now;
	long long int	now_usec;

	gettimeofday(&now, NULL);
	now_usec = ((now.tv_sec) * 1000) + ((now.tv_usec) / 1000);
	while (get_time(now_usec) < millisec)
		usleep(50);
}

// возвращает текущее время от зарождения
int	get_time_from_born(t_philo_stat *philo)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (((now.tv_sec) * 1000) + ((now.tv_usec) / 1000) - philo->start_time);
}

// возвращает текущее время от заданного параметра
int	get_time(long long int from)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (((now.tv_sec) * 1000) + ((now.tv_usec) / 1000) - from);
}

// поток докладывает
void	print_a_message(t_philo_stat *philo, int message)
{
	pthread_mutex_lock(philo->to_print);
	if (message == 0)
		printf("%d %d has taken a fork\n", \
			get_time_from_born(philo), philo->philo_id + 1);
	if (message == 1)
		printf("%d %d is eating\n", \
			get_time_from_born(philo), philo->philo_id + 1);
	if (message == 2)
		printf("%d %d is sleeping\n", \
			get_time_from_born(philo), philo->philo_id + 1);
	if (message == 3)
		printf("%d %d is thinking\n", \
			get_time_from_born(philo), philo->philo_id + 1);
	if (message == 4)
	{
		printf("%d %d is dead\n", \
			get_time_from_born(philo), philo->philo_id + 1);
		return ;
	}
	pthread_mutex_unlock(philo->to_print);
}
