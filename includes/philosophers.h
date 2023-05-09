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

typedef struct s_mtx
{
	pthread_mutex_t	*head_forks_mtx;
	pthread_mutex_t	*head_meal_mtx;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*print_mtx;
	pthread_mutex_t	*time_mtx;
	pthread_mutex_t	*meal_mtx;
}	t_mtx;

typedef struct s_time
{
	time_t	time_to_eat;
	time_t	time_to_sleep;
	time_t	time_to_die;
	time_t	start_time;
	time_t	last_eat_time;
}	t_time;

typedef struct s_philo
{
	pthread_t		ph;
	unsigned int	id;
	t_time			time;
	unsigned int	nbr_of_philos;
	int				meal;
	int				nbr_of_meals;
	t_mtx			mtx;
}	t_philo;

/*	src/debug.c	*/
void			print_data(t_philo *philos);

/*	src/launch.c	*/
int				launch(t_philo *philos);
time_t			get_current_time(void);
time_t			calculate_time(time_t start_time);

/*	src/start.c	*/
void			*start(void *arg);
void			increase_meal_counter(t_philo *philo);

/*	src/init.c	*/
int				philos_init(t_philo **philos, char *argv[]);

///*	src/start.c	*/
//void			*start(void *arg);

///*	src/monitor.c	*/
//bool			someone_dies(t_philo *philos, t_data *data);
//bool			all_eat(t_philo *philos, t_data *data);

/*	src/error.c	*/
void			usage_err(void);
void			invalid_arg(char *arg, char *expected_arg);

/*	src/check.c	*/
int				check_arguments(char *argv[]);

///*	src/debug.c	*/
//void			print_data(t_data *data);
//void			print_philos(t_philo *philos, int nbr);

/*	utils/ctype.c	*/
bool			is_digit(char c);

/*	utils/ft_atoi.c	*/
unsigned long	my_atoi(char *str);

/*	utils/ft_calloc.c	*/
void			*my_calloc(size_t count, size_t size);

/*	src/clear.c	*/
void			clear(t_philo **data);
//void			destroy_forks(pthread_mutex_t *forks, unsigned int nbr_of_forks);

#endif