#include "push_swap.h"

static int	check_number(char *str);
static int	check_overflow(char *str);
static int	check_len_sign(char *str);
static char	f(unsigned int i, char c);

// validate length
// validate only digits
// validate int range
// returns 1 if it is a number, 0 otherwise
int	is_num(char *str)
{
	if (!check_len_sign(str))
		return (0);
	if (!check_number(str))
		return (0);
	if (!check_overflow(str))
		return (0);
	return (1);
}

static int	check_number(char *str)
{
	char	*ctrl;
	char	*tmp;

	if (!str || *str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	ctrl = ft_strmapi(str, f);
	if (!ctrl || *ctrl == '\0')
		return (0);
	tmp = ft_strchr(ctrl, '0');
	if (!tmp || *tmp == '\0')
		return (free(ctrl), 1);
	else
		return (free(ctrl), 0);
}

static int	check_overflow(char *str)
{
	int	err;

	atoi_checked(str, &err);
	if (err == ATOI_ERRNO)
		return (0);
	return (1);
}

static char	f(unsigned int i, char c)
{
	(void)i;
	if (ft_isdigit(c))
		return ('1');
	return ('0');
}

static int	check_len_sign(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 10)
	{
		if (len > 11 && (str[0] == '-' || str[0] == '+'))
			return (0);
		else
			return (1);
	}
	return (1);
}
