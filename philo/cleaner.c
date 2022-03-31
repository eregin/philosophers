/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:01:08 by ereginia          #+#    #+#             */
/*   Updated: 2022/03/21 11:32:12 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	garbage_collector(t_philo_god *god)
{
	int	i;

	i = 0;
	free(god->phil_tread);
	free(god->chelik);
	free(god->forks);
	free(god->flags);
	free(god->params);
	while (i < god->params[0])
	{
		pthread_mutex_destroy(&god->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&god->data_race);
	pthread_mutex_destroy(&god->m_print);
}
