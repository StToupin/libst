/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <stoupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 09:27:36 by stoupin           #+#    #+#             */
/*   Updated: 2018/01/19 10:00:21 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "print/print.h"
#include "buffer.h"

void		buffer_fd_init(t_buffer_fd *b, int fd)
{
	b->fd = fd;
	buffer_init(&b->buffer,
				(int (*)(char *, void *))&buffer_fd_fill_f,
				(int (*)(char *, void *))&buffer_fd_flush_f,
				b);
}

int			buffer_fd_read_char(t_buffer_fd *b, char *c)
{
	return (buffer_read_char(&b->buffer, c));
}

int			buffer_fd_write_char(t_buffer_fd *b, char c)
{
	return (buffer_write_char(&b->buffer, c));
}

int			buffer_fd_flush(t_buffer_fd *b)
{
	return (buffer_flush(&b->buffer));
}

void		buffer_fd_printf(t_buffer_fd *b, const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	generic_vprintf(&b->buffer, (void (*)(void *, char))&buffer_write_char,
					format, &ap);
	va_end(ap);
}
