#include <philosophers.h>

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc < 5)
		exit_usg_err();
	if (check_arguments(argv) == EOF)
		exit(INVALID_ARGS);
	data_init(&data, argv);
	if (data->max_eat == 0)
		exit(EXIT_SUCCESS);
	launch(data);
	//print_data(data);
	clear(&data);
	exit(EXIT_SUCCESS);
}
