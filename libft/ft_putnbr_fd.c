/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:29:01 by gmastroc          #+#    #+#             */
/*   Updated: 2024/05/27 13:47:07 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	nl;
	int		res;

	res = 0;
	nl = n;
	if (nl < 0)
	{
		res = 1;
		ft_putchar_fd('-', fd);
		nl = -nl;
	}
	if (nl >= 10)
		res = res + ft_putnbr_fd(nl / 10, fd);
	res = res + ft_putchar_fd(((nl % 10) + '0'), fd);
	return (res);
}

// #include <fcntl.h>

// int main(void)
// {
// 	int fd = open("test.t", O_WRONLY);
// 	ft_putnbr_fd(80084, fd);
// 	close(fd);

// 	ft_putnbr_fd(0, 1);
// }
