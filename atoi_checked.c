#include "push_swap.h"

int			atoi_checked(const char *str, int *errno);
static int	ft_isspace(int c);

int	atoi_checked(const char *str, int *errno)
{
	int	segno;
	int	numero;

	segno = 1;
	numero = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			segno = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		numero = numero * 10 + (*str - '0');
		if (numero < 0 && numero != INT_MIN)
		{
			*errno = ATOI_ERRNO;
			return (0);
		}
		str++;
	}
	*errno = 0;
	return (numero * segno);
}

static int	ft_isspace(int c)
{
	if ((c >= 0x09 && c <= 0x0D) || c == 0x20)
		return (c);
	return (0);
}
