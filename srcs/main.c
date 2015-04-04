/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 14:44:53 by psaint-j          #+#    #+#             */
/*   Updated: 2015/04/04 17:06:12 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>

static char	*g_login;
char **g_env;

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
	g_env = malloc(sizeof(char *) * 2000);
	copy_tab(env, g_env);
	while (42)
	{
		g_login = get_user(g_env);
		check_sign();
		get_prompt(g_login);
		args = get_params();
		if (args[0])
		{
			command = get_command(args[0], g_env);
			if ((ft_strncmp(args[0], "env", 3)) == 0)
				print_myenv(g_env);
			if ((ft_strncmp(args[0], "setenv", 6)) == 0)
				modif_setenv(args[1], args[2], g_env);
			if ((ft_strncmp(args[0], "unsetenv", 8)) == 0)
				del_unsetenv(args[1], g_env);
			get_printenv(args, g_env, size);
			get_cd(args, g_env);
			if ((ft_strncmp(args[0], "cd", 2)) != 0)
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
