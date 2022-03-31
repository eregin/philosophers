/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:31:08 by ereginia          #+#    #+#             */
/*   Updated: 2022/03/21 14:38:28 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	parse(t_philo_god *god, char **argv)
{
	int		*arr;
	int		i;
	char	*buf;

	i = 1;
	arr = (int *)malloc(sizeof(int) * 5);
	while (argv[i])
	{
		buf = ft_itoa(ft_atoi(argv[i]));
		if (ft_strncmp(buf, argv[i], ft_strlen(argv[i]))
			|| ft_atoi(argv[i]) <= 0)
		{
			free(buf);
			return (1);
		}
		arr[i - 1] = ft_atoi(argv[i]);
		free(buf);
		i++;
	}
	if (i == 5)
		arr[4] = -1;
	god->params = arr;
	return (0);
}
