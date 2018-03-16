/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <stoupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 08:51:50 by stoupin           #+#    #+#             */
/*   Updated: 2018/01/19 10:00:01 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H
# include <stdlib.h>

# define BUFF_SIZE	(1024)

/*
** buffer
*/

typedef struct	s_buffer
{
	char	data[BUFF_SIZE];
	size_t	len;
	size_t	pos;
	size_t	total;
	int		(*fill_buffer)(char *, void *);
	int		(*flush_buffer)(char *, void *);
	void	*f_arg;
}				t_buffer;

void			buffer_init(t_buffer *b,
						int (*fill_buffer)(char *, void *),
						int (*flush_buffer)(char *, void *),
						void *f_arg);
int				buffer_read_char(t_buffer *b, char *c);
int				buffer_write_char(t_buffer *b, char c);
int				buffer_flush(t_buffer *b);
void			buffer_printf(t_buffer *b,	const char *format, ...);

/*
** buffer_fd
*/

typedef struct	s_buffer_fd
{
	int			fd;
	t_buffer	buffer;
}				t_buffer_fd;

int				buffer_fd_fill_f(char *data, t_buffer_fd *b);
int				buffer_fd_flush_f(char *data, t_buffer_fd *b);
void			buffer_fd_init(t_buffer_fd *b, int fd);
int				buffer_fd_read_char(t_buffer_fd *b, char *c);
int				buffer_fd_write_char(t_buffer_fd *b, char c);
int				buffer_fd_flush(t_buffer_fd *b);
void			buffer_fd_printf(t_buffer_fd *b, const char *format, ...);

#endif
