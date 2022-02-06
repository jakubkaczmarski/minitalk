/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:28:55 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/06 16:20:52 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	catch_bytes(int byte)
{
	static int	counter;
	static char	str;

	if (counter < 8)
	{
		str += (byte << counter);
		counter++;
	}
	if (counter == 8)
	{
		if (str == '\0')
		{
			ft_printf("\n");
			counter = 0;
			str = 0;
		}
		else
		{
			ft_printf("%c", str);
			counter = 0;
			str = 0;
		}
	}
}

void	handle_sig(int code)
{
	if (code == SIGUSR1)
		catch_bytes(1);
	if (code == SIGUSR2)
		catch_bytes(0);
}

void	start_server(void)
{
	ft_printf("Server pid is : %d \n", getpid());
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	while (1)
	{
		pause();
	}
}

int	main(void)
{
	start_server();
}
