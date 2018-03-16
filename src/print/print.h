/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <stoupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 08:25:59 by stoupin           #+#    #+#             */
/*   Updated: 2018/01/19 08:25:59 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_basic_counter
{
	size_t	count;
}				t_basic_counter;

typedef struct	s_string_writer
{
	char	*buffer;
	size_t	pos;
}				t_string_writer;

/*
** generic_print_nbr.c
*/

void	generic_print_nbr(void *env,
							void (*f)(void*, char),
							long long int n);

/*
** generic_print_hex.c
*/

void	generic_print_hex(void *env,
							void (*f)(void*, char),
							long long int n);

/*
** generic_print_str.c
*/

void	generic_print_str(void *env,
							void (*f)(void*, char),
							char *str);

/*
** generic_printf.c
*/

void	generic_vprintf(void *env,
						void (*f)(void*, char),
						const char *format,
						va_list *ap);

/*
** vprintf_len.c
*/

size_t		vprintf_len(const char *format,
						va_list *ap);

#endif
