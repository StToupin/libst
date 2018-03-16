/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_vprintf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <stoupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 08:26:26 by stoupin           #+#    #+#             */
/*   Updated: 2018/01/19 09:50:57 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "print.h"

static void	print_special(void *env,
							void (*f)(void*, char),
							char type,
							va_list *ap)
{
	if (type == '%')
		f(env, '%');
	else if (type == 's')
		generic_print_str(env, f, (char*)va_arg(*ap, char*));
	else if (type == 'd')
		generic_print_nbr(env, f, (long long int)va_arg(*ap, int));
	else if (type == 'x')
		generic_print_hex(env, f, (long long int)va_arg(*ap, int));
	else if (type == 'c')
		f(env, (char)va_arg(*ap, int));
	else
		f(env, type);
}

void		generic_vprintf(void *env,
							void (*f)(void*, char),
							const char *format,
							va_list *ap)
{
	int		i;
	char	c;

	i = 0;
	while (format[i] != '\0')
	{
		c = format[i++];
		if (c == '%')
		{
			c = format[i++];
			print_special(env, f, c, ap);
		}
		else
			f(env, c);
	}
}
