/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:19:01 by ereginia          #+#    #+#             */
/*   Updated: 2022/03/23 14:28:24 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/types.h>
# include <signal.h>

//	params[0] = number_of_philosophers
//	params[1] = time_to_die
//	params[2] = time_to_eat
//	params[3] = time_to_sleep
//	params[4] = meal_number
typedef struct s_philo_god
{
	int				philo_id;
	int				*params;
	pid_t			*pids;
	pid_t			sem_pid;
	sem_t			*fork_sem;
	sem_t			*dinner_sem;
	sem_t			*to_print;
	sem_t			*data_race;
	long long int	start_time;
	long long int	last_dinner;
}	t_philo_god;

// init.c
void	ft_init(t_philo_god *god);
void	ft_clean(t_philo_god *god);

// overwatch.c
void	*deadly_overwatch(void *mystic);
int		dinner_overwatch(t_philo_god *god);

// parser.c
int		parse(t_philo_god *god, char **argv);

// routine.c
void	routine(t_philo_god *god);

// utils.c
void	print_a_message(t_philo_god *god, int message);
int		get_time_from_born(t_philo_god *god);
int		get_time(long long int from);
void	ft_msleep(int millisec);

// libft part
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_itoa(int n);

#endif