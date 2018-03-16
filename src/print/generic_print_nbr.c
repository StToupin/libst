/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_print_nbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <stoupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 08:26:36 by stoupin           #+#    #+#             */
/*   Updated: 2018/01/19 08:26:36 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	generic_print_nbr_recur(void *env,
									void (*f)(void*, char),
									long long int n)
{
	char c;

	if (n <= -10 || n >= 10)
		generic_print_nbr_recur(env, f, n / 10);
	if (n >= 0)
		c = '0' + (n % 10);
	else
		c = '0' - (n % 10);
	f(env, c);
}

void	generic_print_nbr(void *env,
							void (*f)(void*, char),
							long long int n)
{
	if (n < 0)
		f(env, '-');
	generic_print_nbr_recur(env, f, n);
}
