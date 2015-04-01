/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 15:43:05 by psaint-j          #+#    #+#             */
/*   Updated: 2015/04/01 20:14:24 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char *g_current_pwd;
static char *g_old_pwd;

void		check_cd(char *path)
{
	struct stat		sb;
	stat(path, &sb);

	if ((sb.st_mode & S_IFMT) == S_IFDIR)
	{
		if (access(path, R_OK) == -1)
		{
			ft_putstr("cd:cd:13: permission denied: ");
			ft_putendl(path);
			return ;
		}
	}
	else
	{
		if ((sb.st_mode & S_IFMT) != S_IFDIR && access(path, F_OK) == 0)
		{
			ft_putstr("cd:cd:13: not a directory: ");
			ft_putendl(path);
			return ;
		}
		ft_putstr("cd:cd:13: no such file or directory: ");
		ft_putendl(path);
	}
}

void		get_pwd(int ret_dir, char *path)
{
	char	*buf;
	char	*pwd;

	if (ret_dir == 0)
	{
		pwd = getcwd(buf, BUFF_SIZE + 1);
		ft_putendl(pwd);
	}
}

void		get_cd(char **args, char **env)
{
	int		ret_dir;
	char	*path;
	path = get_env(env, "HOME");

	if ((ft_strncmp(args[0], "cd", 2)) == 0 && args[1] != NULL)
	{
		if (args[1][0] == '~')
		{
			path = ft_strjoin(path, args[1] + 1);
			check_cd(path);
			ret_dir = chdir(path);
			get_pwd(ret_dir, path);
			return ;
		}
		if (args[1][0] == '-')
		{
			path = ft_strjoin(path, args[1] + 1);
			check_cd(path);
			ret_dir = chdir(path);
			get_pwd(ret_dir, path);
			return ;
		}
		check_cd(args[1]);
		ret_dir = chdir(args[1]);
		get_pwd(ret_dir, path);
		return ;
	}
	else if((ft_strncmp(args[0], "cd", 2)) == 0 && args[1] == NULL)
	{
		check_cd(path);
		ret_dir = chdir(path);
		get_pwd(ret_dir, path);
		return ;
	}
}
