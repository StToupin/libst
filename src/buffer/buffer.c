/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <stoupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 09:06:11 by stoupin           #+#    #+#             */
/*   Updated: 2018/01/19 09:59:15 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print/print.h"
#include "buffer.h"

void	buffer_init(t_buffer *b,
						int (*fill_buffer)(char *, void *),
						int (*flush_buffer)(char *, void *),
						void *f_arg)
{
	b->len = 0;
	b->pos = 0;
	b->total = 0;
	b->fill_buffer = fill_buffer;
	b->flush_buffer = flush_buffer;
	b->f_arg = f_arg;
}

int			buffer_read_char(t_buffer *b, char *c)
{
	if (b->pos == b->len)
	{
		b->len = (*b->fill_buffer)(b->data, b->f_arg);
		b->pos = 0;
		if (b->len <= 0)
			return (b->len);
	}
	*c = b->data[b->pos++];
	b->total++;
	return (1);
}

int			buffer_write_char(t_buffer *b, char c)
{
	int ret;

	b->data[b->pos++] = c;
	ret = 0;
	if (b->pos == BUFF_SIZE)
	{
		ret = (*b->flush_buffer)(b->data, b->f_arg);
		b->pos = 0;
	}
	b->total++;
	return (ret);
}

int			buffer_flush(t_buffer *b)
{
	int ret;

	b->len = b->pos;
	ret = (*b->flush_buffer)(b->data, b->f_arg);
	b->pos = 0;
	return (ret);
}

void		buffer_printf(t_buffer *b,	const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	generic_vprintf(b, (void (*)(void *, char))&buffer_write_char,
					format, &ap);
	va_end(ap);
}
