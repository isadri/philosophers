#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define USG_ERR 2
# define INVALID_ARGS 3
# define ALLOC_ERR 4
# define OK 1
# define USG_ERR_MSG "\e[1m\x1b[31mUsage:\x1b[0m\e[m"
# define INVALID_ARG_MSG "\e[1m\x1b[31mInvalid argument:\x1b[0m\e[m"

typedef struct s_time
{
	time_t	time_to_eat;
	time_t	time_to_sleep;
	time_t	current_time;
}	t_time;

typedef struct s_philo
{
	pthread_t		ph;
	unsigned int	id;
	t_time			time;
	unsigned int	eat_counter;
	time_t			start_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_data
{
	t_philo			*philos;
	time_t			time_to_die;
	unsigned int	nbr_of_philos;
	unsigned int	max_eat;
	pthread_mutex_t	*forks;
	time_t			start_time;
}	t_data;

/*	src/init.c	*/
void			data_init(t_data **data, char *argv[]);

/*	src/philos_create.c	*/
t_philo			*philos_create(char *argv[], t_data *data, int nbr);

/*	src/launch.c	*/
void			launch(t_data *data);
time_t			get_current_time(void);
time_t			get_action_time(t_philo *data);

/*	src/start.c	*/
void			*start(void *arg);

/*	src/monitor.c	*/
bool			someone_dies(t_philo *philos, t_data *data);
bool			all_eat(t_philo *philos, t_data *data);

/*	src/error.c	*/
void			exit_usg_err(void);
void			invalid_arg(char *arg, char *expected_arg);
void			exit_func_call_err(char *func_name, int err);

/*	src/check.c	*/
int				check_arguments(char *argv[]);

/*	src/debug.c	*/
void			print_data(t_data *data);
void			print_philos(t_philo *philos, int nbr);

/*	utils/ctype.c	*/
bool			is_digit(char c);

/*	utils/ft_atoi.c	*/
unsigned long	ft_atoi(char *str);

/*	utils/ft_calloc.c	*/
void			*ft_calloc(size_t count, size_t size);

/*	utils/clear.c	*/
void			clear(t_data **data);
void			destroy_forks(pthread_mutex_t *forks, unsigned int nbr_of_forks);

#endif