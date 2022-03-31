/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:59:00 by ereginia          #+#    #+#             */
/*   Updated: 2022/03/23 13:26:14 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo_stat
{
	int				philo_id;
	int				eating_times;
	int				*philo_params;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*to_print;
	pthread_mutex_t	*data_race;
	long long int	last_dinner;
	long long int	start_time;
}	t_philo_stat;

//	params[0] = number_of_philosophers
//	params[1] = time_to_die
//	params[2] = time_to_eat
//	params[3] = time_to_sleep
//	params[4] = meal_number
typedef struct s_philo_god
{
	pthread_t		*phil_tread;
	int				*params;
	char			*flags;
	long long int	start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	m_print;
	pthread_mutex_t	data_race;
	t_philo_stat	*chelik;
}	t_philo_god;

// init.c
void	ft_init(t_philo_god *god);

// parser.c
int		parse(t_philo_god *god, char **argv);

// routine.c
void	*routine(void *philo);

// utils.c
void	print_a_message(t_philo_stat *philo, int message);
int		get_time_from_born(t_philo_stat *philo);
int		get_time(long long int from);
void	ft_msleep(int millisec);

// overwatch.c
int		deadly_overwatch(t_philo_god *god);

// libft part
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_itoa(int n);

// cleaner.c
void	garbage_collector(t_philo_god *god);

#endif