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
	pthread_mutex_t	*head_meals_mtx;
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
	pthread_t	ph;
	uint16_t	id;
	t_time		time;
	uint16_t	nbr_of_philos;
	int			meal;
	int			nbr_of_meals;
	t_mtx		mtx;
}	t_philo;

/*	src/debug.c	*/
void			print_data(t_philo *philos);

/*	src/launch.c	*/
int				launch(t_philo *philos);
time_t			get_current_time(void);
time_t			calculate_time(time_t start_time);

/*	src/start.c	*/
void			*start(void *arg);
void			update_last_eat_time(t_philo *philo);
void			increase_meal_counter(t_philo *philo);
void			secure_print(char *msg, t_philo *philo);

/*	src/init.c	*/
int				philos_init(t_philo **philos, char *argv[]);
pthread_mutex_t	*get_forks_mtx(uint16_t nbr);
pthread_mutex_t	*get_mtx(void);

/*	src/mtx.c	*/
int				mtx_init(t_philo **philos, uint16_t nbr);
pthread_mutex_t	*get_forks_mtx(uint16_t nbr);
pthread_mutex_t	*get_mtx(void);
void			initialize_mtx(pthread_mutex_t *mtx, uint16_t nbr);

/*	src/forks_meals.c	*/
int				forks_meals_mtx_init(t_philo **philos,
					pthread_mutex_t *forks_mtx);
void			print_mtx_init(t_philo **philos, pthread_mutex_t *print_mtx);
void			time_mtx_init(t_philo **philos, pthread_mutex_t *time_mtx);

/*	src/monitor.c	*/
void			monitor(t_philo *philos);
bool			philo_eats_all_meals(t_philo *philo);
bool			philo_is_dead(t_philo *philo);

/*	src/acquire_release.c	*/
void			acquire(pthread_mutex_t *mtx);
void			release(pthread_mutex_t *mtx);
void			acquire_forks(t_philo *philo);
void			release_forks(t_philo *philo);

/*	src/destroy.c	*/
void			destroy_mutexes(t_philo *philos);

/*	src/error.c	*/
void			usage_err(void);
void			invalid_arg(char *arg, char *expected_arg);

/*	src/check.c	*/
int				check_arguments(char *argv[]);

/*	src/clear.c	*/
void			clear(t_philo **data);
void			clear_forks_mtx(pthread_mutex_t *forks_mtx, uint16_t nbr);
void			clear_mtx(pthread_mutex_t *mtx);

/*	utils/ctype.c	*/
bool			is_digit(char c);

/*	utils/ft_atoi.c	*/
unsigned long	my_atoi(char *str);

/*	utils/ft_calloc.c	*/
void			*my_calloc(size_t count, size_t size);

/*	utils/my_usleep.c	*/
void			my_usleep(time_t time_to_sleep);

#endif