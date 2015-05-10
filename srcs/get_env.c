/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 16:11:37 by psaint-j          #+#    #+#             */
/*   Updated: 2015/05/10 05:36:19 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_myenv(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strcmp(env[i], "NOTHING") != 0)
			ft_putendl(env[i]);
		i++;
	}
}

char	*get_env(char **env, char *path)
{
	char	**tab;
	char	**args;
	char	*args_return;
	int		i;

	i = 0;
	tab = env;
	args_return = NULL;
	while (tab[i])
	{
		args = ft_strsplit(tab[i], '=');
		if ((ft_strcmp(args[0], path)) == 0)
		{
			args_return = NULL;
			if (args[1])
				args_return = ft_strdup(args[1]);
			return (args_return);
		}
		i++;
	}
	return (args_return);
}

void	copy_tab(char **src, char **dst)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		i++;
	}
	dst[i] = NULL;
}

void	init_env_i(char **env)
{
	modif_setenv("ITERM_PROFILE", "Default", env);
	modif_setenv("COLORFGB","7;0", env);
	modif_setenv("USER", "$", env);
	modif_setenv("PATH", "/nfs/zfs-student-4/users/2014/psaint-j/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/usr/texbin", env);
	modif_setenv("TERM","xterm-256color", env);
}
