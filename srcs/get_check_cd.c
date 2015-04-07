/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_check_cd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 19:57:04 by psaint-j          #+#    #+#             */
/*   Updated: 2015/04/07 20:39:13 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_check_cd(char **args, char *path, char *old_path, char **env)
{
	int		ret_dir;

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
