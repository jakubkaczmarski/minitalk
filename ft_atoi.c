/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:28:49 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/06 15:50:51 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isdigit(int ch)
{
	if ((ch >= '0' && ch <= '9'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	counter;
	int	negative;

	negative = 1;
	counter = 0;
	while (str[counter] == ' ' || str[counter] == '\t' || str[counter] == '\n'
		|| str[counter] == '\v' || str[counter] == '\f' || str[counter] == '\r')
		counter++;
	if (str[counter] == '-' || str[counter] == '+')
	{
		if (str[counter] == '-')
			negative = -1;
		counter++;
	}
	res = 0;
	while (str[counter] != '\0' && ft_isdigit(str[counter]))
		res = res * 10 + (str[counter++] - '0');
	return (res * negative);
}
