/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:34:33 by gmastroc          #+#    #+#             */
/*   Updated: 2024/04/07 17:47:11 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_format(char c, va_list list)
{
	int	count;

	count = 0;
	if (c == '%')
		count = ft_putchar_fd('%', 1);
	else if (c == 'c')
		count = ft_putchar_fd(va_arg(list, int), 1);
	else if (c == 'i' || c == 'd')
		count = ft_putnbr_fd(va_arg(list, int), 1);
	else if (c == 's')
		count = ft_putstr_fd(va_arg(list, char *), 1);
	else if (c == 'u')
		count = ft_putnbr_base(va_arg(list, unsigned int), BASE10);
	else if (c == 'p')
		count = ft_putptr(va_arg(list, uintptr_t));
	else if (c == 'x')
		count = ft_putnbr_base(va_arg(list, unsigned int), BASE16);
	else if (c == 'X')
		count = ft_putnbr_base(va_arg(list, unsigned int), BASE16UPPER);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		result;
	int		i;
	va_list	arg_list;

	va_start(arg_list, format);
	i = 0;
	result = 0;
	while (format[i])
	{
		if (format[i] == '%')
			result = result + check_format(format[++i], arg_list);
		else
			result = result + write(1, &format[i], 1);
		i++;
	}
	va_end(arg_list);
	return (result);
}
