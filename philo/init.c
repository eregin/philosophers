/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:20:00 by ereginia          #+#    #+#             */
/*   Updated: 2022/03/21 11:35:55 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// всучаем каждому челику вилки
static void	fork_per_hand(t_philo_god *god)
{
	int	i;

	i = 0;
	while (i < god->params[0])
	{
		if (i != god->params[0] - 1)
		{
			god->chelik[i].left_fork = &god->forks[i];
			god->chelik[i].right_fork = &god->forks[i + 1];
		}
		else
		{
			god->chelik[i].left_fork = &god->forks[i];
			god->chelik[i].right_fork = &god->forks[0];
		}
		i++;
	}
}

// проставляем челикам параметры
static void	give_all_chelik_purpose(t_philo_god *god)
{
	int	i;

	i = 0;
	while (i < god->params[0])
	{
		god->chelik[i].philo_id = i;
		god->chelik[i].philo_params = god->params;
		god->chelik[i].eating_times = 0;
		god->chelik[i].start_time = god->start_time;
		god->chelik[i].last_dinner = god->start_time;
		god->chelik[i].to_print = &god->m_print;
		god->chelik[i].data_race = &god->data_race;
		pthread_mutex_init(&god->forks[i], NULL);
		i++;
	}
}

// запуск потоков
static void	treading(t_philo_god *god)
{
	int	i;

	i = 0;
	god->phil_tread = (pthread_t *)malloc(sizeof(pthread_t) * (god->params[0]));
	while (i < god->params[0])
	{
		pthread_create(&god->phil_tread[i], NULL, &routine, &god->chelik[i]);
		pthread_detach(god->phil_tread[i]);
		i = i + 2;
	}
	i = 1;
	usleep(50);
	while (i < god->params[0])
	{
		pthread_create(&god->phil_tread[i], NULL, &routine, &god->chelik[i]);
		pthread_detach(god->phil_tread[i]);
		i = i + 2;
	}
}

// функция инициализации
void	ft_init(t_philo_god *god)
{
	struct timeval	start;

	god->chelik = (t_philo_stat *) \
			malloc(sizeof(t_philo_stat) * (god->params[0]));
	god->forks = (pthread_mutex_t *) \
			malloc(sizeof(pthread_mutex_t) * (god->params[0]));
	god->flags = (char *)malloc(sizeof(char) * god->params[0]);
	memset(god->flags, 0, sizeof(char) * god->params[0]);
	pthread_mutex_init(&god->m_print, NULL);
	pthread_mutex_init(&god->data_race, NULL);
	gettimeofday(&start, NULL);
	god->start_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	give_all_chelik_purpose(god);
	fork_per_hand(god);
	treading(god);
}
