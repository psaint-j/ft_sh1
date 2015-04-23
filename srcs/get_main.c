/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 15:15:20 by psaint-j          #+#    #+#             */
/*   Updated: 2015/04/14 15:25:17 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_main(char *command, char **args, char **g_env, int size)
{
	char	*args_n;

	args_n = NULL;
	if (args[0])
	{
		command = get_command(args[0], g_env);
		if ((ft_strncmp(args[0], "env", 3)) == 0)
			print_myenv(g_env);
		if_setenv(args, args_n, g_env);
		if_printenv(args, g_env);
		if ((ft_strncmp(args[0], "unsetenv", 8)) == 0)
			del_unsetenv(args[1], g_env);
		get_cd(args, g_env);
		if ((get_builtin(args[0])) != 1)
			get_exec(args, command, g_env);
		if (args && command)
		{
			free(args);
			free(command);
		}
	}
}

void		if_setenv(char **args, char *args_n, char **g_env)
{
	if ((ft_strncmp(args[0], "setenv", 6)) == 0)
	{
		if (args[1] && args[2])
			modif_setenv(args[1], args[2], g_env);
		if (args[1] && args[2] == NULL)
			modif_setenv(args[1], args_n, g_env);
	}
}

void		if_printenv(char **args, char **env)
{
	char	*value;

	if ((ft_strncmp(args[0], "printenv", 8)) == 0)
	{
		if (args[1])
		{
			value = get_env(env, args[1]);
			if (value != NULL)
				ft_putendl(value);
			return ;
		}
		print_myenv(env);
	}
}
