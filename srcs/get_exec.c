/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 17:24:04 by psaint-j          #+#    #+#             */
/*   Updated: 2015/05/07 19:24:52 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		get_exec(char **args, char *command, char **env)
{
	int		father;

	get_exit(args);
	if ((ft_strncmp(args[0], "exit", 4)) != 0 && command != NULL)
	{
		father = fork();
		if (father > 0)
			wait(NULL);
		if (father == 0)
		{
			execve(command, args++, env);
		}
	}
	else
	{
		if ((get_builtin(args[0])) == 0)
		{
			ft_putstr("minishell: command not found: ");
			ft_putendl(args[0]);
		}
	}
}

void		get_exit(char **args)
{
	int		i;

	i = 0;
	if ((ft_strncmp(args[0], "exit", 4)) == 0)
	{
		if (args[1])
		{
			i = ft_atoi(args[1]);
			exit (i);
		}
		exit (i);
	}
}
