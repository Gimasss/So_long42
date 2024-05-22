/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:24:36 by gmastroc          #+#    #+#             */
/*   Updated: 2024/04/07 17:47:11 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(uintptr_t ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count += ft_putstr_fd("(nil)", 1);
	}
	else
	{
		count = count + ft_putstr_fd("0x", 1);
		count = count + ft_putnbr_base(ptr, BASE16);
	}
	return (count);
}
