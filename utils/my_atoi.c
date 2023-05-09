#include <philosophers.h>

static bool				ft_isblank(char c);
static unsigned short	getsign(char c);

unsigned long	my_atoi(char *str)
{
	unsigned long	val;
	unsigned short	sign;

	while (*str && ft_isblank(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		sign = getsign(*str++);
	val = 0;
	while (*str && is_digit(*str))
		val = val * 10 + (*str++ - '0');
	return (val * sign);
}

static bool	ft_isblank(char c)
{
	return (c == ' ' || c == '\t');
}

static unsigned short	getsign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}
