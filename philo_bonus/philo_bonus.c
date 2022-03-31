/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:17:15 by ereginia          #+#    #+#             */
/*   Updated: 2022/03/23 14:05:40 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo_god	god;

	if ((argc != 5 && argc != 6) || parse(&god, argv))
		return (1);
	ft_init(&god);
	return (0);
}
