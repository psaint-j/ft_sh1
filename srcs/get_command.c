/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 20:24:04 by psaint-j          #+#    #+#             */
/*   Updated: 2015/03/30 23:06:30 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_command(char *arg, char **env)
{
	char			**path;
	char			*line;
	char			*command;
	DIR				*dir;
	struct dirent	*dent;
	int				i;

	i = 0;
	line = get_env(env, "PATH");
	path = ft_strsplit(line, ':');
	//print_myenv(path);
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
	return (command);
}
