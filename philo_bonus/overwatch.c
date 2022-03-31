/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overwatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:50:38 by ereginia          #+#    #+#             */
/*   Updated: 2022/03/23 14:34:35 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	dinner_overwatch(t_philo_god *god)
{
	int	i;
	int	max;

	i = 0;
	max = god->params[0];
	while (i < max)
	{
		sem_wait(god->dinner_sem);
		i++;
	}
	sem_wait(god->to_print);
	ft_clean(god);
	exit(0);
}

void	*deadly_overwatch(void *mystic)
{
	t_philo_god	*god;
	long long	tmp;

	god = (t_philo_god *)mystic;
	while (1)
	{
		sem_wait(god->data_race);
		tmp = get_time(god->last_dinner);
		sem_post(god->data_race);
		if (tmp > god->params[1])
		{
			print_a_message(god, 4);
			break ;
		}
		usleep(500);
	}
	exit(0);
}
