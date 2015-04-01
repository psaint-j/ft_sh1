/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 23:05:20 by psaint-j          #+#    #+#             */
/*   Updated: 2015/04/01 23:54:11 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

int			get_line_path(char *name, char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if ((strncmp(name, env[i], ft_strlen(name))) == 0)
			return (i);
		i++;
	}
}

void		get_setenv(char *name, char **env)
{
	int		i;

	i = get_line_path(name, env);
	
}
