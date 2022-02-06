/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:28:46 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/06 16:21:55 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_str(int pid, char *str)
{
	char		*msg;
	static int	i;
	static int	byte;

	msg = str;
	while (msg[i])
	{
		while (byte < 8)
		{
			if ((msg[i] & 1) == 1)
			{
				kill(pid, SIGUSR1);
				usleep(70);
			}
			if ((msg[i] & 1) == 0)
			{
				kill(pid, SIGUSR2);
				usleep(70);
			}
			msg[i] = msg[i] >> 1;
			byte++;
		}
		byte = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("Wrong arguments try again\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (kill((pid), 0) == -1)
	{
		ft_printf("Wrong pid\n");
		return (0);
	}
	str = argv[2];
	send_str(pid, str);
	return (0);
}
