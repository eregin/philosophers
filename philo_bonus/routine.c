/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:36:56 by ereginia          #+#    #+#             */
/*   Updated: 2022/03/23 13:50:40 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// поток жрет
static void	dinner_time(t_philo_god *god)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	sem_wait(god->data_race);
	god->last_dinner = ((now.tv_sec) * 1000) + ((now.tv_usec) / 1000);
	sem_post(god->data_race);
	print_a_message(god, 1);
	ft_msleep(god->params[2]);
	if (god->params[4] != -1)
	{
		god->params[4]--;
		if (god->params[4] == 0)
			sem_post(god->dinner_sem);
	}
}

// поток спит
static void	sleep_time(t_philo_god *god)
{
	print_a_message(god, 2);
	ft_msleep(god->params[3]);
}

// поток пытается взять вилки чтоб похавать
static void	try_to_eat(t_philo_god *god)
{
	sem_wait(god->fork_sem);
	print_a_message(god, 0);
	sem_wait(god->fork_sem);
	print_a_message(god, 0);
	dinner_time(god);
	sem_post(god->fork_sem);
	sem_post(god->fork_sem);
}

void	routine(t_philo_god *god)
{
	pthread_t	death_check;

	pthread_create(&death_check, NULL, &deadly_overwatch, god);
	pthread_detach(death_check);
	while (1)
	{
		try_to_eat(god);
		sleep_time(god);
		print_a_message(god, 3);
	}
}
