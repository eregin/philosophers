/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overwatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:17:37 by ereginia          #+#    #+#             */
/*   Updated: 2022/03/21 14:30:09 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	dinner_overwatch(t_philo_god *god)
{
	static int	i = 0;

	if (god->params[4] > 0)
	{
		pthread_mutex_lock(&god->data_race);
		if (god->chelik[i].eating_times >= god->params[4])
		{
			pthread_mutex_lock(&god->m_print);
			god->flags[i] = 1;
			i++;
			if (i == god->params[0])
				return (0);
			pthread_mutex_unlock(&god->m_print);
		}
		pthread_mutex_unlock(&god->data_race);
	}
	return (1);
}

int	deadly_overwatch(t_philo_god *god)
{
	int	i;

	i = 0;
	while (i < god->params[0])
	{
		if (!dinner_overwatch(god))
			return (0);
		pthread_mutex_lock(&god->data_race);
		if (get_time(god->chelik[i].last_dinner) > god->params[1])
		{
			print_a_message(&god->chelik[i], 4);
			return (0);
		}
		pthread_mutex_unlock(&god->data_race);
		i++;
	}
	return (1);
}
