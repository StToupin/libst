/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <stoupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 08:26:53 by stoupin           #+#    #+#             */
/*   Updated: 2018/01/19 08:26:54 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "print/print.h"

static void	print_char(t_string_writer *s, char c)
{
	s->buffer[s->pos++] = c;
}

char		*ft_asprintf(const char *format, ...)
{
	va_list			ap;
	size_t			len;
	t_string_writer	str_writer;

	va_start(ap, format);
	len = vprintf_len(format, &ap);
	str_writer.pos = 0;
	str_writer.buffer = (char*)malloc(sizeof(char) * (len + 1));
	if (str_writer.buffer == NULL)
		return (NULL);
	va_end(ap);
	va_start(ap, format);
	generic_vprintf((void*)&str_writer,
					(void (*)(void *, char))&print_char,
					format,
					&ap);
	va_end(ap);
	return (str_writer.buffer);
}
