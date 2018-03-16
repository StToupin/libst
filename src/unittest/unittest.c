/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unittest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <stoupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 08:25:38 by stoupin           #+#    #+#             */
/*   Updated: 2018/01/19 09:47:43 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "buffer/buffer.h"
#include "unittest.h"

void	unittest_init(t_unittest_env *env,
						t_buffer_fd *stdout,
						t_buffer_fd *stderr)
{
	env->err = 0;
	env->stdout = stdout;
	env->stderr = stderr;
	env->clean_f = NULL;
	env->clean_f_arg = NULL;
}

void	unittest_set_clean(t_unittest_env *env,
							void (*clean_f)(void*),
							void *clean_f_arg)
{
	env->clean_f = clean_f;
	env->clean_f_arg = clean_f_arg;	
}

void	unittest_print(t_unittest_env *env, char *msg)
{
	buffer_fd_printf(env->stdout, msg);
}

void	unittest_clean(t_unittest_env *env)
{
	if (env->clean_f)
		env->clean_f(env->clean_f_arg);
}

void	unittest_exit(t_unittest_env *env, int code)
{
	unittest_clean(env);
	exit(code);
}
