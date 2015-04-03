/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 02:19:51 by psaint-j          #+#    #+#             */
/*   Updated: 2015/04/03 17:05:30 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		get_builtin(char *arg)
{
	int		ret_builtin;

	ret_builtin = 0;
	if ((ft_strncmp(arg, "cd", ft_strlen(arg))) == 0)
		ret_builtin = 1;
	if ((ft_strncmp(arg, "env", ft_strlen(arg))) == 0)
		ret_builtin = 1;
	if ((ft_strncmp(arg, "setenv", ft_strlen(arg))) == 0)
		ret_builtin = 1;
	if ((ft_strncmp(arg, "unsetenv", ft_strlen(arg))) == 0)
		ret_builtin = 1;
	return (ret_builtin);
}
