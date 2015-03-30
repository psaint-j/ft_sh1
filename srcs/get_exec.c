/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 17:24:04 by psaint-j          #+#    #+#             */
/*   Updated: 2015/03/30 23:12:57 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_exec(char **args, char *command)
{
	if ((ft_strncmp(args[0], "exit", 4)) == 0)
		exit (0);
	if ((ft_strncmp(args[0], "exit", 4)) != 0 && command != NULL)
	{
		int			father;
		pid_t		fork();

		father = fork();
		if (father > 0)
			wait(NULL);
		if (father == 0)
		{
			execve(command, args++,NULL);
			exit(0);
		}
	}
	else
	{
		ft_putstr("minishell: command not found: ");
		ft_putendl(args[0]);
	}
}
