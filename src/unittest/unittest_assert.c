/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unittest_assert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <stoupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 08:25:48 by stoupin           #+#    #+#             */
/*   Updated: 2018/01/19 09:46:21 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft/ft.h"
#include "buffer/buffer.h"
#include "unittest.h"

void	unittest_assert_ok(t_unittest_env *env)
{
	buffer_fd_write_char(env->stdout, '.');
}

void	unittest_assert_failed(t_unittest_env *env, char *err_msg)
{
	buffer_fd_write_char(env->stdout, 'F');
	if (err_msg != NULL && err_msg[0] != '\0')
		buffer_fd_printf(env->stderr,
						"Unit test failed with the following error: %s\n\n",
						err_msg);
	unittest_exit(env, 1);
}

void	unittest_assert_true(t_unittest_env *env, int true, char *err_msg)
{
	if (true)
		unittest_assert_ok(env);
	else
		unittest_assert_failed(env, err_msg);
}

void	unittest_assert_equal_int(t_unittest_env *env, int a, int b, char *err_msg)
{
	if (a == b)
		unittest_assert_ok(env);
	else
	{
		buffer_fd_printf(env->stderr,
						"The following integers whould be equal: %d and %d\n",
						a, b);
		unittest_assert_failed(env, err_msg);
	}
}

void	unittest_assert_equal_str(t_unittest_env *env, char *a, char *b, char *err_msg)
{
	if (ft_strcmp(a, b) == 0)
		unittest_assert_ok(env);
	else
	{
		buffer_fd_printf(env->stderr,
				"The following strings whould be equal: \"%s\" and \"%s\"\n",
				a, b);
		unittest_assert_failed(env, err_msg);
	}
}
