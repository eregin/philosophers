/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:23:40 by ereginia          #+#    #+#             */
/*   Updated: 2022/03/21 11:42:56 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// поток жрет
static void	dinner_time(t_philo_stat *philo)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	pthread_mutex_lock(philo->data_race);
	philo->last_dinner = ((now.tv_sec) * 1000) + ((now.tv_usec) / 1000);
	pthread_mutex_unlock(philo->data_race);
	print_a_message(philo, 1);
	ft_msleep(philo->philo_params[2]);
	if (philo->philo_params[4] != -1)
	{
		pthread_mutex_lock(philo->data_race);
		philo->eating_times++;
		pthread_mutex_unlock(philo->data_race);
	}
}

// поток спит
static void	sleep_time(t_philo_stat *philo)
{
	print_a_message(philo, 2);
	ft_msleep(philo->philo_params[3]);
}

// поток пытается взять вилки чтоб похавать
static void	try_take_fork(t_philo_stat *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_a_message(philo, 0);
	pthread_mutex_lock(philo->right_fork);
	print_a_message(philo, 0);
	dinner_time(philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*routine(void *philo)
{
	t_philo_stat	*philosoph;

	philosoph = (t_philo_stat *)philo;
	while (1)
	{
		try_take_fork(philosoph);
		sleep_time(philosoph);
		print_a_message(philosoph, 3);
	}
	return (NULL);
}
