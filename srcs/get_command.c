/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 20:24:04 by psaint-j          #+#    #+#             */
/*   Updated: 2015/04/03 18:10:31 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_command(char *arg, char **env)
{
	char			**path;
	char			*command;
	DIR				*dir;
	struct dirent	*dent;
	int				i;

	i = 0;
	path = ft_strsplit(get_env(env, "PATH"), ':');
	command = NULL;
	while (i < 5)
	{
		dir = opendir(path[i]);
		while ((dent = readdir(dir)) != NULL)
		{
			if ((ft_strcmp(dent->d_name, arg)) == 0)
			{
				arg = ft_strjoin("/", arg);
				command = ft_strjoin(path[i], arg);
				return (command);
			}
		}
		i++;
	}
	command = get_command_path(arg, env);
	return (command);
}

char	*get_command_path(char *arg, char **env)
{
	int ret;
	
	ret = 0;
	if (strncmp(arg, "/", 1) == 0)
		ret = 1;
	if (strncmp(arg, "./", 2) == 0)
		ret = 1;
	if (ret == 1)
	{
		if (access(arg, F_OK) != 0)
		{
			ft_putstr("cd:cd:13: no such file or directory: ");
			ft_putendl(arg);
			arg = NULL;
			return (arg);
		}
		return (arg);
	}
	arg = NULL;
	return (arg);
}
