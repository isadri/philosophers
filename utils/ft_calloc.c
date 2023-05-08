#include <philosophers.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		exit(ALLOC_ERR);
	memset(ptr, 0, count * size);
	return (ptr);
}
