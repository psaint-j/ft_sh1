/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 02:19:51 by psaint-j          #+#    #+#             */
/*   Updated: 2015/04/10 11:00:38 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		get_builtin(char *arg)
{
	int		ret_builtin;

	ret_builtin = 0;
	if ((ft_strcmp(arg, "cd")) == 0)
		ret_builtin = 1;
	if ((ft_strcmp(arg, "env")) == 0)
		ret_builtin = 1;
	if ((ft_strcmp(arg, "setenv")) == 0)
		ret_builtin = 1;
	if ((ft_strcmp(arg, "unsetenv")) == 0)
		ret_builtin = 1;
	if ((ft_strcmp(arg, "printenv")) == 0)
		ret_builtin = 1;
	if ((ft_strcmp(arg, "exit")) == 0)
		ret_builtin = 2;
	if ((ft_strncmp(arg, "/", 1)) == 0)
		ret_builtin = 2;
	if ((ft_strncmp(arg, "./", 2)) == 0)
		ret_builtin = 2;
	return (ret_builtin);
}
