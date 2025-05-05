/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_checked.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:28:03 by sabruma           #+#    #+#             */
/*   Updated: 2025/05/05 11:06:39 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			atoi_checked(const char *str, int *errno);
static int	ft_isspace(int c);
static int	check_overflow(int result, int digit, int sign, int *errno);

int	atoi_checked(const char *str, int *errno)
{
	int	segno;
	int	numero;

	segno = 1;
	numero = 0;
	*errno = 0;

	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			segno = -1;
	while (ft_isdigit(*str))
	{
		if (check_overflow(numero, *str - '0', segno, errno))
			return (0);
		numero = numero * 10 + (*str - '0');
		str++;
	}
	return (numero * segno);
}

static int	check_overflow(int result, int digit, int sign, int *errno)
{
	if (sign == 1 && result > (INT_MAX - digit) / 10)
		*errno = ATOI_ERRNO;
	else if (sign == -1 && result > (-(INT_MIN + digit)) / 10)
		*errno = ATOI_ERRNO;
	else
		return 0;
	return 1;
}

static int	ft_isspace(int c)
{
	if ((c >= 0x09 && c <= 0x0D) || c == 0x20)
		return (c);
	return (0);
}
