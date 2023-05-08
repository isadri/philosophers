#include <philosophers.h>

void	exit_usg_err(void)
{
	printf(USG_ERR_MSG " number_of_philosophers time_to_die time_to_eat "
		"time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	exit(USG_ERR);
}

void	invalid_arg(char *arg, char *expected_arg)
{
	printf(INVALID_ARG_MSG " '%s' for %s\n", arg, expected_arg);
}

void	exit_func_call_err(char *func_name, int err)
{
	printf("%s: %s\n", func_name, strerror(err));
	exit(EXIT_FAILURE);
}
