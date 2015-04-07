/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 16:11:37 by psaint-j          #+#    #+#             */
/*   Updated: 2015/04/04 17:30:55 by psaint-j         ###   ########.fr       */
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
			args_return = ft_strdup(args[1]);
			return(args_return);
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

void	get_printenv(char **args, char **env, int size)
{
	if ((ft_strncmp(args[0], "printenv", 8)) == 0)
	{
		if (args[1])
		{
			char	*to_return;
			char	*get_env_return;

			get_env_return = NULL;
			get_env_return = get_env(env, args[1]);
			if (get_env_return != NULL)
				to_return = ft_strdup(get_env_return);
			ft_putendl(to_return);
			free(to_return);
		}
		if (args[0] && args[1] == NULL)
			print_myenv(env);
	}
}
