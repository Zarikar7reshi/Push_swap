/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_checked.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:28:03 by sabruma           #+#    #+#             */
/*   Updated: 2025/05/05 10:58:03 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (numero < 0 && numero != INT_MIN)
		{
			*errno = ATOI_ERRNO;
			return (0);
		}
		numero = numero * 10 + (*str - '0');
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
