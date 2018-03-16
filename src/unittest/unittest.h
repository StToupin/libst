/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unittest.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <stoupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 08:25:34 by stoupin           #+#    #+#             */
/*   Updated: 2018/01/19 09:46:54 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNITTEST_H
# define UNITTEST_H

# include "buffer/buffer.h"

typedef struct	s_unittest_env
{
	t_buffer_fd	*stdout;
	t_buffer_fd	*stderr;
	int			err;
	void		(*clean_f)(void*);
	void		*clean_f_arg;
}				t_unittest_env;

/*
** from unittest.c
*/

void	unittest_init(t_unittest_env *env,
						t_buffer_fd *stdout,
						t_buffer_fd *stderr);
void	unittest_set_clean(t_unittest_env *env,
							void (*clean_f)(void*),
							void *clean_f_arg);
void	unittest_print(t_unittest_env *env, char *msg);
void	unittest_clean(t_unittest_env *env);
void	unittest_exit(t_unittest_env *env, int code);

/*
** from unittest_assert.c
*/

void	unittest_assert_ok(t_unittest_env *env);
void	unittest_assert_failed(t_unittest_env *env, char *err_msg);
void	unittest_assert_true(t_unittest_env *env, int true, char *err_msg);
void	unittest_assert_equal_int(t_unittest_env *env, int a, int b,
															char *err_msg);
void	unittest_assert_equal_str(t_unittest_env *env, char *a, char *b,
															char *err_msg);

#endif
