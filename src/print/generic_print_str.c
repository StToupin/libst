/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_print_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <stoupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 08:26:32 by stoupin           #+#    #+#             */
/*   Updated: 2018/01/19 08:26:33 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	generic_print_str(void *env,
							void (*f)(void*, char),
							char *str)
{
	if (str)
	{
		while (*str)
			f(env, *str++);
	}
	else
		generic_print_str(env, f, "(null)");
}
