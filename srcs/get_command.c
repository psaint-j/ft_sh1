/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 20:24:04 by psaint-j          #+#    #+#             */
/*   Updated: 2015/05/10 03:09:04 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_niquetamere(struct dirent *dent, DIR *dir, char *arg, char *path)
{
	char			*command;

	command = NULL;
	while ((dent = readdir(dir)) != NULL)
	{
		if ((ft_strcmp(dent->d_name, arg)) == 0)
		{
			arg = ft_strjoin("/", arg);
			command = ft_strjoin(path, arg);
			break ;
		}
	}
	return (command);
}

char	*get_command(char *arg, char **env)
{
	char			**path;
	DIR				*dir;
	struct dirent	*dent;
	int				i;
	char			*data[2];

	i = 0;
	data[0] = get_env(env, "PATH");
	data[1] = NULL;
	if (data[0] != NULL && ((path = ft_strsplit(data[0], ':')) || 42))
	{
		while (path[i] && ((dir = opendir(path[i])) || 42))
		{
			if (dir != NULL)
			{
				data[1] = ft_niquetamere(dent, dir, arg, path[i]);
				if (data[1] != NULL)
					break ;
				closedir(dir);
			}
			i++;
		}
	}
	return ((data[1]) ? data[1] : get_command_path(arg, env));
}

char	*get_command_path(char *arg, char **env)
{
	int ret;

	ret = 0;
	if (ft_strncmp(arg, "/", 1) == 0)
		ret = 1;
	if (ft_strncmp(arg, "./", 2) == 0)
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
