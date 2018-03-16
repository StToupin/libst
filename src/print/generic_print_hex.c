/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_print_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <stoupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 08:26:39 by stoupin           #+#    #+#             */
/*   Updated: 2018/01/19 08:26:40 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	generic_print_hex(void *env,
							void (*f)(void*, char),
							long long int n)
{
	static const char	*digits = "0123456789abcdef";
	char				c;

	if (n <= -16 || n >= 16)
		generic_print_hex(env, f, n / 16);
	if (n >= 0)
		c = digits[n % 16];
	else
		c = digits[-n % 16];
	f(env, c);
}
