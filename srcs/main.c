/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 14:44:53 by psaint-j          #+#    #+#             */
/*   Updated: 2015/03/30 22:14:01 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>

static char	*g_login;

void	signhandler(int signum)
{
	(void)signum;
	ft_putstr("\n");
	get_prompt(g_login);
}

void	check_sign(void)
{
	signal(SIGINT, signhandler);
}

int		main(int ac, char **av, char **env)
{
	char		**args;
	char		*command;
	int			size;

	size = ft_countab(env);
	while (42)
	{
		g_login = get_user(env);
		check_sign();
		//		ft_putstr("$ >");
		get_prompt(g_login);
		args = get_params();
		if (args[0])
		{
			//			command = ft_strjoin("/bin/", args[0]);
			command = get_command(args[0], env);
			if ((ft_strncmp(args[0], "env", 3)) == 0)
				print_myenv(env);
			get_printenv(args, env, size);
			get_cd(args, env);
			get_exec(args, command);
			if (args && command)
			{
				free(args);
				free(command);
			}
		}
	}
	//	(void)ac;
	//	(void)av;
	return (0);
}
