/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 15:43:05 by psaint-j          #+#    #+#             */
/*   Updated: 2015/04/03 05:46:01 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

void		get_pwd(int ret_dir, char *path, char **env)
{
	char	buf[1024];

	if (ret_dir == 0)
	{
		getcwd(buf, sizeof(buf));
		modif_setenv("PWD", buf, env);
	}
}
void		get_old_pwd(char *old_path, char **env)
{
	char	buf[1024];
	
	getcwd(buf, sizeof(buf));
	modif_setenv("OLDPWD", buf, env);
	old_path = ft_strdup(buf);
}

void		get_cd(char **args, char **env)
{
	int		ret_dir;
	char	*path;
	char	*old_path;
	path = get_env(env, "HOME");

	if ((ft_strncmp(args[0], "cd", 2)) == 0 && args[1] != NULL)
	{
		if (args[1][0] == '~')
		{
			path = ft_strjoin(path, args[1] + 1);
			check_cd(path);
			get_old_pwd(old_path, env);
			ret_dir = chdir(path);
			get_pwd(ret_dir, path, env);
			return ;
		}
		if (args[1][0] == '-')
		{
			path = ft_strjoin(get_env(env, "OLDPWD"), args[1] + 1);
			check_cd(path);
			get_old_pwd(old_path, env);
			ret_dir = chdir(path);
			get_pwd(ret_dir, path, env);
			return ;
		}
		check_cd(args[1]);
		get_old_pwd(old_path, env);
		ret_dir = chdir(args[1]);
		get_pwd(ret_dir, path, env);
		return ;
	}
	else if((ft_strncmp(args[0], "cd", 2)) == 0 && args[1] == NULL)
	{
		check_cd(path);
		get_old_pwd(old_path, env);
		ret_dir = chdir(path);
		get_pwd(ret_dir, path, env);
		return ;
	}
}
