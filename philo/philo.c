/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:58:10 by ereginia          #+#    #+#             */
/*   Updated: 2022/03/21 14:21:41 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo_god	god;

	if ((argc != 5 && argc != 6) || parse(&god, argv))
		return (1);
	ft_init(&god);
	while (deadly_overwatch(&god))
		;
	garbage_collector(&god);
	return (0);
}
