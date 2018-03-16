/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vprintf_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <stoupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 08:25:52 by stoupin           #+#    #+#             */
/*   Updated: 2018/01/19 08:25:53 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "print.h"

static void	character_counter(t_basic_counter *counter, char c)
{
	(void)c;
	counter->count++;
}

size_t		vprintf_len(const char *format,
						va_list *ap)
{
	t_basic_counter	counter;

	counter.count = 0;
	generic_vprintf((void *)&counter,
					(void (*)(void *, char))&character_counter,
					format,
					ap);
	return (counter.count);
}
