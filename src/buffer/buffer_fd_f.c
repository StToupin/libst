/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_fd_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <stoupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 09:36:25 by stoupin           #+#    #+#             */
/*   Updated: 2018/01/19 09:40:58 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "buffer.h"

int	buffer_fd_fill_f(char *data, t_buffer_fd *b)
{
	return (read(b->fd, data, BUFF_SIZE));
}

int	buffer_fd_flush_f(char *data, t_buffer_fd *b)
{
	return (write(b->fd, data, b->buffer.len));
}