/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 23:05:20 by psaint-j          #+#    #+#             */
/*   Updated: 2015/05/11 16:04:33 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_strlen_path(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c == '=')
			return (i);
		i++;
	}
	return (i);
}

int			get_line_path(char *name, char **env)
{
	int		i;
	char	**tab;

	tab = env;
	i = 0;
	while (tab[i])
	{
		if ((strncmp(name, tab[i], ft_strlen_path(tab[i]))) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void		modif_setenv(char *name, char *value, char **env)
{
	int		i;
	char	*str;

	i = get_line_path(name, env);
	str = ft_strjoin(name, "=");
	if (name && value)
		str = ft_strjoin(str, value);
	if (i != -1)
	{
		env[i] = ft_strdup(str);
		return ;
	}
	add_setenv(name, value, env, i);
}

void		add_setenv(char *name, char *value, char **env, int check)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strjoin(name, "=");
	if (name && value)
		str = ft_strjoin(str, value);
	if (check == -1)
	{
		while (env[i])
			i++;
		env[i] = ft_strdup(str);
	}
	i++;
	env[i] = NULL;
}

void		del_unsetenv(char *name, char **env)
{
	char	**tab;
	int		len;
	int		i;
	int		j;

	if (name)
	{
		len = get_line_path(name, env);
		i = 0;
		if (len != -1)
		{
			tab = env;
			while (tab[i] != tab[len])
				i++;
			env[i] = ft_strdup("NOTHING");
		}
	}
}
