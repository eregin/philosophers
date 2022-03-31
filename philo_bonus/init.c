/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:14:15 by ereginia          #+#    #+#             */
/*   Updated: 2022/03/23 14:52:13 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_clean(t_philo_god *god)
{
	sem_close(god->fork_sem);
	sem_close(god->dinner_sem);
	sem_close(god->to_print);
	sem_close(god->data_race);
	free(god->params);
	free(god->pids);
}

static void	ft_start(t_philo_god *god)
{
	god->philo_id = 0;
	while (god->philo_id < god->params[0])
	{
		god->pids[god->philo_id] = fork();
		if (god->pids[god->philo_id] == 0)
			routine(god);
		god->philo_id++;
		god->philo_id++;
	}
	god->philo_id = 1;
	while (god->philo_id < god->params[0])
	{
		god->pids[god->philo_id] = fork();
		if (god->pids[god->philo_id] == 0)
			routine(god);
		god->philo_id++;
		god->philo_id++;
	}
	if (god->params[4] != -1)
	{
		god->sem_pid = fork();
		if (god->sem_pid == 0)
			dinner_overwatch(god);
	}
}

void	ft_init(t_philo_god *god)
{
	struct timeval	start;

	god->pids = (pid_t *)malloc(sizeof(pid_t) * (god->params[0]));
	sem_unlink("/forks");
	sem_unlink("/dinner");
	sem_unlink("/to_print");
	sem_unlink("/check_data_race");
	god->fork_sem = sem_open("/forks", O_CREAT, 0777, god->params[0]);
	god->dinner_sem = sem_open("/dinner", O_CREAT, 0777, 0);
	god->to_print = sem_open("/to_print", O_CREAT, 0777, 1);
	god->data_race = sem_open("/check_data_race", O_CREAT, 0777, 1);
	gettimeofday(&start, NULL);
	god->start_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	god->last_dinner = god->start_time;
	ft_start(god);
	waitpid(-1, NULL, 0);
	kill(0, SIGINT);
	ft_clean(god);
	exit(0);
}
